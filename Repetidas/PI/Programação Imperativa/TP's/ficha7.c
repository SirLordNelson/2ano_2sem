#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char *palavra;
    int ocorr;
    struct celula *prox;
} * Palavras;

//Ex1
void libertaLista(Palavras l){
    Palavras aux;
    while (l != NULL){
        aux = l;
        l = l->prox;
        free(aux->palavra);
        free(aux);
    }
}

//Ex2
int quantasP(Palavras l){
    int i = 0;
    while(l != NULL){
        i++;
        l = l->prox;
    }
    return i;
}

//Ex3
void listaPal(Palavras l){
    while(l != NULL){
        char *p = l->palavra;
        int o = l->ocorr;
        printf("%s %d\n", p, o);
        l = l->prox;
    }
}

//Ex4
char *ultima(Palavras l){
    while(l != NULL){
        if(l->prox == NULL) return l->palavra;
        l = l->prox;
    }
    return NULL;
}

//Ex5
Palavras acrescentaInicio(Palavras l, char *p){
    Palavras new = malloc(sizeof(struct celula));
    if(new == NULL) return NULL;
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = l;
    
    return new;
}

//Ex6
Palavras acrescentaFim(Palavras l, char *p){
    Palavras ult = malloc(sizeof(struct celula));
    if(ult == NULL) return NULL;
    ult->palavra = strdup(p);
    ult->ocorr = 1;
    ult->prox = NULL; //esqueci-me disto

    if(l == NULL) return ult;
    while(l->prox != NULL){ //para no último
        l = l->prox;
    }
    l->prox = ult;

    return l;
}

//Ex7
Palavras acrescenta(Palavras l, char *p){
    Palavras ant = NULL, atual = l;

    while(atual != NULL && strcmp(atual->palavra, p) < 0){
        ant = atual;
        atual = atual->prox;
    }

    if(atual != NULL && strcmp(atual->palavra, p) == 0){
        atual->ocorr++;
        return l;
    }

    Palavras new = malloc(sizeof(struct celula));
    if(new == NULL) return NULL;
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = atual;

    if(ant == NULL) return new; // Inseriu no início
    else{
        ant->prox = new;
        return l; // Lista inicial não muda
    }
}

void imprimeLista(Palavras l){
    while(l != NULL){
        printf("%s: %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

int main(){
    Palavras lista = NULL;
    char *entrada[] = {"banana", "abacaxi", "banana", "uva", "abacaxi", "pera", "banana"};
    int n = sizeof(entrada) / sizeof(entrada[0]);

    for(int i = 0; i < n; i++){
        lista = acrescenta2(lista, entrada[i]);
    }
    imprimeLista(lista);
    libertaLista(lista);

    return 0;
}

//Ex8
struct celula *maisFreq(Palavras l){
    struct celula *mais_freq = NULL;
    int maior = 0;
    while(l != NULL){
        if(l->ocorr > maior){
            maior = l->ocorr;
            mais_freq = l;
        }
        l = l->prox;
    }
    return mais_freq;
}