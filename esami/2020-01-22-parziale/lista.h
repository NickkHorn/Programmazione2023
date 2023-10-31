#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    char targa[8];
    int accessi;
    struct Nodo *next;
} nodo;

// QUESTI DUE IMPOSTANO AUTOMATICAMENTE GLI ACCESSI A 1
nodo* newList(char *targa);
void addToList(nodo *list, char *targa);

void printList(nodo *list);
void freeList(nodo *list);

nodo* get(nodo *lista, char *targa);
void scriviPrezzi(nodo *lista);


#endif