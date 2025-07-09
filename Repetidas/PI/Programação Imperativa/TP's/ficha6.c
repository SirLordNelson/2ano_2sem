#include <stdio.h>
#include <stdlib.h>

//Ex1
struct staticStack{
    int sp; //stack pointer
    int values [Max];
} STACK, *SStack;

//Ex1a)
void SinitStack(SStack s){
    s->sp = 0;
}

//Ex1b)
int SisEmpty(SStack s){
    if(s->sp == 0) return 1;
    else return 0;
}

//Ex1c)
int Spush(SStack s, int x){
    if(s->sp >= Max) return 1;
    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

//Ex1d)
int Spop(SStack s, int *x){
    if(s->sp == 0) return 1;
    s->sp--;                //sp sempre aponta para onde o próximo push vai inserir
    *x = s->values[s->sp];
    return 0;
}

//Ex1e)
int Stop(SStack s, int *x){
    if(s->sp == 0) return 1;
    *x = s->values[s->sp - 1];
    return 0;
}

//Ex2
struct staticQueue{
    int front;      //aponta para o elemento mais antigo (o próximo a sair)
    int length;
    int values[Max];
} QUEUE, *SQueue;

//Ex2a)
void SinitQueue (SQueue q){
    q->front = 0;
    q->length = 0;
}

//Ex2b)
int SisEmptyQ(SQueue q){
    if(q->length == 0) return 1;
    else return 0;
}

//Ex2c)
int Senqueue(SQueue q, int x){
    if(q->length == Max) return 1;
    q->values[(q->front + q->length) % Max] = x;    //faz-se % Max para que o array seja circular
    q->length++;
    return 0;
}

//Ex2d)
int Sdequeue(SQueue q, int *x){
    if(q->length == 0) return 1;
    *x = q->values[q->front];
    q->front = (q->front + 1) % Max;
    q->length--;
    return 0;
}

//Ex2e)
int Sfront(SQueue q, int *x){
    if(q->length == 0) return 1;
    *x = q->values[q->front];
    return 0;
}



//Ex3
//Stack dinâmica
typedef struct dinStack{
    int size;
    int sp;
    int *values;
} *DStack;

void DinitStack(DStack s){
    s->size = 1;
    s->sp = 0;
    s->values = malloc(s->size * sizeof(int));
}

int DisEmpty(DStack s){
    return (s->sp == 0);
}

int Dpush(DStack s, int x){
    if(s->sp == s->size){
        int *new_values = malloc(2 * s->size * sizeof(int));
        if(!new_values) return 1;
        for(int i = 0; i < s->sp; i++) new_values[i] = s->values[i];
        free(s->values);
        s->values = new_values;
        s->size *= 2;
    }
    s->values[s->sp++] = x;
    return 0;
}

int Dpop(DStack s, int *x){
    if(DisEmpty(s)) return 1;
    *x = s->values[s->sp - 1];
    return 0;
}

void DfreeStack(DStack s){
    free(s->values);
}

//Queue dinâmica
typedef struct dinQueue{
    int size;
    int front;
    int length;
    int *values;
} *DQueue;

void DinitQueue(DQueue q){
    q->size = 1;
    q->front = 0;
    q->length = 0;
    q->values = malloc(q->size * sizeof(int));
}

int DisEmptyQ(DQueue q){
    return (q->length == 0);
}

int Denqueue(DQueue q, int x){
    if(q->length == q->size){
        int *new_values = malloc(2 * q->size * sizeof(int));
        if(!new_values) return 1;
        for(int i = 0; i < q->length; i++){
            new_values[i] = q->values[(q->front + i) % q->size];
        }
        free(q->values);
        q->values = new_values;
        q->front = 0;
        q->size *= 2;
    }
    q->values[(q->front + q->length) % q->size] = x;
    q->length++;
    return 0;
}

int Ddequeue(DQueue q, int *x){
    if(DisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    q->front = (q->front + 1) % q->size;
    q->length--;
    return 0;
}

void DfreeQueue(DQueue q){
    free(q->values);
}