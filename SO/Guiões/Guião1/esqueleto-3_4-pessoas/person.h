#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h> // chamadas ao sistema: defs e decls essenciais
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT, O_*

typedef struct{
    char name[30];
    int idade;
} Person;

int open(const char *path, int oflag [, mode]);
ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
off_t lseek(int fd, off_t offset, int whence);
int close(int fildes);

void add_person(const char *filename, const char *nome, const int idade);
