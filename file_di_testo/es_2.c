#include <stdlib.h>
#include <stdio.h>

#define MAX_READ_SIZE 1024

int main(void) {
    char f_name[100];
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", f_name);

    FILE *f = fopen(f_name, "r");
    if (f == NULL) {
        printf("Errore nell'apertura del file");
        exit(-1);
    }

    char contenuto_file[MAX_READ_SIZE];
    fread(contenuto_file, 1, MAX_READ_SIZE, f);
    printf("%s", contenuto_file);

    if (fclose(f) != 0) {
        printf("Errore nella chiusura del file!");
        exit(-1);
    }

    return 0;
}