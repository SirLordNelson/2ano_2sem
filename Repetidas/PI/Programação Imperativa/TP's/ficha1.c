#include <stdio.h>
#include <stdlib.h>

//Ficha 1//

//Ex3

//1)
int main(){
    char *a = "#";
    int N;

    scanf("%d", &N);

    for(int alt = 0; alt < N; alt++){
        for(int larg = 0; larg < N; larg++){
            printf("%s", a);
        }
        printf("\n");
    }

    return 0;
}

//2)
int main(){
    char *a = "#";
    char *b = "_";
    int N;

    scanf("%d", &N);

    for(int alt = 0; alt < N; alt++){
        if(alt%2 == 0){
            for(int larg = 0; larg < N; larg++){
                if(larg%2 == 0) printf("%s", a);
                else printf("%s", b);
            }
        }
        else{
            for(int larg = 0; larg < N; larg++){
                if(larg%2 == 0) printf("%s", b);
                else printf("%s", a);
            }
        }
        printf("\n");
    }

    return 0;
}

//3)
int horizontal(int N){
        for (int linha = 1; linha <= N; linha++) {
            for (int espaco = 1; espaco <= N - linha; espaco++) {
                printf(" ");
            }
            for (int caractere = 1; caractere <= 2 * linha - 1; caractere++) {
                printf("#");
            }
            printf("\n");
    }
}

int vertical(int N){
    for(int alt = 1; alt < N; alt++){
        for(int larg = 0; larg < alt ; larg++){
            printf("#");
        }
        printf("\n");
    }

    for(int h = N; h > 0; h--){
        for(int larg = 0; larg < h ; larg++){
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int altura;

    scanf("%d", &altura);

    horizontal(altura);

    printf("\n");

    vertical(altura);

    return 0;
}

//4)
int desenharCirculo(int raio){
    int contador = 0;
    for(int linha = -raio; linha <= raio; linha++){
        for(int coluna = -raio; coluna <= raio; coluna++){
            if(coluna*coluna + linha*linha <= raio*raio){//x^2 + y^2 <= raio^2
                printf("#");
                contador++;
            } else printf(" ");
        }
        printf("\n");
    }
    return contador;
}

int main(){
    int N;

    scanf("%d", &N);

    desenharCirculo(N);

    return 0;
}