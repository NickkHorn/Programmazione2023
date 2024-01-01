#ifndef LISTA_H
#define LISTA_H

typedef struct nodo {
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

Lista creaLista(int dato);
void inserisciElemento(Lista l, int el);
void stampa(Lista l);
void azzera(Lista l);
void libera(Lista l);
unsigned int lunghezza(Lista l);
int massimo(Lista l);

#endif