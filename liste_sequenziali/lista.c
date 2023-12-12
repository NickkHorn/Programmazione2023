#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void inizializza(Lista *l) {
    l->n_elementi = 0;
}

void inserisci(Lista *l, int elemento) {
    if (l->n_elementi >= GRANDEZZA_MAX) {
        printf("La lista è piena!");
        return;
    }

    l->dati[l->n_elementi] = elemento;
    l->n_elementi++;
}

void scrivi(Lista *l) {
    for (int i = 0; i < l->n_elementi; i++)
        printf("Elemento #%d: %d\n", i+1, l->dati[i]);
    printf("\n");
}