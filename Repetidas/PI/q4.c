#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[100];
    int nr;
    int nota;
} Aluno;

typedef struct cel {
    Aluno *aluno;
    struct cel *prox;
} *Turma;

int adicionaAluno(Turma *t, char *nome, int nr, int nota) {
    Aluno *novo_aluno = malloc(sizeof(Aluno));
    if (novo_aluno == NULL) return 1;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->nr = nr;
    novo_aluno->nota = nota;
    struct cel *nova_cel = malloc(sizeof(struct cel));
    if (nova_cel == NULL) {
        free(novo_aluno);
        return 1;
    }
    nova_cel->aluno = novo_aluno;
    while (*t != NULL && (*t)->aluno->nota < nota) {
        t = &((*t)->prox);
    }
    nova_cel->prox = *t;
    *t = nova_cel;
    return 0;
}

void imprimeTurma(Turma t) {
    printf("Turma (ordenada por nota crescente):\n");
    while (t != NULL) {
        printf("Nome: %s, Nr: %d, Nota: %d\n", 
               t->aluno->nome, t->aluno->nr, t->aluno->nota);
        t = t->prox;
    }
}

void libertaTurma(Turma t) {
    while (t != NULL) {
        Turma temp = t;
        t = t->prox;
        free(temp->aluno);
        free(temp);
    }
}

int main(){
    Turma turma = NULL;
    if (adicionaAluno(&turma, "Joao Silva", 12345, 15) != 0) {
        printf("Erro ao adicionar aluno!\n");
        return 1;
    }
    if (adicionaAluno(&turma, "Maria Santos", 54321, 10) != 0) {
        printf("Erro ao adicionar aluno!\n");
        return 1;
    }
    if (adicionaAluno(&turma, "Carlos Pereira", 67890, 18) != 0) {
        printf("Erro ao adicionar aluno!\n");
        return 1;
    }
    if (adicionaAluno(&turma, "Ana Oliveira", 98765, 12) != 0) {
        printf("Erro ao adicionar aluno!\n");
        return 1;
    }
    imprimeTurma(turma);
    libertaTurma(turma);
    return 0;
}