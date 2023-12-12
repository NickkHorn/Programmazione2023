#ifndef LISTA_H
#define LISTA_H

#ifndef GRANDEZZA_MAX
#define GRANDEZZA_MAX 50
#endif

typedef struct {
    unsigned int n_elementi;
    int dati[50];
} Lista;

void inizializza(Lista *l);
void inserisci(Lista *l, int elemento);
void scrivi(Lista *l);

#endif