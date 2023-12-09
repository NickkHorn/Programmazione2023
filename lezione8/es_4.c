#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define DIM 60455

void parolaCasuale(char parole[DIM][31], char *parola) {
    int index = rand()%DIM;
    strcpy(parola, parole[index]);
}

int main(void) {
    srand(time(NULL));
    char parole[DIM][31];
    FILE *f = fopen("words_italian.txt", "r");
    if (f == NULL) {
        printf("Errore nell'apertura del file");
        exit(-1);
    }
    printf("Caricamento delle parole iniziato...\n");
    int n = 0;
    while (!feof(f)) {
        fscanf(f, "%s", parole[n]);
        n++;
    }
    fclose(f);
    printf("Parole caricate!\n");
    char parola[31];
    parolaCasuale(parole, parola);
    printf("Parola casuale: %s", parola);
    return 0;
}