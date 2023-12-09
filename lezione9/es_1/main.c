#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frazione.h"

typedef struct {
    Frazione fraz1, fraz2;
    char operatore;
} Operazione;

Frazione esegui(Operazione op) {
    Frazione res;
    switch (op.operatore) {
        case '+':
            somma(&res, op.fraz1, op.fraz2);
        break;
        case '-':
            differenza(&res, op.fraz1, op.fraz2);
        break;
        case '*':
            moltiplicazione(&res, op.fraz1, op.fraz2);
        break;
        case '/':
            divisione(&res, op.fraz1, op.fraz2);
        break;
        default:
            printf("Indice di operazione non valido!");
            exit(1);
        break;
    }
    return res;
}

int main(void) {
    Frazione fraz1, fraz2;
    char operatore; 
    otteniDaInput(&fraz1);
    scanf("%c", &operatore);
    otteniDaInput(&fraz2);
    
    Operazione op = {fraz1, fraz2, operatore};

    Frazione res = esegui(op);
    printf("Frazionario: ");
    stampaFrazionario(&res);
    printf("Valore: ");
    stampaDecimale(&res);
    return 0;
}