#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

persona* creaPersona(char *codice_fiscale);
// ritorna una lista con tutte le persone salvate nel file, le attività usate sono inizializzate a 0
node* caricaDati(char *bin_fpath);
void controllaIngressi(char *ingressi_fpath, node *lista);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Per favore inserire gli argomenti necessari, prova con: \"persona.o <file codici fiscali> <file ingressi>\"");
        return 1;
    }

    char *bin_fpath = argv[1];
    char *ingressi_fpath = argv[2];
    node *lista = caricaDati(bin_fpath);
    controllaIngressi(ingressi_fpath, lista);
    printList(lista);

    freeList(lista);
    return 0;
}

persona *creaPersona(char *codice_fiscale) {
    persona *pers = malloc(sizeof *pers);
    strcpy(pers->codice_fiscale, codice_fiscale);
    for (int i = 0; i < 3; i++)
        pers->attivita[i] = 4;
    pers->negati = 0;
    return pers;
}

node *caricaDati(char *bin_fpath) {
    FILE *f = fopen(bin_fpath, "rb");
    if (f == NULL) {
        printf("Non è stato possibile aprire il file binario specificato!");
        return NULL;
    }
    node *list = NULL;
    fseek(f, 0, SEEK_END);
    unsigned int num_persone = ftell(f)/LUNGHEZZA_CODICE_FISCALE;
    fseek(f, 0, SEEK_SET);

    int n = 0;

    while (n < num_persone) {
        char codice_fiscale[LUNGHEZZA_CODICE_FISCALE];
        fread(codice_fiscale, LUNGHEZZA_CODICE_FISCALE, 1, f);
        persona *pers = creaPersona(codice_fiscale);
        n++;

        if (list == NULL)
            list = newList(pers);
        else
            appendToList(list, pers);
    }

    if (fclose(f) > 0)
        printf("Errore: impossibile chiudere la stream file binario!");

    return list;
}

void controllaIngressi(char *ingressi_fpath, node* lista) {
    FILE *f = fopen(ingressi_fpath, "r");
    if (f == NULL) {
        printf("Non è stato possibile aprire il file degli ingressi specificato!");
        return;
    }

    while (!feof(f)) {
        char codice_fiscale[LUNGHEZZA_CODICE_FISCALE];
        int attivita;
        
        fscanf(f, "%s %i", codice_fiscale, &attivita);
        persona *pers = getPersona(codice_fiscale, lista);
        if (pers == NULL) {
            printf("Errore: codice fiscale non riconosciuto nel file degli ingressi specificato, l'entrata sara' ignorata");
            continue;
        }
        if (pers->attivita[attivita-1] > 0 && pers->negati < 3)
            pers->attivita[attivita-1]--;
        else {
            printf("Codice fiscale: %s, attivita' %d: Accesso negato\n", pers->codice_fiscale, attivita);
            pers->negati++;
        }
    }

    if (fclose(f) > 0)
        printf("Errore: impossibile chiudere la stream file degli ingressi!");
}