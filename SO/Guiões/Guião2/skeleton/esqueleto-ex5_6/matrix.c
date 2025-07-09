#include "matrix.h"

int **createMatrix(){

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for(int i = 0; i < ROWS; i++){
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for(int j = 0; j < COLUMNS; j++){
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix){
    for(int i = 0; i < ROWS; i++){
        printf("%2d | ", i);
        for(int j = 0; j < COLUMNS; j++){
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ex.5
int valueExists(int **matrix, int value){
    int pid;

    for(int i = 0; i < ROWS; i++){
        if((pid == fork()) == 0){
            printf("[pid %d] row: %d\n", getpid(), i);
            
            for(int j = 0; j < COLUMNS; j++){
                if(matrix[i][j] == value) _exit(1);
            }
            _exit(0);
        }
    }
    //os filhos estiveram a trabalhar e agr o pai irá apresentar o trabalho final, uma vez que foi este que iniciou os filhos
    for(int j = 0; j < ROWS; j++){
        int status;
        wait(&status);
        if(WIFEXITED(status) && WEXITSTATUS(status) == 1) return 1;
    }
    return 0;
}

// ex.6
void linesWithValue(int **matrix, int value){
    int pid;
    int status;
    
    for(int i = 0; i < ROWS; i++){
        if((pid == fork()) == 0){
            for(int j = 0; j < COLUMNS; j++){
                if(matrix[i][j] == value){
                    printf("Child PID: %d; found in %d", getpid(), i);
                    _exit(1);
                }
            }
            _exit(0);
        }
    }
    for(int j = 0; j < ROWS; j++){
        wait(&status);
    }
    return 0;
}