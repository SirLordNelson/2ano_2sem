#include <stdio.h>
#include <string.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//Ex1
//fiz sozinho
int length (LInt l){
    int r = 0;
    while(l->prox != NULL){
        r++;
    }
    return r;
}

//Ex2
//copiei a linha 27
void freeL (LInt a){
    LInt next;
    while(a){
        next = a->prox;
        a->prox = NULL;
        free(a);
        a = next;
    }
}

//Ex3
//fiz sozinho
void imprimeL (LInt a){
    while(a){
        printf("%d\n", a->valor);
        a = a->prox;
    }
}

//Ex4
//feita pelo Deepseek
LInt reverseL (LInt l){
    LInt prev = NULL;
    while (l != NULL) {
        LInt next = l->prox;
        l->prox = prev;
        prev = l;
        l = next;
    }
    return prev;
}

//Ex5
//aprimorada pelo Deepseek
void insertOrd(LInt *l, int a) {
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = a;
    novo->prox = NULL; //faltou isto
    if (*l == NULL || (*l)->valor >= a) { //faltou este if
        novo->prox = *l;
        *l = novo;
    }else{
        LInt atual = *l;
        while (atual->prox != NULL && atual->prox->valor < a) {
            atual = atual->prox;
        }
        // parte aprimorada
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

//Ex6
//aprimorada pelo Deepseek
int removeOneOrd(LInt *l, int a) {
    if (*l == NULL) return 1; //se for vazia
    LInt atual = *l;
    LInt anterior = NULL; //dá mais jeito se for anterior ao invés de next
    while (atual != NULL && atual->valor < a) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL && atual->valor == a) {
        if (anterior == NULL) *l = atual->prox; //se for o primeiro elemento
        else anterior->prox = atual->prox;
        free(atual);
        return 0;
    } else return 1;
}

//Ex7
//fiz com ajuda
void merge (LInt *r, LInt a, LInt b){
    LInt l = *r;
    if(!a) l = b;
    else if(!b) l = a;
    else if(a->valor < b->valor){
        l = a;
        merge(l->prox, a->prox, b); //usar recursividade
    }
    else{
        l = b;
        merge(l->prox, a, b->prox);
    }
}

//Ex8
//fiz sozinho, mas com alguma ajuda
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(l){
        if(l->valor < x){
            *mx = malloc(sizeof(struct lligada));
            (*mx)->valor = l->valor; //ia-me esquecendo desta parte... ATENTO!!!
            splitQS(l->prox, x, &(*mx)->prox, *Mx); //faltou-me o &
        }else{
            *Mx = malloc(sizeof(struct lligada));
            (*Mx)->valor = l->valor;
            splitQS(l->prox, x, *mx, &(*Mx)->prox);
        }
    }
}

