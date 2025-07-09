#include <unistd.h>

int dup(int fd);
int dup2(int fd1, int fd2);

int main(int argc, char *argv[]){
    if(fork() == 0){
        int fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
        dup2(fd, 1);
        close(fd);
        execlp("ls", "ls", NULL);
        _exit(1);
    }
    wait(NULL);
    return 0;
}