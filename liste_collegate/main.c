#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista l = creaLista(5);
    inserisciElemento(l, 10);
    inserisciElemento(l, 9);
    printf("Prima dell'azzeramento: \n");
    stampa(l);
    azzera(l);
    printf("\nDopo l'azzeramento: \n");
    stampa(l);
    libera(l);

    l = creaLista(5);
    inserisciElemento(l, 10);
    inserisciElemento(l, 9);
    printf("Lista ricreata! Lunghezza: %d", lunghezza(l));
    libera(l);
    return 0;
}