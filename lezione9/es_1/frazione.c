#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frazione.h"

int min(int a, int b) {
    return (a <= b)?a:b;
}

int MCM(int a, int b) {
    int _min = min(a,b);
    int _max = a+b-_min;
    int mult = 1; // moltiplicatore
    // mult*_min sarà sicuramente un moltiplicatore di _min essendo mult intero, perché sia minimo comune multiplo
    // devo solo controllare se è anche un multiplo di _max
    while ((mult*_min)%_max != 0)
        mult++;
    return _min*mult;
}

void semplifica(Frazione *fraz) {
    bool found = true;    
    while (found) {
        found = false;
        for (int n = 2; n <= min(fraz->num, fraz->den); n++) {
            if (fraz->num % n == 0 && fraz->den % n == 0) {
                fraz->num /= n;
                fraz->den /= n;
                found = true;
                break;
            }
        }
    }
}

void creaFrazione(Frazione *dest, int num, int den) {
    if (den == 0) {
        printf("Errore: una frazione non può avere denominatore pari a 0!");
        exit(1);
    }

    dest->num = num;
    dest->den = den;
    semplifica(dest);
}

void otteniDaInput(Frazione *fraz) {
    printf("Inserisci una frazione (<num>/<den>): ");
    scanf("%d/%d", &fraz->num, &fraz->den);
    if (fraz->den == 0) {
        printf("Errore: Il denominatore non può essere 0!");
        exit(1);
    }
    semplifica(fraz);
}

void stampaFrazionario(Frazione *fraz) {
    printf("%d/%d\n", fraz->num, fraz->den);
}

void stampaDecimale(Frazione *fraz) {
    printf("%f\n", (float) (fraz->num)/fraz->den);
}

void somma(Frazione *dest, Frazione fraz1, Frazione fraz2) {
    dest->den = MCM(fraz1.den, fraz2.den);
    dest->num = fraz1.num*(dest->den/fraz1.den)+fraz2.num*(dest->den/fraz2.den);
    semplifica(dest);
}

void differenza(Frazione *dest, Frazione fraz1, Frazione fraz2) {
    dest->den = MCM(fraz1.den, fraz2.den);
    dest->num = fraz1.num*(dest->den/fraz1.den)-fraz2.num*(dest->den/fraz2.den);
    semplifica(dest);
}

void moltiplicazione(Frazione *dest, Frazione fraz1, Frazione fraz2) {
    dest->num = fraz1.num * fraz2.num;
    dest->den = fraz1.den * fraz2.den;
    semplifica(dest);
}

void divisione(Frazione *dest, Frazione fraz1, Frazione fraz2) {
    if (fraz2.num == 0) {
        printf("Errore: impossibile dividere per 0");
        exit(1);
    }

    dest->num = fraz1.num*fraz2.den;
    dest->den = fraz1.den*fraz2.num;
    semplifica(dest);
}