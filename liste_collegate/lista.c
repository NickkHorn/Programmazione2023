#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Lista creaLista(int dato) {
    Nodo* testa = malloc(sizeof *testa);
    testa->dato = dato;
    testa->next = NULL;
    return testa;
}

void inserisciElemento(Lista l, int dato) {
    Nodo* curr = l;
    while (curr->next != NULL)
        curr = curr->next;
    
    Nodo* nuovo_el = malloc(sizeof *nuovo_el);
    nuovo_el->dato = dato;
    nuovo_el->next = NULL;
    curr->next = nuovo_el;
}

void libera(Lista l) {
    Nodo* curr = l;
    while (curr != NULL) {
        Nodo* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int massimo(Lista l) {
    if (l == NULL) {
        printf("Errore: impossibile trovare il valore massimo di una lista vuota!");
        return -1;
    }

    Nodo *curr = l;
    int curr_max = l->dato;
    while (curr != NULL) {
        curr = curr->next;
        if (curr->dato >= curr_max)
            curr_max = curr->dato;
    }
    return curr_max;    
}

void stampa(Lista l) {
    Nodo *curr = l;
    int n = 0;
    while (curr != NULL) {
        printf("Elemento #%d: %d\n", n, curr->dato);
        curr = curr->next;
        n++;
    }
}

void azzera(Lista l) {
    Nodo *curr = l;
    while (curr != NULL) {
        curr->dato = 0;
        curr = curr->next;
    }
}

unsigned int lunghezza(Lista l) {
    Nodo *curr = l;
    unsigned int n = 0;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }
    return n;
}