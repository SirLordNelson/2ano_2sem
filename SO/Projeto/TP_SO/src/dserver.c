#include "../include/document.h"
#include "../include/message.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <glib.h>
#include <dirent.h>

#define PIPE_NAME "/tmp/doc_pipe"

/**
 * @brief A static global hash table used to store document-related data.
 * 
 * This hash table is intended to manage and organize documents within the
 * application. The keys and values stored in the table depend on the specific
 * implementation and usage within the program.
 */
static GHashTable* doc_table;

/**
 * @brief A static counter to keep track of the document IDs.
 * 
 * This counter is used to assign unique IDs to documents as they are added
 * to the hash table. It is incremented each time a new document is indexed.
 */
static int doc_id_counter = 1;

/**
 * @brief A static variable to define the maximum cache size for documents.
 * 
 * This variable is used to limit the number of documents that can be cached
 * in the server's memory. It is set based on user input when the server starts.
 */
static int max_cache_size;

/**
 * @brief Sends a termination message to a child process via a named pipe.
 *
 * This function constructs a message of type `Message` with the action set to 'x'
 * and the process ID of the current process. It then opens a named pipe (FIFO) 
 * in write-only mode and writes the message to it. If the pipe is successfully 
 * opened, the message is sent, and the pipe is closed
 */
 void kill_child() {
    Message msg;
    memset(&msg, 0, sizeof(Message));
    msg.action = 'x';
    msg.id = getpid();

    int fifo_fd = open(PIPE_NAME, O_WRONLY);
    if (fifo_fd != -1) {
        write(fifo_fd, &msg, sizeof(Message));
        close(fifo_fd);
    }
}

/**
 * @brief Handles an index request by creating a new document and adding it to the document table.
 *
 * @param msg Pointer to a Message structure containing the document details such as title, authors, year, and path.
 * @param client_fd File descriptor of the client to send the response back to.
 *
 * This function creates a new Document object using the provided details in the Message structure.
 * It inserts the document into a global hash table (`doc_table`) with a unique document ID as the key.
 * The document ID is incremented after each insertion. A confirmation message is sent back to the client
 * indicating the successful indexing of the document.
 */
 void handle_index_request(Message* msg, int client_fd) {
    Document* doc = document_new(doc_id_counter, msg->title, msg->authors, msg->year, msg->path);
    g_hash_table_insert(doc_table, GINT_TO_POINTER(doc_id_counter), doc);
    char response[256];
    int length = snprintf(response, sizeof(response), "Document %d indexed\n", doc_id_counter);
    if(fork () == 0) {
        write(client_fd, response, length);
        kill_child();
        exit(0);
    }
    doc_id_counter++;
}

/**
 * @brief Handles a consult request from a client by retrieving document information.
 *
 * This function looks up a document in the global hash table `doc_table` using the
 * document ID provided in the `msg` parameter. If the document is found, it sends
 * the document's details (title, authors, year, and path) to the client through the
 * specified file descriptor. If the document is not found, it sends an error message
 * to the client.
 *
 * @param msg Pointer to a Message structure containing the document ID to be consulted.
 * @param client_fd File descriptor of the client to which the response will be sent.
 */
 void handle_consult_request(Message* msg, int client_fd) {
    Document* doc = g_hash_table_lookup(doc_table, GINT_TO_POINTER(msg->id));
    if (doc) {
        char buffer[1024];
        int len = snprintf(buffer, sizeof(buffer), "Title: %s\nAuthors: %s\nYear: %s\nPath: %s\n", doc->title, doc->authors, doc->year, doc->path);
        if(fork () == 0) {
            write(client_fd, buffer, len);
            kill_child();
            exit(0);
        }
    } else {
        const char *not_found = "Document not found\n";
        write(client_fd, not_found, strlen(not_found));
    }
}

/**
 * @brief Handles a delete request from a client.
 *
 * This function processes a delete request by attempting to remove an entry
 * from the global document table (`doc_table`) based on the ID provided in
 * the message. If the entry is successfully removed, a success message is
 * sent to the client. Otherwise, an error message indicating that the document
 * was not found is sent.
 *
 * @param msg Pointer to the Message structure containing the request details,
 *            including the ID of the document to be deleted.
 * @param client_fd File descriptor of the client to which the response will
 *                  be sent.
 */
 void handle_delete_request(Message* msg, int client_fd) {
    if (g_hash_table_remove(doc_table, GINT_TO_POINTER(msg->id))) {
        char buffer[64];
        int len = snprintf(buffer, sizeof(buffer), "Index entry %d deleted\n", msg->id);
        if(fork () == 0) {
            write(client_fd, buffer, len);
            kill_child();
            exit(0);
        }
    } else {
        const char* error_msg = "Document not found\n";
        write(client_fd, error_msg, strlen(error_msg));
    }
}

