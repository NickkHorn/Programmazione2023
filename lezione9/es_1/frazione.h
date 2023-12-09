#ifndef FRAZIONE_H
#define FRAZIONE_H

typedef struct {
    int num, den;
} Frazione;

void semplifica(Frazione *fraz);
void creaFrazione(Frazione *dest, int num, int den);
void otteniDaInput(Frazione *fraz);
void stampaFrazionario(Frazione *fraz);
void stampaDecimale(Frazione *fraz);
void somma(Frazione *dest, Frazione fraz1, Frazione fraz2);
void differenza(Frazione *dest, Frazione fraz1, Frazione fraz2);
void moltiplicazione(Frazione *dest, Frazione fraz1, Frazione fraz2);
void divisione(Frazione *dest, Frazione fraz1, Frazione fraz2);


#endif