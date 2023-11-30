#include <stdlib.h>
#include <stdio.h>

#define MAX_DIM 1500

int main(void) {
    FILE *f = fopen("prova.txt", "w");
    if (f == NULL) {
        printf("Errore nell'apertura del file!");
        exit(-1);
    }

    char linea[MAX_DIM];
    char *terminatore = "FINE"; 
    fgets(linea, MAX_DIM, stdin);
    for (int i = 0; i < MAX_DIM-4; i++) {
        int j = i;
        for (; j < i+4; j++)
            if (linea[j] != terminatore[j-i])
                break;

        // il loop è con j arrivato alla fine, significa che c'è la parola FINE
        if (j == i+4)
            break;

        fputc(linea[i], f);
    }

    if (fclose(f) != 0) {
        printf("Errore nella chiusura del file!");
        exit(-1);
    }

    return 0;
}