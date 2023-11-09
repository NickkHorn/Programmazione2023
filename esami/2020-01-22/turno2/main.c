#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

nodo* leggiFile(char *fpath);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("E' necessario specificare come argomento il percorso relativo del file con le vaccinazioni come segue: \"vaccinazioni <file>\"");
        return 1;
    }
    nodo* lista = leggiFile(argv[1]);
    printList(lista);
    freeList(lista);
    return 0;
}

nodo* leggiFile(char *fpath) {
    FILE *f = fopen(fpath, "rb");
    if (f == NULL) {
        printf("Errore nell'apertura del file!");
        return NULL;
    }

    nodo* lista = NULL;

    while (!feof(f)) {
        vaccinazione v;
        fread(&v, sizeof(v), 1, f);
        if (lista == NULL)
            lista = newList(&v);
        else
            segnaVaccinazione(lista, &v);
    }

    if (fclose(f) != 0)
        printf("Errore nella chiusura del file!");
    return lista;
}