#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int giorno;
    int mese;
    int anno;
} data;

typedef struct {
    char nome[20];
    data compleanno;
} persona;

int main(void) {
    data oggi;
    persona pers;
    printf("Inserisci la data di oggi (gg mm aa): ");
    scanf("%d %d %d", &oggi.giorno, &oggi.mese, &oggi.anno);
    printf("Inserire il proprio nome e la propria data di nascita (nome gg mm aa): ");
    scanf("%s %d %d %d", pers.nome, &pers.compleanno.giorno, &pers.compleanno.mese, &pers.compleanno.anno);

    if (oggi.giorno == pers.compleanno.giorno && oggi.mese == pers.compleanno.mese && oggi.anno == pers.compleanno.anno)
        printf("Auguri\n");
    else
        printf("Non e' il tuo compleanno\n");

    return 0;
}