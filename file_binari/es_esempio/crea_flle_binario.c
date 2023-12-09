#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char nome[31]; // 31 perchè sono 30 caratteri + il terminatore
    char cognome[31];
    char sesso;
    int anno_nascita;
} Persona;

char toLower(char x) {
    // x non è maiuscola
    if (x <  65 || x > 90)
        return x;

    return x + 32;
} 

Persona leggiel() {
    Persona pers;
    printf("\tInserisci il nome della persona: ");
    scanf("%s", pers.nome);
    printf("\tInserisci il conome della persona: ");
    scanf("%s", pers.cognome);
    printf("\tInserisci il sesso della persona (m/f): ");
    char sesso;
    scanf(" %c", &sesso);
    pers.sesso = toLower(sesso);
    printf("\tInserisci l'anno di nascita della persona: ");
    scanf("%d", &pers.anno_nascita);
    return pers;
}

int main(void) {
    FILE *f = fopen("people.dat", "wb");
    int n = 1;

    bool loading = true;
    while (loading) { 
        printf("\n\nPersona #%d:\n", n);
        Persona pers = leggiel();
        printf("Vuoi caricare un'altra persona? (s/n)? ");
        char in;
        scanf(" %c", &in);
        loading = (toLower(in) == 's');
        fwrite(&pers, sizeof(Persona), 1, f);
        n++;
    }

    fclose(f);
    return 0;
}