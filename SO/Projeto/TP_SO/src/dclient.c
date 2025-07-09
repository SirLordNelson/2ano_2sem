#include "../include/message.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SERVER_PIPE "/tmp/doc_pipe"
#define BUFF_SIZE 512

/**
 * @brief Client program for interacting with a server via FIFO pipes.
 *
 * This program allows a client to send various commands to a server using
 * named pipes (FIFOs). The client creates a unique FIFO for receiving
 * responses from the server and sends requests through a predefined server
 * FIFO. The program supports multiple actions such as adding, deleting,
 * consulting, listing, searching, and finalizing operations.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * 
 * Command-line usage:
 *   - `-a <title> <authors> <year> <path>`: Add a new entry.
 *   - `-c <id>`: Consult an entry by ID.
 *   - `-d <id>`: Delete an entry by ID.
 *   - `-l <id> <keyword>`: List entries by ID and keyword.
 *   - `-s <keyword> [n_proc]`: Search entries by keyword, optionally specifying the number of processes.
 *   - `-f`: Finalize the server.
 *
 * The program validates the input arguments and constructs a `Message` structure
 * to send to the server. It then waits for a response from the server and displays
 * the output to the standard output.
 *
 * @return Returns 0 on success, or 1 on invalid command or error.
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        const char* usage = "Usage: ";
        const char* options = " <options>\n";
        write(STDERR_FILENO, usage, strlen(usage));
        write(STDERR_FILENO, argv[0], strlen(argv[0]));
        write(STDERR_FILENO, options, strlen(options));
        exit(EXIT_FAILURE);
    }

    char client_fifo[MSG_FIFO_SIZE];
    snprintf(client_fifo, sizeof(client_fifo), "/tmp/client_%d", getpid());
    mkfifo(client_fifo, 0666);

    Message msg = {0};
    strncpy(msg.fifo_name, client_fifo, MSG_FIFO_SIZE);

    if (strcmp(argv[1], "-a") == 0 && argc == 6) {
        msg.action = 'a';
        strncpy(msg.title, argv[2], 200);
        strncpy(msg.authors, argv[3], 200);
        strncpy(msg.year, argv[4], 4);
        strncpy(msg.path, argv[5], 64);
    } else if (strcmp(argv[1], "-c") == 0 && argc == 3) {
        msg.action = 'c';
        msg.id = atoi(argv[2]);
    } else if (strcmp(argv[1], "-d") == 0 && argc == 3) {
        msg.action = 'd';
        msg.id = atoi(argv[2]);
    } else if (strcmp(argv[1], "-l") == 0 && argc == 4) {
        msg.action = 'l';
        msg.id = atoi(argv[2]);
        strncpy(msg.keyword, argv[3], 127);
    } else if (strcmp(argv[1], "-s") == 0 && (argc == 3 || argc == 4)) {
        msg.action = 's';
        strncpy(msg.keyword, argv[2], 127);
        if (argc == 4) msg.n_proc = atoi(argv[3]);
    } else if (strcmp(argv[1], "-f") == 0) {
        msg.action = 'f';
    } else {
        const char* invalid = "Invalid command\n";
        write(STDERR_FILENO, invalid, strlen(invalid));
        unlink(client_fifo);
        return 1;
    }

    int fifo_w = open(SERVER_PIPE, O_WRONLY);
    write(fifo_w, &msg, sizeof(Message));
    close(fifo_w);

    int fifo_r = open(client_fifo, O_RDONLY);
    char buffer[BUFF_SIZE];
    int n_read;
    while ((n_read = read(fifo_r, buffer, BUFF_SIZE)) > 0) {
        write(1, buffer, n_read);
    }
    close(fifo_r);
    unlink(client_fifo);

    return 0;
}