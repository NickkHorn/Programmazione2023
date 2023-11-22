#include <stdlib.h>
#include <stdio.h>

struct orario {
    int ora;
    int minuti;
} ora_iniziale, ora_finale;

int main(void) {
    printf("Inserisci l'ora iniziale: ");
    scanf("%d %d", &ora_iniziale.ora, &ora_iniziale.minuti);
    if (ora_iniziale.ora < 0 || ora_iniziale.minuti < 0) {
        printf("L'ora e i minuti non possono essere negativi!");
        exit(1);
    }

    printf("Inserisci l'ora finale: ");
    scanf("%d %d", &ora_finale.ora, &ora_finale.minuti);

    if (ora_finale.ora < 0 || ora_finale.minuti < 0) {
        printf("L'ora e i minuti non possono essere negativi!");
        exit(1);
    }

    int ore_trascorse = ora_finale.ora - ora_iniziale.ora;
    int minuti_trascorsi = ora_finale.minuti - ora_iniziale.minuti;
    if (minuti_trascorsi < 0) {
        ore_trascorse--;
        minuti_trascorsi += 60;
    }

    printf("differenza: %d:%d\n", ore_trascorse, minuti_trascorsi);

    return 0;
}