//Ex9
//não tinha percebido bem o exercício
LInt parteAmeio (LInt *l){
    int d = length(*l);
    if(d == 0) return NULL;
    LInt y = *l;
    LInt prev = NULL;
    for(int i = 0; i < d/2; i++){
        prev = *l;
        *l = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

//Ex10
//fiz sozinho, mas com alguma ajuda
int removeAll (LInt *l, int a){
    int rem = 0;
    LInt prev = NULL;
    while(*l){
        if((*l)->valor == a){
            if(!prev) *l = (*l)->prox; //melhorar entendimento destes exercícios com apontadores
            else prev->prox = (*l)->prox;
            rem++;
        }else{
            prev = *l;
            *l = &((*l)->prox);
        }
    }
}

//Ex11
//fiz sozinho com ajuda do Deepseek
int removeDups (LInt *l){
    int rem = 0;
    LInt a = *l;
    for(; a != NULL; a = a->prox){
        LInt aux = a->prox;
        LInt prevaux = a;
        while(aux != NULL){
            if(a->valor == aux->valor){
                prevaux->prox = aux->prox; //adicionou ->prox no prevaux
                free(aux);
                aux = prevaux->prox; //adicionou esta linha
                rem++;
            }else{ //adicionou esta parte
                prevaux = aux;
                aux = aux->prox;
            }
        }
    }
    return rem;
}

//Ex12
//fiz sozinho com ajuda do Deepseek
int removeMaiorL (LInt *a){
    if (*a == NULL) return -1; //adicionada

    LInt l = *a;
    int maior = l->valor; //deu valor
    LInt mega = l; //deu valor
    LInt prevmega = NULL;
    while(l->prox != NULL){
        if((l->prox)->valor > maior){
            maior = (l->prox)->valor;
            mega = l->prox;
            prevmega = l:
        }
        l = l->prox;
    }
    if(prevmega == NULL) *a = mega->prox; //adicionada
    else prevmega->prox = mega->prox; //adicionada
    free(mega);
    return maior;
}

//Ex13
//fiz com ajuda da Sofia
void init (LInt *l) {
    LInt prev = NULL;
    for(;(*l)->prox; prev = *l, l = &((*l)->prox)); //aprimorada
    if(!prev) { //adicionada
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

//Ex14
//fiz sozinho com ajuda da Sofia
void appendL (LInt *a, int x){
    for(; (*a)->prox; *a = &((*a)->prox));
    LInt l = malloc(sizeof(struct lligada));
    l->valor = x;
    l->prox = NULL;
    if(!(*a)) (*a) = l; //adicionada
    (*a)->prox = l;
}

//Ex15
//fiz sozinho com ajuda do jteixeira
void concatL (LInt *a, LInt b){
    if(*a){ //if adicionado
        for(; (*a)->prox; *a = &((*a)->prox));
        (*a)->prox = b;
    }else *a = b; //else adicionado
}

//Ex16
//fiz sozinho com ajuda da Sofia
LInt cloneL (LInt a){
    if(!a) return NULL; //adicionada
    LInt l = malloc(sizeof(struct lligada));
    l->valor = a->valor;
    l->prox = cloneL(a->prox); //aprimorada
    return l;
}

//Ex17
//copiei da Sofia
LInt cloneRev2 (LInt l){
    LInt list = NULL;
    while(l){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list; //parte mais importante!!!
        list = new;
        l = l->prox;
    }
    return list;
}

//Ex18
//fiz sozinho
int maximo (LInt l){
    int maior = l->valor;
    while(l != NULL){ //aprimorada pelo Deepseek
        if(l->valor > maior) maior = l->valor;
        l = l->prox;
    }
    return maior;
}

//Ex19
//copiei da Sofia
//compliquei demasiado nesta
int take (int n, LInt *l){
    int i = 0;
    for(;i < n && *l; i++, l = &((*l)->prox));
    if(!(*l)) return i;
    for(;*l;){
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

//Ex20
int drop (int n, LInt *l){
    int i = 0;
    for(; i < n && *l; i++, *l = (*l)->prox){ //Deepseek retirou o & antes do (*l)->prox
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return i;
}

//Ex21
//fiz sozinho
LInt Nforward (LInt l, int N){
    for(int i = 0; i < N; i++){ //otimização temporal do Deepseek
        l = l->prox;
    }
    return l;
}

//Ex22
//fiz sozinho, com algumas otimizações da Sofia
int listToArray (LInt l, int v[], int N){
    int i = 0;
    for(; i < N && l; l = l->prox){
        v[i++] = l->valor;
    }
    return i;
}

//Ex23
//fiz sozinho com inspiração da Sofia
LInt arrayToList (int v[], int N){ //recursivamente dá mais jeito
    if(N == 0) return NULL;
    LInt l = malloc(sizeof(struct lligada));
    l->valor = (*v);
    l->prox = arrayToList(v+1, N-1);
    return l;
}

//Ex24
//fiz sozinho com ajuda da Sofia e do Deepseek
LInt somasAcL (LInt l){
    if (l == NULL) return NULL; //adicionado pelo Deepseek
    int m = 0;
    LInt prev = NULL; //prev não é um nó, mas um ponteiro que sempre referencia o último nó adicionado
    LInt list = NULL;
    for(; l; l = l->prox){ //ciclo ajuda mais
        m = m + l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = m;
        new->prox = NULL;
        if(!list){ //adicionado pela Sofia
            list = new; //list é preenchido apenas uma vez (com o primeiro new)
            prev = new;
        }else{ //adicionado pela Sofia
            //Depois, prev redireciona o final da lista (prev->prox) para o novo nó e atualiza seu próprio valor para new
            //A lista cresce porque prev liga cada new ao último nó existente, enquanto list mantém a referência do início
            prev->prox = new;
            prev = new;
        }
    }
    return list;
}

//Ex25
//fiz sozinho com ajuda da Sofia
void remreps (LInt l){
    if(l){
        while(l->prox){
            if(l->valor == (l->prox)->valor){
                l->prox = (l->prox)->prox;
                free(l->prox); //estava mal colocado
            }else l = l->prox;
        }
    }
}

//Ex26
//copiei da Sofia
LInt rotateL (LInt l){
    if(!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while(temp->prox) temp = temp->prox; 
    temp->prox = l;
    l->prox = NULL;
    return list;
}

//Ex27
//não li bem o enunciado
LInt parte(LInt l) {
    if(!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;
    newL->prox = parte(l->prox);
    return newL;
}


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//Ex28
//copiei da Sofia pq não me lembrava como se faziam máscaras
int altura(ABin tree){
    if(tree == NULL) return 0;
    return 1 + (altura(tree->esq) > altura(tree->dir) ? altura(tree->esq) : altura(tree->dir));
}

//Ex29
//fiz sozinho
ABin cloneAB (ABin tree){
    if(!tree) return NULL;

    ABin a = malloc(sizeof(struct nodo));
    a->valor = tree->valor;
    a->esq = cloneAB(tree->esq);
    a->dir = cloneAB(tree->dir);
    return a;
}

//Ex30
//fiz sozinho com ajuda do jteixeira
void mirror (ABin *tree){
    ABin temp;
    if(*tree){
        temp = (*tree)->dir;
        (*tree)->dir = (*tree)->esq;
        (*tree)->esq = temp;
        mirror(&(*tree)->esq); //não sabia como colocar aqui
        mirror(&(*tree)->dir);
    }
}

//Ex31
//ordem de visita: Subárvore esquerda; Raiz; Subárvore direita
void inorder(ABin a, LInt *l){
    if(a){
        LInt new, pt;
        inorder(a->esq, l);
        for (; *l; l = &(*l)->prox);
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;
        inorder(a->dir, l);
    }
    else *l = NULL;
}

//Ex32
//ordem de visita: Raiz; Subárvore esquerda; Subárvore direita
void preorder(ABin a, LInt *l){
    if(a){
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;
        preorder(a->esq, l);
        for (; *l; l = &(*l)->prox);
        preorder(a->dir, l);
    }else *l = NULL;
}

//Ex33
//ordem de visita: Subárvore esquerda; Subárvore direita; Raiz
void posorder(ABin a, LInt *l){
    if(a){
        posorder(a->esq, l);
        for (; *l; l = &(*l)->prox);
        posorder(a->dir, l);
        for (; *l; l = &(*l)->prox);
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }else *l = NULL;
}

//Ex34
//feita pelo Deepseek
int depth (ABin a, int x){
    if(!a) return -1;
    if(a->valor == x) return 1;

    int esq = depth(a->esq, x);
    int dir = depth(a->dir, x);
    
    //parte adicionada
    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return dir + 1;
    if(dir == -1) return esq + 1;
    
    return (esq < dir ? esq : dir) + 1;
}

//Ex35
//fiz sozinho com ajuda do Deepseek
int freeAB (ABin a){
    if(!a) return 0;

    int n = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return n;
}

//Ex36
//fiz sozinho com ajuda do Deepseek
int pruneAB (ABin *a, int l){
    if(!(*a)) return 0;

    if(l == 0){ //parte aprimorada
        int r = freeAB(*a);
        *a = NULL;
        return r;
    }
    int r = pruneAB(a->esq, l-1) + pruneAB(a->dir, l-1); 
    return r;
}

//Ex37
//fiz sozinho
int iguaisAB (ABin a, ABin b){
    if(!a && b || a && !b) return 0;
    if(!a && !b || a && b) return 1;
    return a->valor == b->valor && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}

//Ex38
//copiei da Sofia pq não tinha percebido bem o que era para fazer
LInt concat(LInt a, LInt b){
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}

LInt nivelL (ABin a, int n){
    if(!a || n < 1) return NULL;
    if(n == 1){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq, n - 1), nivelL(a->dir, n - 1));
}

//Ex39
//fiz sozinho com ajuda da Sofia
int nivelV (ABin a, int n, int v[]){
    if(!a || n < 1) return 0;
    if(n == 1){
        (*v) = a->valor;
        return 1;
    }else{ //aprimorado pela Sofia
        int e = nivelV(a->esq, n-1, v);
        int d = nivelV(a->dir, n-1, v + e);
        return e + d;
    }
}

//Ex40
//fiz sozinho com ajuda do jteixeira
int dumpAbin (ABin a, int v[], int N){
    if(!a || N <= 0) return 0;

    int r = dumpAbin(a->esq, v, N);
    v[r] = a->valor;
    ++r; //parte adicionada
    r += dumpAbin(a->dir, v + r, N - r);
    return r;
}

//Ex41
//fiz sozinho com ajuda da Sofia
ABin somasAcA (ABin a){
    if(!a) return NULL;

    ABin t = malloc(sizeof(struct nodo));
    t->esq = somasAcA(a->esq);
    t->dir = somasAcA(a->dir);
    t->valor = a->valor + (t->esq ? t->esq->valor : 0) + (t->dir ? t->dir->valor : 0); //copiei da Sofia
    return t;
}

//Ex42
//fiz sozinho com ajuda do Deepseek
int contaFolhas(ABin a){
    if (!a) return 0;
    if (!a->esq && !a->dir) return 1;
    
    return contaFolhas(a->esq) + contaFolhas(a->dir); //Deepseek simplificou
}