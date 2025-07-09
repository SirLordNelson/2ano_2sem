#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ex 2
void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x = 3, y = 5;
    
    swapM(&x, &y);
    printf("%d %d\n", x, y);
}

//Ex 3
void swap (int v[], int i, int j){
    int w = 0;
    int z = 0;

    for(; w < 3; w++){
        if(w == i) break;
    }
    for(; z < 3; z++){
        if(z == j) break;
    }

    int temp = v[w];
    v[w] = v[z];
    v[z] = temp;
}

int main(){
    int v[3] = {1,2,3};
    int i = 1;
    int j = 2;

    swap(v, i, j);
    
    for(int n = 0; n < 3; n++){
        printf("%d\n", v[n]);
    }
}

//Ex 4
int soma (int v[], int N){
    int r = 0;

    for(int i = 0; i < N; i++){
        r += v[i];
    }

    return r;
}

int main(){
    int N = 6;
    int v[6] = {1,2,3,4,5,6};

    printf("%d\n", soma(v, N));
}

//Ex 5
void inverteArray (int v[], int N){
    int inicio = 0;
    int fim = N-1;

    while(fim >= inicio){
        int temp = v[inicio];
        v[inicio] = v[fim];
        v[fim] = temp;
        inicio++;
        fim--;
    }

    for(int n = 0; n < N; n++){
        printf("%d\n", v[n]);
    }
}

int main(){
    int v[6] = {1,2,3,4,5,6};
    int N = 6;

    inverteArray(v, N);
}

//Ex 6
int maximum(int v[], int N, int *m){
    *m = 0;

    for(int i = 0; i < N; i++){
        if(v[i] > *m) *m = v[i];
    }

    return *m;
}

int main(){
    int v[6] = {1,2,3,9,5,6};
    int N = 6;
    int m;

    printf("%d\n", maximum(v, N, &m));
}

//Ex 7
void quadrados (int q[], int N){
    for(int i = 0; i < N; i++){
        int a = q[i] * q[i];
        q[i] = a;
        printf("%d\n", q[i]);
    }
}

int main(){
    int v[6] = {1,2,3,9,5,6};
    int N = 6;

    quadrados(v, N);
}

//Ex 8a)
//feito pelo Deepseek
void pascal(int v[], int N) {
    v[0] = 1;
    
    for (int linha = 1; linha < N; linha++) {
        v[linha] = 1;
        
        //o vetor v vai sendo atualizado com a soma do valor que estava nessa posição com o anterior
        for (int i = linha - 1; i > 0; i--) {
            v[i] = v[i] + v[i - 1];
        }
    }
}

int main() {
    int N = 5;
    int v[N];
    
    pascal(v, N);
    
    printf("Linha %d do triângulo de Pascal: ", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}

//Ex 8b)
void pascal2(int v[], int N){
    v[0] = 1;

    for (int linha = 0; linha < N; linha++) {
        v[linha] = 1;

        for (int i = linha - 1; i > 0; i--) {
            v[i] = v[i] + v[i - 1];
        }

        for (int i = 0; i <= linha; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
}