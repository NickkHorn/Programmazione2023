#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista l;
    inizializza(&l);
    int n = 0;
    int curr;
    do {
        printf("Inserisci un numero positivo, o un numero <= di 0 per terminare: ");
        scanf("%d", &curr);
        inserisci(&l, curr);
        n++;
    } while (curr > 0 && n < GRANDEZZA_MAX);
    scrivi(&l);

    return 0;
}