#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

//Ex1
int main(int argc, char *argv[]){
    pid_t pid;
    int pipe_fd[2];
    pipe(pipe_fd);
    if((pid = fork()) == 0){
        close(pipe_fd[0]);
        int value = 500;
        write(pipe_fd[1], &value, sizeof(int));
        _exit(1);
    }
    close(pipe_fd[1]);
    int value;
    read(pipe_fd[0], &value, sizeof(int));
    printf("Value: %d\n", value);
    wait(NULL);
    return 0;
}

//Ex2
int main(int argc, char *argv[]){
    pid_t pid;
    int pipe_fd[2];
    pipe(pipe_fd);
    if(fork() == 0){
        close(pipe_fd[1]);
        int value = 0;
        while(read(pipe_fd[0], &value, sizeof(int)) > 0){
            printf("Child: %d\n", value);
        }
        _exit(1);
    }
    close(pipe_fd[0]);
    for(int i = 0; i < 1000; i++){
        write(pipe_fd[1], &i, sizeof(int));
        printf("Parent: %d\n", i);
    }
    close(pipe_fd[1]);
    wait(NULL);
    return 0;
}

/*
é possível que o output seja intercalado

parent: 1
child: 1
child: 2
parent: 2
tmb pode acontecer, mas se antes do "parent: 2" aparecer "child: 3", algo está errado pq ñ devia ser possível
*/