#include <stdio.h>
#include <stdlib.h>

//Ficha 2//

//Ex1
float multInt1 (int n, float m){
    int r = 0;

    while(n){
        r = r + m;
        n--;
    }

    return r;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int r = multInt1(n, m);

    printf("%d\n", r);

    return 0;
}

//Ex2
float multInt2 (int n, float m){
    int r = 0;

    while(n >= 1){
        if (n%2 != 0) r = r + m;
        m = 2*m;
        n = n/2;
    }

    return r;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int r = multInt2(n, m);

    printf("%d\n", r);

    return 0;
}

//Ex3
int mdc1 (int a, int b){
    int r = 1;
    int w;

    while((r <= a) && (r <= b)){
        if((a%r == 0) && (b%r == 0)) w = r;
        r++;
    }

    return w;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int r = mdc1(n, m);

    printf("%d\n", r);

    return 0;
}

//Ex4
int mdc2 (int a, int b){
    while(a > 0 && b > 0){
        if(a >= b) a = a - b;
        if(a < b) b = b - a;
    }

    if(a > 0) return a;
    else return b;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int r = mdc2(n, m);

    printf("%d\n", r);

    return 0;
}

//Ex5
//Feito pelo Deepseek
int mdc3 (int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int r = mdc3(n, m);

    printf("%d\n", r);

    return 0;
}

//Ex6
//a)
int fib1 (int n){
    if(n < 2) return 1;
    return (fib1(n-1) + fib1(n-2));
}

int main(){
    int n;
    scanf("%d", &n);

    int r = fib1(n);

    printf("%d\n", r);

    return 0;
}

//b)
int fib2 (int n){
    int a = 0;
    int b = 1;
    int r;

    while(n > 0){
        r = a + b;
        a = b;
        b = r;
        n--;
    }

    return r;
}

int main(){
    int n;
    scanf("%d", &n);

    int r = fib2(n);

    printf("%d\n", r);

    return 0;
}