#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

int dup(int fd);
int dup2(int fd1, int fd2);

//Ex1
int main(int argc, char *argv[]){
    int in_fd = open("etc/passwd", O_RDONLY);
    int out_fd = open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int err_fd = open("erros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    int stdout_original = dup(STDOUT_FILENO); //copia stdout para stdout_original

    dup2(in_fd, STDIN_FILENO); //copia etc/passwd para stdin
    close(in_fd);
    dup2(out_fd, STDOUT_FILENO); //copia saida.txt para stdout
    close(out_fd);
    dup2(err_fd, STDERR_FILENO); //copia erros.txt para stderr
    close(err_fd);

    write(STDOUT_FILENO, "texto\n", 6); //escreve em saida.txt

    //4 simboliza o tamanho do buffer (string + '\0')
    write(stdout_original, "FIM\n", 4); //escreve em stdout_original

    return 0;
}

// stdin (0) -> teclado
// stdout (1) -> ecrã
// stderr (2) -> ecrã

//Ex3
int main(int argc, char const *argv[]){
    if(fork() == 0){
        int out_fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(out_fd, STDOUT_FILENO);
        close(out_fd);

        execlp("ls", "ls", NULL); // segundo ls equivale a argv[0] e o primeiro equivale ao binário
        _exit(1);
    }
    return 0;
}

//Ex4
int main(int argc, char const *argv[]){
    int pipe_fd[2];
    pipe(pipe_fd); //cria o pipe

    if(fork() == 0){ //filho
        close(pipe_fd[1]); //fecha o pipe para o filho não escrever
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);

        execlp("wc", "wc", NULL);
        _exit(1);
    }

    close(pipe_fd[0]); //fecha o pipe para o pai não ficar à espera

    char *contents = "ola tudo bem? sim, e contigo?\n já chegaste?\n";
    write(pipe_fd[1], contents, strlen(contents)); //escreve no pipe
    close(pipe_fd[1]); //fecha descritor de escrita

    return 0;
}

//Ex5
//o pai vai dando tarefas aos filhos pela pipeline
int main(int argc, char *argv[]){
    int pipe_fd[2];
    pipe(pipe_fd);
    if(fork() == 0){
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);

        execlp("ls", "ls", "/etc", NULL);
        _exit(1);
    }
    close(pipe_fd[1]);

    if(fork() == 0){
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);

        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }

    close(pipe_fd[0]);

    return 0;
}

//Ex6
int main(int argc, char *argv[]){
    int pipe_fd[3][2];
    pipe(pipe_fd[0]);
    
    //grep
    if(fork() == 0){
        close(pipe_fd[0][0]);
        dup2(pipe_fd[0][1], STDOUT_FILENO);
        close(pipe_fd[0][1]);

        execlp("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
        _exit(1);
    }
    close(pipe_fd[0][1]);

    //cut
    pipe(pipe_fd[1]); //cut -> unit
    if(fork() == 0){
        close(pipe_fd[1][0]);
        dup2(pipe_fd[0][0], STDIN_FILENO);
        close(pipe_fd[0][0]);
        dup2(pipe_fd[1][1], STDOUT_FILENO);
        close(pipe_fd[1][1]);

        execlp("cut", "cut", "-f7", "-d:", NULL);
        _exit(1);
    }
    close(pipe_fd[0][0]);
    close(pipe_fd[1][1]);

    //uniq
    pipe(pipe_fd[2]); //uniq -> wc
    if(fork() == 0){
        close(pipe_fd[2][0]);
        dup2(pipe_fd[1][0], STDIN_FILENO);
        close(pipe_fd[1][0]);
        dup2(pipe_fd[2][1], STDOUT_FILENO);
        close(pipe_fd[2][1]);

        execlp("uniq", "uniq", NULL);
        _exit(1);
    }
    close(pipe_fd[1][0]);
    close(pipe_fd[2][1]);

    //wc
    if(fork() == 0){
        close(pipe_fd[3][0]);
        dup2(pipe_fd[2][0], STDIN_FILENO);
        close(pipe_fd[2][0]);

        execlp("wc", "wc", "-l", NULL);
        _exit(0);
    }
    close(pipe_fd[2][0]);

    for(int i = 0; i < 4; i++){
        wait(NULL); //espera pelos filhos
    }
    return 0;
}