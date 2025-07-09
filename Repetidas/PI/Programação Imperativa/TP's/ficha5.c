#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//Ex1
int nota(Aluno a){
    int notaTM = 0;
    for(int i = 0; i < 6; i++){
        notaTM = notaTM + a.miniT[i];
    }
    notaTM = notaTM/6;
    float media = (a.teste*0.8) + (notaTM*0.2);
    if(media >= 9.5) return media;
    else return 0;
}

int main(){
    Aluno aluno1 = {
        .numero = 12345,
        .nome = "João Silva",
        .miniT = {10, 12, 14, 8, 15, 11},
        .teste = 13.5
    };
    int notaFinal = nota(aluno1);
    if (notaFinal >= 9.5) printf("O aluno %s (Número: %d) obteve uma nota final de %d.\n", aluno1.nome, aluno1.numero, notaFinal);
    else printf("O aluno %s (Número: %d) não atingiu a nota mínima para aprovação.\n", aluno1.nome, aluno1.numero);
    return 0;
}

//Ex2
int procuraNum(int num, Aluno t[], int N){
    for(int i = 0; i < N; i++){
        if(t[i].numero == num) return i;
    }
    return -1;
}

int main() {
    Aluno alunos[] = {
        {12345, "João Silva", {10, 12, 14, 8, 15, 11}, 13.5},
        {67890, "Maria Santos", {9, 11, 13, 10, 12, 14}, 15.0},
        {54321, "Carlos Oliveira", {8, 10, 12, 9, 11, 13}, 10.5}
    };
    int N = sizeof(alunos) / sizeof(alunos[0]);
    int numeroProcurado = 67890;
    int indice = procuraNum(numeroProcurado, alunos, N);
    if(indice != -1){
        printf("Aluno encontrado no índice %d:\n", indice);
        printf("Nome: %s\n", alunos[indice].nome);
        printf("Número: %d\n", alunos[indice].numero);
    }else printf("Aluno com número %d não encontrado.\n", numeroProcurado);
    return 0;
}

//Ex3
//o DeepSeek corrigiu a categoria do temp
void ordenaPorNum(Aluno t[], int N){
    Aluno temp;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-i-1; j++){
            if(t[j].numero > t[j+1].numero){
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }
}

int main(){
    Aluno alunos[] = {
        {54321, "Carlos Oliveira", {8, 10, 12, 9, 11, 13}, 10.5},
        {12345, "João Silva", {10, 12, 14, 8, 15, 11}, 13.5},
        {67890, "Maria Santos", {9, 11, 13, 10, 12, 14}, 15.0}
    };
    int N = sizeof(alunos) / sizeof(alunos[0]);
    printf("Antes da ordenação:\n");
    for (int i = 0; i < N; i++) {
        printf("Número: %d, Nome: %s\n", alunos[i].numero, alunos[i].nome);
    }
    ordenaPorNum(alunos, N);
    printf("\nApós a ordenação:\n");
    for (int i = 0; i < N; i++) {
        printf("Número: %d, Nome: %s\n", alunos[i].numero, alunos[i].nome);
    }
    return 0;
}

//Ex4
//DeepSeek adicionou o [ind[j]] no if
void criaIndPorNum(Aluno t[], int N, int ind[]){
    for(int i = 0; i < N; i++){
        ind[i] = i;
    }
    int temp;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-i-1; j++){
            if(t[ind[j]].numero > t[ind[j+1]].numero){
                temp = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = temp;
            }
        }
    }
}

int main(){
    Aluno alunos[] = {
        {4444, "André", {2, 1, 0, 2, 2, 2}, 10.5},
        {2222, "Joana", {2, 2, 2, 1, 0, 0}, 14.5},
        {7777, "Maria", {2, 2, 2, 2, 2, 1}, 18.5},
        {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7}
    };
    int N = sizeof(alunos) / sizeof(alunos[0]);
    int ind[N];
    criaIndPorNum(alunos, N, ind);
    for (int i = 0; i < N; i++) {
        printf("%d\n", ind[i]);
    }
    return 0;
}

//Ex5
void imprimeTurma(int ind[], Aluno t[], int N){
    criaIndPorNum(t, N, ind);
    int w;
    for(int i = 0; i < N; i++){
        w = ind[i];
        printf("Número: %d, Nome: %s, Nota: %d\n", t[w].numero, t[w].nome, nota(t[w]));
    }
}

int main(){
    Aluno alunos[] = {
        {4444, "André", {2, 1, 0, 2, 2, 2}, 10.5},
        {2222, "Joana", {2, 2, 2, 1, 0, 0}, 14.5},
        {7777, "Maria", {2, 2, 2, 2, 2, 1}, 18.5},
        {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7}
    };
    int N = sizeof(alunos) / sizeof(alunos[0]);
    int ind[N];
    imprimeTurma(ind, alunos, N);
    return 0;
}

//Ex6
int procuraNum2(int num, Aluno t[], int N, int ind[]){
    criaIndPorNum(t, N , ind);
    int w;
    for(int i = 0; i < N; i++){
        w = ind[i];
        if(num == t[w].numero) return w;
    }
    return -1;
}

int main(){
    Aluno alunos[] = {
        {4444, "André", {2, 1, 0, 2, 2, 2}, 10.5},
        {2222, "Joana", {2, 2, 2, 1, 0, 0}, 14.5},
        {7777, "Maria", {2, 2, 2, 2, 2, 1}, 18.5},
        {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7}
    };
    int N = sizeof(alunos) / sizeof(alunos[0]);
    int ind[N];
    int numeroProcurado = 2222;
    int indice = procuraNum2(numeroProcurado, alunos, N, ind);
    if(indice != -1){
        printf("Aluno encontrado no índice %d:\n", indice);
        printf("Número: %d, Nome: %s, Nota: %d\n", alunos[indice].numero, alunos[indice].nome, nota(alunos[indice]));
    }else printf("Aluno com número %d não encontrado.\n", numeroProcurado);
    return 0;
}

//Ex7
//feita pelo DeepSeek, pq não sabia da função strcmp
void criaIndPorNome(Aluno t[], int N, int ind[]){
    for(int i = 0; i < N; i++){
        ind[i] = i;
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-i-1; j++){
            if(strcmp(t[ind[j]].nome, t[ind[j + 1]].nome) > 0){ //compara duas strings lexicograficamente (em ordem alfabética)
                int temp = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = temp;
            }
        }
    }
}

int main(){
    Aluno alunos[] = {
        {4444, "André", {2, 1, 0, 2, 2, 2}, 10.5},
        {2222, "Joana", {2, 2, 2, 1, 0, 0}, 14.5},
        {7777, "Maria", {2, 2, 2, 2, 2, 1}, 18.5},
        {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7}
    };
    int N = sizeof(alunos) / sizeof(alunos[0]);
    int ind[N];

    criaIndPorNome(alunos, N, ind);

    printf("Alunos ordenados pelo nome:\n");
    for(int i = 0; i < N; i++){
        int w = ind[i];
        printf("Nome: %s, Número: %d\n", alunos[w].nome, alunos[w].numero);
    }
    return 0;
}