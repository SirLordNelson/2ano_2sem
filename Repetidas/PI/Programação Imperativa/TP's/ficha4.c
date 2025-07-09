#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Ex 1.1
int isVogal(char s){
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return 1;
    if(s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') return 1;
    else return 0;
}

int contaVogais (char *s){
    int m = 0;
    while(*s != '\0'){
        if(isVogal(*s)) m++;
        s++;
    }
    return m;
}

int main(){
    char *s = {"disnuts"};
    int m = contaVogais(s);
    printf("%d\n", m);
}

//Ex 1.2
//o Deepseek corrigiu a primeira definição da main e adicionou os []'s
int retiraVogaisRep(char *s) {
    int m = 0;
    int j = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(isVogal(s[i]) && s[i] == s[i + 1]) m++;
        else{
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
    return m;
}

int main(){
    char s[] = "Estaa e umaa string coom duuuplicadoos";
    int m = retiraVogaisRep(s);
    printf("%d\n", m);
    printf("%s\n", s);
}

//Ex 1.3
//o Chat criou o temp
int duplicaVogais(char *s){
    char temp[200];
    int m = 0, j = 0;
    for(int i = 0; s[i] != '\0'; i++){
        temp[j++] = s[i];
        if(isVogal(s[i])){
            temp[j++] = s[i];
            m++;
        }
    }
    temp[j] = '\0';
    strcpy(s, temp);
    return m;
}

int main(){
    char s[100] = "programacao";
    int m = duplicaVogais(s);
    printf("%d\n", m);
    printf("%s\n", s);
}

//Ex 2.1
int ordenado(int v[], int N){
    for(int i = 0; i < N; i++){
        if(v[i+1] == '\0') break;
        if(v[i] > v[i+1]) return 0;
    }
    return 1;
}

int main(){
    int v[] = {10, 20, 30, 40, 50};
    int N = 5;
    int m = ordenado(v, N);
    printf("%d\n", m);
    return 0;
}

//Ex 2.2
//o Chat adicionou os outros 2 ciclos
void merge(int a[], int na, int b[], int nb, int r[]){
    int j = 0;
    int w = 0;
    int i = 0;

    while(j < na && w < nb){
        if(a[j] < b[w]) r[i++] = a[j++];
        else r[i++] = b[w++];
    }

    while (j < na){
        r[i++] = a[j++];
    }

    while (w < nb){
        r[i++] = b[w++];
    }
}

int main(){
    int a[] = {1,3,5};
    int b[] = {2,4,6};
    int na = 3;
    int nb = 3;
    int r[na+nb];
    merge(a, na, b, nb, r);
    for (int i = 0; i < na + nb; i++){
        printf("%d\n", r[i]);
    }
    return 0;
}

//Ex 2.3
//o Deepseek melhorou o segundo for adicionando: j < N-i-1
void organiza(int v[], int N) {
    int temp;
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N-i-1; j++){
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int partition (int v[], int N, int x){
    organiza(v, N);
    int i = 0;
    for(; i < N; i++){
        if(v[i] == x) break;
    }
    for(int j = 0; j <= i; j++){
        printf("%d\n", v[j]);
    }
}

int main(){
    int N = 5;
    int v[] = {3, 1, 4, 5, 7};
    int x = 5;
    partition(v, N, x);
    return 0;
}