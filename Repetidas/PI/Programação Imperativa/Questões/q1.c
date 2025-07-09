#include <stdio.h>
#include <string.h>

//Ex4
int bitsUm(unsigned int n){
    int total = 0;
    while(n != 0){
        if(n%2 == 1)total++;
        n/2;
    }
    return total;
}

//Ex6
int qDig(unsigned int n){
    int q = 0;
    while(n != 0){
        n = n/10;
        q++;
    }
    return q;
}

//Ex7
char *strcat(char s1[], char s2[]){
    int i, j;
    for(i = 0; s1[i]; i++);
    for(j = 0; s2[j]; j++){
        s1[i+j] = s2[j];
    }
    s1[i+j] = '\0';
    return s1;
}

//Ex8
char *strcpy(char *dest, char source[]){
    int i = 0;
    for(; source[i]; i++){
        *(dest + i) = source[i];
    }
    *(dest + i) = '\0';
    return dest;
}

//Ex9
//fui ver correção
int strcmp(char s1[], char s2[]){
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return s1[i]-s2[i];
}

//Ex10
//o que se quer é um apontador, não a posição exatamente
char *strstr(char s1[], char s2[]){
    int i = 0;
    for(; s1[i] && s2[0] != s1[i]; i++);
    return i;
}

//o que é pretendido
char *strstr(char s1[], char s2[]){
    int r1, r2;
    char * pos;
    pos = s1;
    r1 = 0;
    r2 = 0;
    while(s1[r1] && s2[r2]){
        if(s1[r1] == s2[r2]){
            r2++;
            if(pos == NULL)pos = s1+r1;
        }
        else{
            r2 = 0;
            pos = NULL;
        }
        r1++;
    }
    if(s2[r2])pos = NULL;
    return pos;
}

//Ex11
void strrev(char s[]){
    int i = 0;
    int temp = 0;
    for(; s[i]; i++);
    for(int j = 0; j <= i; j++, i--){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}

//Ex12
//utilizar o w
void strnoV(char s[]){
    int w = 0;
    for(int i=0; s[i]; i++){
        if(!isVowel(s[i])) s[w++] = s[i];
    }
    s[w] = '\0';
}

//Ex13
//Deepseek adicionou o j, facilita no else
void truncW(char t[], int n){
    int m = 0;
    int j = 0;
    for(int i = 0; t[i]; i++){
        if(!isspace(t[i]) && m < n){
            t[j++] = t[i];
            m++;
        }else{
            t[j++] = t[i];
            m = 0;
        }
    }
    t[j] = '\0';
}

//Ex14
//Deepseek colocou caso de não existir e colocou o if fora do 2 ciclo
char charMaisfreq(char s[]){
    if (s[0] == '\0')return 0;
    int maior = 0;
    char a = s[0];
    for(int i = 0; s[i]; i++){
        int m = 0;
        for(int j = 0; s[j]; j++){
            if(s[i] == s[j]) m++;
        }
        if(m > maior){
            maior = m;
            a = s[i];
        }
    }
    return a;
}

//Ex15
//Deepseek colocou o 2º if no else
int iguaisConsecutivos(char s[]){
    int m = 0;
    int maior = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == s[i+1])m++;
        else{
            if(m > maior) maior = m;
            m = 0;
        }
    }
    return maior;
}

//Ex16
int difConsecutivos(char s[]){
    int m = 1;
    int maior = 1;
    for(int i = 0; s[i]; i++){
        if(s[i] != s[i+1] && s[i+1] != '\0') m++;
        else{
            if(m > maior) maior = m;
            m = 1;
        }
    }
    return maior;
}

//Ex17
int maiorPrefixo(char s1 [], char s2 []){
    int i = 0;
    for(; s1[i] == s2[i] && s1[i]; i++);
    return i;
}

//Ex18
//fui ver o while
int maiorSufixo(char s1 [], char s2 []){
    int i = 0;
    int j = 0;
    int r = -1;
    for(; s1[i]; i++);
    for(; s2[j]; j++);
    while(s1[i--] == s2 [j--]){
        r++;
    }
    return r;
}

//Ex19
//fui ver o else
int sufPref(char s1[], char s2[]){
    int m = 0;
    int j = 0;
    for(int i = 0; s1[i]; i++){
        if(s1[i] == s2[j++]) m++;
        else m = j = 0;
    }
    return m;
}

