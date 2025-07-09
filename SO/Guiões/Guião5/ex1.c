#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int mkfifo(const char *pathname, mode_t mode);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s <pathname>\n", argv[0]);
        return 1;
    }
    if(mkfifo(argv[1], 0666) < 0){
        perror("mkfifo");
        return 2;
    }
    return 0;
}