#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <glib.h>

/**
 * @brief Represents a document with metadata and file path information.
 * 
 * @param id
 * Unique identifier for the document.
 * 
 * @param title
 * Title of the document. Maximum length is 200 characters.
 * 
 * @param authors
 * Authors of the document. Maximum length is 200 characters.
 * 
 * @param year
 * Year of publication. Stored as a string with a maximum length of 4 characters.
 * 
 * @param path
 * File path to the document. Maximum length is 64 characters.
 */
typedef struct {
    int id;
    char title[201];
    char authors[201];
    char year[5];
    char path[65];
} Document;

/**
 * @brief Creates a new Document instance.
 * 
 * @param id The unique identifier for the document.
 * @param title The title of the document.
 * @param authors The authors of the document, as a string.
 * @param year The publication year of the document, as a string.
 * @param path The file path to the document.
 * @return A pointer to the newly created Document instance.
 */
Document* document_new(int id, const char* title, const char* authors, const char* year, const char* path);

/**
 * @brief Frees the memory allocated for a Document object.
 * 
 * This function releases all resources associated with the given Document
 * object, including any dynamically allocated memory within the structure.
 * After calling this function, the pointer to the Document object should
 * no longer be used.
 * 
 * @param doc Pointer to the Document object to be freed.
 */
void document_free(Document* doc);

#endif //DOCUMENT_H