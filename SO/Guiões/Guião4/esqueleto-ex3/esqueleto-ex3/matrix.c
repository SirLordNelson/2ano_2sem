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

void lookupNumber(int** matrix, int value, int* vector){
    //Hint - use the Minfo struct from matrix.h
}