#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define min(a,b) ((a<=b)?a:b)

typedef struct {
    int num, den;
} Frazione;

Frazione semplifica(Frazione fraz) {
    bool found = true;    
    while (found) {
        found = false;
        for (int n = 2; n <= min(fraz.num, fraz.den); n++) {
            if (fraz.num % n == 0 && fraz.den % n == 0) {
                fraz.num /= n;
                fraz.den /= n;
                found = true;
                break;
            }
        }
    }
    return fraz;
}

Frazione creaFrazione(int num, int den) {
    Frazione fraz = {num, den};
    fraz = semplifica(fraz);
    return fraz;
}

Frazione otteniDaInput() {
    Frazione fraz;
    printf("Inserisci il numeratore e il denomatore (num den): ");
    scanf("%d %d", &fraz.num, &fraz.den);
    fraz = semplifica(fraz);
    return fraz;
}

void stampaFrazionario(Frazione fraz) {
    printf("%d/%d\n", fraz.num, fraz.den);
}

void stampaDecimale(Frazione fraz) {
    printf("%f\n", (float) (fraz.num)/fraz.den);
}

Frazione somma(Frazione fraz1, Frazione fraz2) {
    Frazione res = {fraz1.num+fraz2.num, fraz1.den+fraz2.den};
    return semplifica(res);
}

Frazione differenza(Frazione fraz1, Frazione fraz2) {
    Frazione res = {fraz1.num-fraz2.num, fraz1.den-fraz2.den};
    return semplifica(res);
}

Frazione moltiplicazione(Frazione fraz1, Frazione fraz2) {
    Frazione res = {fraz1.num*fraz2.num, fraz1.den*fraz2.den};
    return semplifica(res);
}

Frazione divisione(Frazione fraz1, Frazione fraz2) {
    Frazione res = {fraz1.num*fraz2.den, fraz1.den*fraz2.num};
    return semplifica(res);
}

int main(void) {
    printf("Prima frazione:\n\t");
    Frazione fraz1 = otteniDaInput();
    printf("Seconda frazione:\n\t");
    Frazione fraz2 = otteniDaInput();

    printf("Operazioni possibili:\n\t1 - Somma\n\t2 - Differenza\n\t3 - Moltiplicazione\n\t4 - Divisione\nInserire il numero dell'operazione desiderata: ");
    int op;
    scanf("%d", &op);
    
    Frazione res;
    switch (op) {
        case 1:
            res = somma(fraz1, fraz2);
        break;
        case 2:
            res = differenza(fraz1, fraz2);
        break;
        case 3:
            res = moltiplicazione(fraz1, fraz2);
        break;
        case 4:
            res = divisione(fraz1, fraz2);
        break;
        default:
            printf("Indice di operazione non valido!");
            exit(1);
        break;
    }
    printf("Frazionario: ");
    stampaFrazionario(res);
    printf("Valore: ");
    stampaDecimale(res);

    return 0;
}