/**
 * @brief Handles a request to count the number of lines in a document containing a specific keyword.
 *
 * This function processes a request to count the occurrences of a keyword in a document.
 * It retrieves the document from a hash table using the provided document ID, and if the
 * document exists, it uses a child process to execute the `grep` command to count the lines
 * containing the keyword. The result is then sent back to the client.
 *
 * @param msg Pointer to the Message structure containing the request details, including
 *            the document ID and the keyword to search for.
 * @param client_fd File descriptor of the client to which the result will be sent.
 */
 void handle_line_count_request(Message* msg, int client_fd) {
    Document* doc = g_hash_table_lookup(doc_table, GINT_TO_POINTER(msg->id));
    if (!doc) {
        const char* error_msg = "Document not found\n";
        write(client_fd, error_msg, strlen(error_msg));
        return;
    }
    int pipefd[2];
    pipe(pipefd);
    
    pid_t pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        execlp("grep", "grep", "-c", msg->keyword, doc->path, NULL);
        const char* exec_error = "Failed to execute grep\n";
        write(STDERR_FILENO, exec_error, strlen(exec_error));
        exit(EXIT_FAILURE);
    }
    else if (pid > 0) {
        close(pipefd[1]);
        char result[64] = {0};
        ssize_t bytes_read = read(pipefd[0], result, sizeof(result) - 1);
        if (bytes_read > 0) {
            if (result[bytes_read - 1] == '\n') {
                result[bytes_read - 1] = '\0';
                bytes_read--;
            }
            write(client_fd, result, bytes_read);
        }
        close(pipefd[0]);
        wait(NULL);
    }
    else {
        const char* fork_error = "Failed to fork\n";
        write(client_fd, fork_error, strlen(fork_error));
    }
}

/**
 * @brief Handles a search request by searching for a keyword in documents and sending the results.
 *
 * This function processes a search request by iterating over a hash table of documents,
 * spawning child processes to perform the search using the `grep` command, and sending
 * the results back to the client through a file descriptor.
 *
 * @param msg Pointer to a Message structure containing the search request details.
 *            - `msg->keyword`: The keyword to search for in the documents.
 *            - `msg->n_proc`: The maximum number of concurrent processes allowed.
 * @param fd File descriptor to which the search results will be written.
 *
 * @details
 * - The function retrieves all document IDs from the `doc_table` hash table.
 * - It limits the number of concurrent processes to `msg->n_proc` (or 1 if `msg->n_proc` is 0).
 * - For each document, it forks a child process to execute the `grep` command to search for the keyword.
 * - If the keyword is found in a document, the document ID is written to a pipe.
 * - After all processes complete, the results are read from the pipe and sent to the client.
 */
 void handle_search_request(Message* msg, int fd) {
    GList* keys = g_hash_table_get_keys(doc_table);
    int max_procs = msg->n_proc > 0 ? msg->n_proc : 1;
    int active_procs = 0;
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        const char* pipe_error = "Failed to create pipe\n";
        write(fd, pipe_error, strlen(pipe_error));
        g_list_free(keys);
        return;
    }

    for (GList* iter = keys; iter != NULL; iter = iter->next) {
        int doc_id = GPOINTER_TO_INT(iter->data);
        Document* doc = g_hash_table_lookup(doc_table, iter->data);

        while (active_procs >= max_procs) {
            wait(NULL);
            active_procs--;
        }

        pid_t pid = fork();
        if (pid == 0) {
            close(pipefd[0]);
            if (fork() == 0) {
                execlp("grep", "grep", "-q", msg->keyword, doc->path, NULL);
                _exit(2);
            }
            int status;
            wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                char id_str[16];
                int len = snprintf(id_str, sizeof(id_str), "%d ", doc_id);
                write(pipefd[1], id_str, len);
            }
            _exit(0);
        } else if (pid > 0) active_procs++;
        else {
            const char* fork_error = "Fork failed\n";
            write(fd, fork_error, strlen(fork_error));
        }
    }

    while (active_procs-- > 0) wait(NULL);
    close(pipefd[1]);

    char buf[4096] = {0};
    ssize_t len = read(pipefd[0], buf, sizeof(buf) - 1);
    if (len > 0) {
        buf[len] = '\0';
        char output[4096 + 3];
        int out_len = snprintf(output, sizeof(output), "[%s]\n", buf);
        write(fd, output, out_len);
    }
    close(pipefd[0]);
    g_list_free(keys);
}

