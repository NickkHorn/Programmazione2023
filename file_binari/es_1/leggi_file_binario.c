#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int stipendio;
} Impiegato;

int main(void) {
    FILE *f = fopen("STIPENDI.dat", "rb");
    if (f == NULL) {
        printf("Errore nell'apertura del file!");
        exit(-1);
    }

    Impiegato im;
    while (fread(&im, sizeof(Impiegato), 1, f) == 1)
        printf("%s: %d\n", im.nome, im.stipendio);

    if (fclose(f) != 0) {
        printf("Errore nell'apertura del file!");
        exit(-1);   
    }

    return 0;
}