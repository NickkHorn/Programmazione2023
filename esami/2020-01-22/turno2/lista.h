#ifndef LISTA_H
#define LISTA_H
#include "stdbool.h"

typedef struct Vaccinazione {
    int n_chip;
    char v_type;
} vaccinazione;

typedef struct Nodo {
    int n_chip;
    bool vaccinazioni[3]; // 0 -> C, 1 -> E, 2 -> P
    struct Nodo *next;
} nodo;

// passato per riferimento così la macchina non fa una copia ed + leggermente più veloce
nodo* newList(vaccinazione *v);
nodo* get(nodo* list, int n_chip);
void segnaVaccinazione(nodo* list, vaccinazione *v);
void printList(nodo* list);
void freeList(nodo *list);

#endif