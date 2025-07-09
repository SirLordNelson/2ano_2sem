#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdlib.h>
#include <stdio.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t fork(void);
void _exit(int status);
pid_t wait(int *status);
pid_t waitPID(pid_t pid, int *status, int options);
int WIFEXITED(int status); /* macro */
int WEXITSTATUS(int status); /* macro */

//Ex1
int main(int argc, char *argv[]){
    printf("child pid: %d\n", getpid());
    printf("parent pid: %d\n", getppid());

    return 0;
}

//Ex2
int main(int argc, char *argv[]){
    int status;
    int pid;

    if(pid = fork() == 0){
        printf("[child] pid: %d\n", getpid());
        printf("[child] pid: %d\n", getppid());
        _exit(0);
    } else{
        pid_t child = wait(&status);
        printf("[parent] pid: %d\n", getpid());
        printf("[parent] pid: %d\n", getppid());   
    }

    return 0;
}

//Ex3
int main(int argc, char *argv[]){
    int N = 10;
    int pid;

    for(int i = 0; i < N; i++){
        if((pid = fork()) == 0){
            printf("Hello from child %d\n", i);
            _exit(i);
        }
        int status;
        wait(&status);
        if(WIFEXITED(status)) printf("Child %d exited with status %d\n", i, WEXITSTATUS(status));
    }
    return 0;
}

//Ex4
int main(int argc, char *argv[]){
    int N = 10;
    int pid[N];

    for(int i = 0; i < N; i++){
        if((pid[i] = fork()) == 0){
            printf("Hello from child %d\n", i);
            _exit(i);
        }
    }
    for(int i = 0; i < N; i++){
        int status;
        waitPID(pid[i], &status, 0);
        if(WIFEXITED(status)) printf("Child %d exited with status %d\n", i, WEXITSTATUS(status));
    }
    return 0;
}