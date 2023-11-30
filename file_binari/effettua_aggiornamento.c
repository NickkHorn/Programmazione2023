#include <stdlib.h> 
#include <stdio.h>

typedef struct {
    char nome[20];
    int stipendio;
} Impiegato;

unsigned int getByteSize(FILE *f) {
    unsigned int original_pos = ftell(f);
    fseek(f, 0, SEEK_END);
    unsigned int file_byte_length = ftell(f);
    fseek(f, original_pos, SEEK_SET);
    return file_byte_length;
} 

int main(void) {
    FILE *f = fopen("STIPENDI.dat", "r+b");
    if (f == NULL) {
        printf("Errore nell'apertura del file!");
        exit(-1);
    }

    unsigned int num_employees_recorded = getByteSize(f)/sizeof(Impiegato); 
    unsigned int n_loaded = 0;
    Impiegato im;
    while (fread(&im, sizeof(Impiegato), 1, f) == 1) {
        if (im.stipendio < 1000) {
            im.stipendio = (int) (im.stipendio * 1.1f);
            fseek(f, ftell(f) - sizeof(Impiegato), SEEK_SET);
            fwrite(&im, sizeof(Impiegato), 1, f);
            fflush(f);
        }
    }

    if (fclose(f) != 0) {
        printf("Errore nella chiusura del file!");
        exit(-1);
    }

    return 0;
}