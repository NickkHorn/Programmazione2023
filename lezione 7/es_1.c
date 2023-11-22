#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int num, den;
} Frazione;

Frazione creaFrazione(int num, int den) {
    Frazione fraz = {num, den};
    return fraz;
}

Frazione otteniDaInput() {
    Frazione fraz;
    printf("Inserisci il numeratore e il denomatore (num den): ");
    scanf("%d %d", &fraz.num, &fraz.den);
    return fraz;
}

void stampaFrazionario(Frazione fraz) {
    printf("%d/%d\n", fraz.num, fraz.den);
}

void stampaDecimale(Frazione fraz) {
    printf("%f\n", (float) (fraz.num)/fraz.den);
}

int main(void) {
    Frazione fraz1 = creaFrazione(3, 4);
    Frazione fraz2 = otteniDaInput();

    stampaFrazionario(fraz1);
    stampaDecimale(fraz2);

    return 0;
}