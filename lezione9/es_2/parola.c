#include <string.h>
#include "parola.h"

void scriviInOutput(Parola *parola) {
    printf("Parola: ");
    for (int i = 0; i < strlen(parola->testo); i++) {
        if (!parola->indovinate[i])
            printf("_");
        else
            printf("%c", parola->testo[i]);
    }
    printf("\n");
}

Parola inizializza(char *testo) {
    Parola p;
    strcpy(p.testo, testo);
    for (int i = 0; i < strlen(testo); i++)
        p.indovinate[i] = false;
    return p;
}

bool processaLettera(Parola *parola, char lettera) {
    bool presente = false;    
    for (int i = 0; i < strlen(parola->testo); i++) {
        if (parola->testo[i] == lettera) {
            if (parola->indovinate[i]) {
                printf("Hai già indovinato quella lettera!");
                return true;
            }

            presente = true;
            parola->indovinate[i] = true;
        }
    }
    return presente;
}

bool indovinata(Parola *parola) {
    for (int i = 0; i < strlen(parola->testo); i++)
        if (!parola->indovinate[i])
            return false;
    return true;
}