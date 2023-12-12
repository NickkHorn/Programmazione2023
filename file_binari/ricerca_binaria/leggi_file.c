#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[21];
    char via[21];
    int n_civico;
} Persona;

unsigned int getByteSize(FILE *f) {
    long original_pos = ftell(f);
    fseek(f, 0, SEEK_END);
    unsigned int f_size = ftell(f);
    fseek(f, original_pos, SEEK_SET);
    return f_size;
}

void scriviPersona(Persona *pers) {
    printf("Nome: %s\nVia: %s\nNumero civico: %d\n\n", pers->nome, pers->via, pers->n_civico);
}

int main(void) {
    FILE *f = fopen("INDIRIZZI.IND", "rb");
    const unsigned int num_persone = getByteSize(f)/sizeof(Persona);    
    printf("Inserisci il nome della persona: ");
    char nome[21];
    scanf("%s", nome);

    int curr = -1;
    int low = 0, high = num_persone-1;
    while (true) {
        int curr = (low+high)/2;
        // se per esempio low = 1 e high = 2 allora per la divisione intera (low+high)/2 fa 1 e dunque curr = low
        if (curr == low)
            curr = high;

        fseek(f, curr*sizeof(Persona), SEEK_SET);
        Persona pers;
        fread(&pers, sizeof(Persona), 1, f);
        // se la persona analizzata è più avanti nell'alfabeto controlla l'intervallo [low, curr)
        if (strcmp(pers.nome, nome) > 0)
            high = curr;
        // se la persona analizzata è più indietro nell'alfabeto controlla l'intervallo (curr, high]
        else if (strcmp(pers.nome, nome) < 0)
            low = curr;
        // se la persona è quella che cerchiamo
        else {
            scriviPersona(&pers);
            break;
        }
    }


    fclose(f);
    return 0;
}