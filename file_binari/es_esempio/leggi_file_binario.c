#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char nome[31]; // 31 perchè sono 30 caratteri + il terminatore
    char cognome[31];
    char sesso;
    int anno_nascita;
} Persona;

unsigned int getByteSize(FILE *f) {
    long original_pos = ftell(f);
    fseek(f, 0, SEEK_END);
    unsigned int f_size = ftell(f);
    fseek(f, original_pos, SEEK_SET);
    return f_size;
}

void scriviPersona(Persona *pers) {
    printf("Nome: %s\nCognome: %s\nSesso: %c\nEta': %d\n\n", pers->nome, pers->cognome, pers->sesso, pers->anno_nascita);
}

int main(void) {
    FILE *f = fopen("people.dat", "rb");
    const unsigned int num_people = getByteSize(f)/sizeof(Persona);
    Persona persone[num_people];

    fread(persone, sizeof(Persona), num_people, f);
    for (int i = 0; i < num_people; i++)
        scriviPersona(&persone[i]);

    fclose(f);
    return 0;
}