//Ex20
//esqueci-me do 2º if
int contaPal(char s[]){
    int t = 0;
    for(int i = 0; s[i]; i++){
        if(!isspace(s[i]) && !s[i+1]) t++;
        else if(!isspace(s[i]) && isspace(s[i+1])) t++;
    }
    return t;
}

//Ex22
int contida(char a[], char b[]){
    int c = 1;
    for(int i = 0; a[i] && c; i++){
        c = 0;
        for(int j = 0; b[j] && !c; j++){
            if(a[i] == b[j]) c = 1;
        }
    }
    return c;
}

//Ex23
//Deepseek adicionou o i--
int palindorome (char s[]){
    int i = strlen(s) - 1;
    int c = 1;
    for(int j = 0; j < i; j++, i--){
        if(s[j] != s[i]) c = 0;
    }
    return c;
}

//Ex26
//feito pelo Deepseek
void insere(int v[], int N, int x){
    int i = N - 1;
    while(i >= 0 && v[i] > x){
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = x;
}

//Ex29
int retiraNeg(int v[], int N){
    int w = 0;
    for(int i = 0; i < N; i++){
        if(v[i] >= 0) v[w++] = v[i];
    }
    return w;
}

//Ex30
//Deepseek corrigiu t inicial e retirou um ciclo (aumentou a eficiência)
int menosFreq (int v[], int N){
    int m = 0;
    int maior = N;
    int t = v[0];
    for(int i = 1; i < N, i++){
        if(v[i] == v[j]) m++;
        else{
            if(maior > m){
                t = v[i-1];
                maior = m;
            }
            m = 1;
        }
    }
    if(m < maior) t = v[N - 1];
    return t;
}

//Ex32
//foi adicionado o último else
int maxCresc(int v[], int N){
    int m = 0;
    int max = 0;
    for(int i = 0; i < N; i++){
        if(v[i] <= v[i+1]) m++;
        else{
            if(max < m) max = m;
        }
        else m = 1;
    }
    return max;
}

//Ex33
//corrigiu o argumento do m++
int elimRep(int v[], int n){
    int w = 0;
    int m = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n+1; j++){
            if(v[i] == v[j]) m++;
            else v[w++] = v[i];
        }
        n = n - w;
    }
    return m;
}

//Ex35 e 36
int comunsOrd(int a[], int na, int b[], int nb){
    int m = 0;
    for(int i = 0; i < na; i++){
        for(int j = 0; j < nb; j++){
            if(a[i] == b[j]) m++;
        }
    }
    return m;
}

//Ex35
int comunsOrd(int a[], int na, int b[], int nb){
    int ra, rb, comuns;
    rb = 0;
    ra = 0;
    comuns = 0;
    while(ra < na && rb < nb){
        if (a[ra] > b[rb]) rb++;
        else if(a[ra] == b[rb]){
            ra++;
            rb++;
            comuns++;
        }
        else ra++;
    }
    return comuns;
}

//Ex37
int minInd(int v[], int n){
    int m = 0;
    for(int i = 0; i < n; i++){
        if(v[m] > v[i]) m = v[i];
    }
    return m;
}

//Ex38
void somasAc(int v[], int Ac [], int N){
    for(int i = 0; i < N; i++){
        if(i == 0) Ac[0] = v[0];
        else Ac[i] = v[i] + Ac[i-1];
    }
}

//Ex39
//fui ver como se fazia
int triSup(int N, float m [N][N]){
    int x = 1;
    for(int i = 1; i < N && x; i++){
        for(int j = 0; j < i && x; j++){
            if(m[i][j] != 0) x = 0;
        }
    }
    return x;
}

//Ex48
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

//fui ver como se fazia
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N){
    int nmovX = final.x - inicial.x; // Número de movimentos horizontais necessários
    int nmovY = final.y - inicial.y; // Número de movimentos verticais necessários
    int totalMovimentos = abs(nmovX) + abs(nmovY);

    if(totalMovimentos > N) return -1;
    int i = 0;
    // Movimentos horizontais (Oeste ou Este)
    for(; i < abs(nmovX); i++){
        if(nmovX > 0) mov[i] = Este;
        else mov[i] = Oeste;
    }
    // Movimentos verticais (Norte ou Sul)
    for(; i < totalMovimentos; i++){
        if(nmovY > 0) mov[i] = Norte;
        else mov[i] = Sul;
    }
    return totalMovimentos;
}