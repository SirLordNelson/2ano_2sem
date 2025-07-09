#include "matrix.h"


int main(int argc, char *argv[]) {

    // generate random matrix
    int **matrix = createMatrix();

    // print matrix
    printMatrix(matrix);

    int factos = valueExists(matrix, 5);
    if(factos){
        printf("O valor 5 existe.\n");
        linesWithValue(matrix, 5);
    }
    else printf("O valor não existe.\n");

    // free matrix
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}