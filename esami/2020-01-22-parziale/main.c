#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include <string.h>

nodo* caricaDati(char *fpath);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Per favore specificare il percorso del file binario come segue:\nmain.exe <fileBinario>");
        return 1;
    }
    nodo *lista = caricaDati(argv[1]);
    if (lista == NULL) {
        printf("Errore riscontrato nella lettura del file!\n");
        return 0;
    }

    scriviPrezzi(lista);

    freeList(lista);
    return 0;
}

nodo* caricaDati(char *fpath) {
    FILE *f = fopen(fpath, "rb");
    if (f == NULL) {
        printf("Errore nell'apertura del file!\n");
        return NULL;
    }
    
    nodo *lista = NULL;
    fseek(f, 0, SEEK_END);
    long unsigned int length = ftell(f);
    fseek(f, 0, SEEK_SET);

    // lunghezza di uno degli accessi in bytes
    const unsigned int entry_length = sizeof(float) + sizeof(char)*8;
    unsigned int read = 0; // numero di bytes letti fino ad'ora

    char ultime_targhe[3][8];

    while (read < length) {
        char targa[8];
        float durata;
        fread(targa, sizeof(char)*8, 1, f);
        // serve per far andare avanti il puntatore nella lettura del file
        fread(&durata, sizeof(float), 1, f);
        read += entry_length;

        int entries_rimaste = (length-read)/entry_length;
        if (entries_rimaste < 3) // 2/1/0
            strcpy(ultime_targhe[2-entries_rimaste], targa);

        if (lista == NULL)
            lista = newList(targa);
        else {
            nodo *veicolo = get(lista, targa);
            if (veicolo == NULL)
                addToList(lista, targa);
            else
                veicolo->accessi++;
        }
    }


    if (fclose(f) != 0) {
        printf("Errore nella chiusura del file!\n");
        return NULL;
    }

    FILE *f_out = fopen("ultime3.txt", "w");

    for (int i = 0; i < 3; i++)
        fprintf(f_out, "%s\n", ultime_targhe[i]);

    fclose(f_out);

    return lista;
}