/**
 * @brief Handles a shutdown request for the server.
 *
 * This function is responsible for gracefully shutting down the server.
 * It sends a shutdown message to the client, iterates through the document
 * table, and copies a limited number of documents to a cache directory
 * before exiting the program.
 *
 * @param fd The file descriptor to which the shutdown message is sent.
 *
 * The function performs the following steps:
 * 1. Sends a shutdown message to the client.
 * 2. Retrieves all keys from the document hash table.
 * 3. Iterates through the keys and copies up to `max_cache_size` documents
 *    from their source paths to the "Server_Cache" directory.
 * 4. Closes all open file descriptors and frees allocated memory.
 * 5. Exits the program with a status code of 0.
 */
void handle_shutdown_request(int fd) {
    const char* shutdown_msg = "Server is shutting down\n";
    write(fd, shutdown_msg, strlen(shutdown_msg));

    mkdir("Server_Cache", 0777);

    GList* keys = g_hash_table_get_keys(doc_table);
    GList* iter = keys;
    int copied = 0;

    while (iter && copied < max_cache_size) {
        int id = GPOINTER_TO_INT(iter->data);
        Document* doc = g_hash_table_lookup(doc_table, iter->data);

        if (doc) {
            char src_path[256], dst_path[256];
            strncpy(src_path, doc->path, sizeof(src_path)-1);
            src_path[sizeof(src_path)-1] = '\0';
            
            int len = snprintf(dst_path, sizeof(dst_path), "Server_Cache/%d.txt", doc->id);
            if (len >= sizeof(dst_path)) dst_path[sizeof(dst_path)-1] = '\0';

            int src_fd = open(src_path, O_RDONLY);
            if (src_fd >= 0) {
                int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                if (dst_fd >= 0) {
                    char buffer[1024];
                    ssize_t bytes;
                    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
                        write(dst_fd, buffer, bytes);
                    }
                    close(dst_fd);
                }
                close(src_fd);
                copied++;
            }
        }
        iter = iter->next;
    }
    g_list_free(keys);
    exit(0);
}

/**
 * @brief Loads documents from the "Server_Cache" directory into the document table.
 *
 * This function scans the "Server_Cache" directory for regular files and creates
 * a new Document object for each file found. The documents are then inserted into
 * the global document table (`doc_table`) with a unique document ID. The document
 * ID counter (`doc_id_counter`) is incremented for each document added.
 *
 * If the "Server_Cache" directory cannot be opened, the function returns without
 * performing any operations.
 */
void load_documents_from_cache() {
    DIR* dir = opendir("Server_Cache");
    if (!dir) return;
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char full_path[512];
            snprintf(full_path, sizeof(full_path), "Server_Cache/%s", entry->d_name);
            Document* doc = document_new(doc_id_counter, "(Recovered)", "Unknown", "0000", full_path);
            g_hash_table_insert(doc_table, GINT_TO_POINTER(doc_id_counter), doc);
            doc_id_counter++;
        }
    }
    closedir(dir);
}

/**
 * @brief Processes a client request by forking a child process to handle it.
 *
 * This function creates a child process using `fork()` to handle a client request
 * encapsulated in the `Message` structure. The child process performs the following:
 * - Opens the client's FIFO for writing.
 * - Executes the appropriate action based on the `action` field in the `Message`.
 * - Sends a termination message to a predefined named pipe (PIPE_NAME) upon completion.
 *
 * @param msg Pointer to the `Message` structure containing the client's request.
 *
 * Actions:
 * - 'l': Calls `handle_line_count_request` to process a line count request.
 * - 's': Calls `handle_search_request` to process a search request.
 * - Default: Writes "Unknown action" to the client's FIFO.
 *
 * Upon completion, the child process sends a termination message with action 'x'
 * and its process ID to the named pipe (PIPE_NAME) to signal that it has finished.
 */
