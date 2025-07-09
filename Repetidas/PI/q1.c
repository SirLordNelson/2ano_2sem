#include <stdio.h>

int main(){
    long x = 28, y = 2;
    int v = 5;
    char d = 's';
    int max_distance = 0;
    int current_distance = 0;
    char current_direction = d;

    for(int t = 1; t <= 10000; t++){
        if(t % 3 == 0 && t % 5 == 0){
            if(d == 'n') d = 'e';
            else if(d == 'e') d = 's';
            else if(d == 's') d = 'w';
            else d = 'n';
            if(current_distance > max_distance) max_distance = current_distance;
            current_distance = 0;
            current_direction = d;
        }else if(t % 3 == 0) v += 2;
        else if(t % 5 == 0) v -= 1;
        else{
            if(d == 'n') y += v;
            else if(d == 'e') x += v;
            else if(d == 's') y -= v;
            else x -= v;

            if(d == current_direction) current_distance += v;
            else{
                if(current_distance > max_distance) max_distance = current_distance;
                current_distance = v;
                current_direction = d;
            }
        }
    }
    if(current_distance > max_distance) max_distance = current_distance;

    printf("Posição final: x = %ld, y = %ld, v = %d, d = %c\n", x, y, v, d);
    printf("Maior distância percorrida continuamente numa só direção: %d\n", max_distance);
    return 0;
}