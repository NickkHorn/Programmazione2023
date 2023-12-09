#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int stipendio;
} Impiegato;

int main(void) {
    FILE *f = fopen("STIPENDI.dat", "wb");
    if (f == NULL) {
        printf("Errore nell'apertura del file!");
        exit(-1);
    }

    Impiegato impiegati[3] = {
        { "Rossi", 1600 },
        { "Bianchi", 800 },
        { "Verdi", 1100 }
    };

    fwrite(impiegati, sizeof(Impiegato), 3, f);

    if (fclose(f) != 0) {
        printf("Errore nell'apertura del file!");
        exit(-1);   
    }

    return 0;
}