#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> // chamadas ao sistema: defs e decls essenciais
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT, O_*

int open(const char *path, int oflag [, mode]);
ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
off_t lseek(int fd, off_t offset, int whence);
int close(int fildes);

//Ex 1
int main(int argc, char *argv[]){
    int read_bytes;
    char buf[100];
    
    if(argc == 1){   
        while((read_bytes = read(0, buf, 100)) > 0){
            printf ("%d\n", read_bytes);
            write(1, buf, read_bytes);
        }
    }else if (argc == 2){   
        int fd = open(argv[1], O_RONLY, 0600);
        if (fd < 0){
            perror ("open");
            return 1;
        }
        read_bytes = read(fd, buf, 100);
        write(1, buf, read_bytes);
        close(fd);
    }
    return 0;
}

//Ex 1a)
int main(int argc, char *argv[]){
    int read_bytes;
    char buf[100];
    
    if(argc > 1){   
        int fd = open(argv[1], O_RDWR, 0600);
        if(fd < 0){
            perror ("open");
            return 1;
        }
        read_bytes = read(fd, buf, 100);
        write(1, buf, read_bytes);
    }
    return 0;
}

//Ex 2
int main(int argc, char argv[]){
    if(argc < 3){
        perror("Invalid file(s).");
        return -1;
    }

    int fd1 = open(argv[1], O_RDONLY, 0660);
    if(fd1 < 0){
        perror("Invalid file.");
        close(fd1);
        return -1;
    }

    int fd2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if(fd2 < 0){
        perror("Invalid file.");
        close(fd2);
        return -1;
    }

    unsigned char buffer[4096] = { 0 };

    //ajustar o tamanho do buffer
    size_t buf_s = 4096;
    if(argc == 4){
        charsave = NULL;
        buf_s = strtol(argv[3], &save, 10); //do argv[3], do byte 10, para o save
        buf_s = 4096 < buf_s ? 4096 : buf_s;
        if(!save){
            static const char ERROR[] = "This is not the size you wanted.";
            write(1, ERROR, sizeof(ERROR));
            return -1;
        }
    }

    //escreve no buffer
    for(ssize_t i = read(fd1, buffer, buf_s); i > 0; i = read(fd1, buffer, buf_s)){
        write(fd2, buffer, i);
    }

    return 0;
}