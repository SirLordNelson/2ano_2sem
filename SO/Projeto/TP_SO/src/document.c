#include "../include/document.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Document* document_new(int id, const char* title, const char* authors, const char* year, const char* path) {
    Document* doc = malloc(sizeof(Document));
    if (!doc) return NULL;
    doc->id = id;
    strncpy(doc->title, title, 200);
    strncpy(doc->authors, authors, 200);
    strncpy(doc->year, year, 4);
    strncpy(doc->path, path, 64);
    return doc;
}

void document_free(Document* doc) {free(doc);}