#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Scrivere un programma che legga i caratteri scritti dall’utente su una riga di input e li
stampi sostituendo ogni lettera minuscola con la corrispondente maiuscola.
Ad esempio, se l’utente inserisce 26 Ottobre 2023, il programma deve stampare 26
OTTOBRE 2022. */

int main(void) {
    char ins[100];
    printf("Scrivi qualcosa: ");
    fgets(ins, sizeof(ins), stdin);
    for (int i = 0; i < strlen(ins); i++) {
        if (ins[i] >= 'a' && ins[i] <= 'z')
            ins[i] -= 32;
    }
    printf("%s", ins);
    return 0;
}