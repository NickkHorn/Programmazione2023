#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "parola.h"

// la parola più lunga è "contemporaneamente", con 18 caratteri, + 1 di terminatore diventano 19
#define MAX_PAROLA_SIZE 20
#define NUM_PAROLE 60453

void parsaRiga(FILE *src, char *dest) {
    int n = 0;
    do {
        dest[n] = fgetc(src);
        n++;
    } while (!feof(src) && dest[n-1] != '\n');
    dest[n-1] = '\0';
}

void ottieniParola(char *dest) {
    FILE *src = fopen("words_italian.txt", "r");
    if (src == NULL) {
        printf("Errore nell'apertura del file \"words_italian.txt\"");
        exit(-1);
    }

    // rand arriva massimo a 32767, ma il vettore contiene poco meno del doppio degli elementi
    // moltiplicando per due prenderei solo indici pari, dunque devo sommare due chiamate a rand()
    int parola_idx = (rand()+rand())%NUM_PAROLE;
    for (int i = 0; i < parola_idx; i++) 
        parsaRiga(src, dest);

    parsaRiga(src, dest);
    fclose(src);
}

int main(void) {
    srand(time(NULL));
    printf("Benvenuto al gioco dell'impiccato! Lasciami scegliere una parola...\n");
    char parola[MAX_PAROLA_SIZE];
    ottieniParola(parola);
    Parola p = inizializza(parola);
    printf("%s\n", p.testo);
    int vite = 5;
    while (vite > 0) {
        scriviInOutput(&p);
        printf("Inserisci una lettera: ");
        char in; // lettera inserita dal giocatore
        scanf(" %c", &in);
        bool corretta = processaLettera(&p, in);
        if (!corretta)
            vite--;
        else if (indovinata(&p)) {
            printf("Congratulazioni! Hai indovinato la parola!");
            exit(-1);
        }
    }
    printf("Mi spiace, hai perso... la parola era %s\n", p.testo);
    return 0;
}