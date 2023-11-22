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

int main(void) {
    Frazione fraz1 = creaFrazione(3, 6);
    Frazione fraz2 = otteniDaInput();

    stampaDecimale(fraz1);
    stampaFrazionario(fraz2);

    return 0;
}