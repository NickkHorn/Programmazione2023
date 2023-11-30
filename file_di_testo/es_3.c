#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 20
#define MAX_ADDRESS_SIZE 30
#define MAX_NUMBER_SIZE 15

int main(void) {
    char nome_cercato[MAX_NAME_SIZE];
    printf("Inserisci il nome di una persona: ");
    scanf("%s", nome_cercato);

    FILE *f = fopen("rubrica.txt", "r");
    if (f == NULL) {
        printf("Errore nell'apertura del file!");
        exit(-1);
    }

    while (!feof(f)) {
        char nome[MAX_NAME_SIZE], indirizzo[MAX_ADDRESS_SIZE], numero[MAX_NUMBER_SIZE];
        fscanf(f, "%s %s %s", nome, indirizzo, numero);
        if (strcmp(nome, nome_cercato) == 0) {
            printf("Indirizzo: %s\nNumero: %s\n", indirizzo, numero);
            break;
        }
    }

    if (fclose(f) != 0) {
        printf("Errore nella chiusura del file!");
        exit(-1);
    }

    return 0;
}