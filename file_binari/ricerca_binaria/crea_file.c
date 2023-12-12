#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[21];
    char via[21];
    int n_civico;
} Persona;

Persona leggiPersona() {
    Persona pers;
    printf("\tInserisci il nome della persona: ");
    scanf("%s", pers.nome);
    printf("\tInserisci la via della persona: ");
    scanf("%s", pers.via);
    printf("\tInserisci il numero civico della persona: ");
    scanf("%d", &pers.n_civico);
    return pers;
}

void ordinaPerNome(Persona pers[], int num_people) {
    bool ordered = false;
    for (int n = 0; n < num_people-1; n++) {
        Persona curr = pers[n];
        int best_idx = n+1;
        for (int j = n+1; j < num_people; j++) {
            Persona checked = pers[j];

            // Se curr_best è dopo nell'alfabeto di checked
            if (strcmp(pers[best_idx].nome, checked.nome) > 0)
                best_idx = j;
        }
        // Scambia la persona con il primo nome in ordine alfabetico e pers[n]
        Persona temp = pers[best_idx];
        pers[best_idx] = curr;
        pers[n] = temp; 
    }

}

void scriviPersona(Persona *pers) {
    printf("Nome: %s\nVia: %s\nNumero civico: %d\n\n", pers->nome, pers->via, pers->n_civico);
}

int main(void) {
    int n_persone;
    printf("Inserisci il numero di persone che vuoi specificare: ");
    scanf("%d", &n_persone);
    if (n_persone < 0) {
        printf("Il numero di persone da inserire deve essere maggiore o uguale a 0!");
        exit(-1);
    }

    Persona persone[n_persone];

    FILE *f = fopen("INDIRIZZI.IND", "wb");
    int n = 0;
    for (int n = 0; n < n_persone; n++) {
        printf("Persona #%d:\n", n+1);
        persone[n] = leggiPersona();
    }

    fwrite(persone, sizeof(Persona), n_persone, f);
    fclose(f);
    
    ordinaPerNome(persone, n_persone);
    for (int i = 0; i < n_persone; i++)
        scriviPersona(&persone[i]);
    return 0;
}