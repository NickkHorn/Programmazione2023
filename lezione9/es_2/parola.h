#include <stdio.h>  
#include <stdbool.h>
#ifndef PAROLA_H
#define PAROLA_H

#ifndef MAX_PAROLA_SIZE
#define MAX_PAROLA_SIZE 20
#endif

typedef struct {
    char testo[MAX_PAROLA_SIZE];
    bool indovinate[MAX_PAROLA_SIZE]; // array di bool che specifica se sono stati indovinate le lettere
} Parola;

Parola inizializza(char *testo);
void scriviInOutput(Parola *parola);
bool indovinata(Parola *parola);
bool processaLettera(Parola *parola, char lettera); // ritorna se la lettera era presente nella paorla oppure no

#endif