void process_request(Message* msg) {
    if (fork() == 0) {
        int client_fd = open(msg->fifo_name, O_WRONLY);
        if (client_fd < 0) exit(EXIT_FAILURE);
        switch (msg->action) {
            case 'l': handle_line_count_request(msg, client_fd); break;
            case 's': handle_search_request(msg, client_fd); break;
            default: {
                const char* unknown_action = "Unknown action\n";
                write(client_fd, unknown_action, strlen(unknown_action));
                break;
            }
        }
        close(client_fd);

        kill_child();
        exit(0);
    }
}

/**
 * @brief Server application for handling document-related requests via a named pipe.
 *
 * This program implements a server that listens for client requests through a named pipe (FIFO).
 * It supports various actions such as indexing, consulting, deleting documents, and shutting down the server.
 * The server maintains a document cache with a maximum size specified at runtime.
 *
 * Usage:
 *   ./dserver <document_folder> <cache_size>
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments. 
 *             argv[1] specifies the document folder.
 *             argv[2] specifies the maximum cache size.
 *
 * @return Returns 0 on successful execution, or exits with an error code on failure.
 *
 * The server performs the following tasks:
 * - Initializes a hash table to manage documents.
 * - Loads documents from the cache.
 * - Creates and opens a named pipe for communication with clients.
 * - Processes client requests in an infinite loop, handling various actions:
 *   - 'a': Index a document.
 *   - 'c': Consult a document.
 *   - 'd': Delete a document.
 *   - 'l': Process a custom request.
 *   - 's': Process another custom request.
 *   - 'f': Shut down the server.
 *   - 'x': Wait for a specific process to terminate.
 * - Cleans up resources (e.g., closes the FIFO and unlinks it) upon termination.
 */
 int main(int argc, char* argv[]) {
    if (argc != 3) {
        const char* usage = "Usage: ";
        const char* args = " <document_folder> <cache_size>\n";
        write(STDERR_FILENO, usage, strlen(usage));
        write(STDERR_FILENO, argv[0], strlen(argv[0]));
        write(STDERR_FILENO, args, strlen(args));
        exit(EXIT_FAILURE);
    }

    max_cache_size = atoi(argv[2]);
    doc_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, 
                                    (GDestroyNotify)document_free);
    load_documents_from_cache();

    if (mkfifo(PIPE_NAME, 0666) == -1 && errno != EEXIST) {
        const char* fifo_error = "Failed to create server pipe\n";
        write(STDERR_FILENO, fifo_error, strlen(fifo_error));
        exit(EXIT_FAILURE);
    }

    int fifo = open(PIPE_NAME, O_RDONLY);
    if (fifo == -1) {
        const char* open_error = "Failed to open server pipe for reading\n";
        write(STDERR_FILENO, open_error, strlen(open_error));
        exit(EXIT_FAILURE);
    }

    int fifo_w = open(PIPE_NAME, O_WRONLY);
    if (fifo_w == -1) {
        const char* write_error = "Failed to open server pipe for writing\n";
        write(STDERR_FILENO, write_error, strlen(write_error));
        close(fifo);
        exit(EXIT_FAILURE);
    }

    while (1) {
        Message msg;
        ssize_t n_read = read(fifo, &msg, sizeof(Message));
        if (n_read > 0) {
            if (msg.action == 'x') waitpid(msg.id, NULL, 0);
            else {
                int client_fd = open(msg.fifo_name, O_WRONLY);
                if (client_fd < 0) {
                    const char* client_error = "Failed to open client pipe\n";
                    write(STDERR_FILENO, client_error, strlen(client_error));
                    continue;
                }
                switch (msg.action) {
                    case 'a': handle_index_request(&msg, client_fd); break;
                    case 'c': handle_consult_request(&msg, client_fd); break;
                    case 'd': handle_delete_request(&msg, client_fd); break;
                    case 'l': process_request(&msg); break;
                    case 's': process_request(&msg); break;
                    case 'f': 
                        handle_shutdown_request(client_fd); 
                        close(fifo);
                        close(fifo_w);
                        unlink(PIPE_NAME);
                        exit(EXIT_SUCCESS);
                        break;
                    default: {
                        const char* unknown_action = "Unknown action\n";
                        write(client_fd, unknown_action, strlen(unknown_action));
                        break;
                    }
                }
                close(client_fd);
            }
        } else if (n_read == -1) {
            const char* read_error = "Error reading from pipe\n";
            write(STDERR_FILENO, read_error, strlen(read_error));
        }
    }
    close(fifo);
    close(fifo_w);
    unlink(PIPE_NAME);
    return EXIT_SUCCESS;
}