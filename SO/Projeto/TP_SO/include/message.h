#ifndef MESSAGE_H
#define MESSAGE_H


#define MSG_COMMAND_SIZE 384
#define MSG_FIFO_SIZE 128

/**
 * @brief Represents a message structure used for communication.
 * 
 * This structure is used to encapsulate information for inter-process
 * communication, including metadata and content details.
 * 
 * @param fifo_name
 *     The name of the FIFO (named pipe) used for communication.
 *     The size of this field is defined by MSG_FIFO_SIZE.
 * 
 * @param action
 *     A character representing the action or command to be performed.
 * 
 * @param id
 *     An integer identifier associated with the message.
 * 
 * @param keyword
 *     A string containing a keyword, with a maximum size of 128 characters.
 * 
 * @param n_proc
 *     An integer representing the number of processes involved.
 * 
 * @param title
 *     A string containing the title, with a maximum size of 201 characters.
 * 
 * @param authors
 *     A string containing the authors, with a maximum size of 201 characters.
 * 
 * @param year
 *     A string representing the year, with a maximum size of 5 characters.
 * 
 * @param path
 *     A string containing the file path, with a maximum size of 65 characters.
 */
typedef struct {
    char fifo_name[MSG_FIFO_SIZE];
    char action;
    int id;
    char keyword[128];
    int n_proc;
    char title[201];
    char authors[201];
    char year[5];
    char path[65];
} Message;

#endif //MESSAGE_H