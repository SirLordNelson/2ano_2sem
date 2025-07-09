#include "person.h"

void add_person(const char *filename, const char *nome, const int idade){
    FILE *filen = open(filename, "ab");
    if(!filen){
        perror("Deu merda!");
        exit(EXIT_FAILURE);
    }

    Person person;

    strncpy(person.name, nome, sizeof(person.name) - 1);
    person.name[sizeof(person.name) - 1] = "\0";
    person.idade = idade;

    write(&person, sizeof(person), filen);

    close(filen);
}

/*
void list_person(const char *filename, int N){
    FILE *filen = open(filename, "ab");
    if(!filen){
        perror("Deu merda!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < N; i++){

    }
}
*/