#include <stdlib.h>
#include <stdio.h>

struct data {
    int giorno;
    int mese;
    int anno;
} oggi;

struct persona {
    char nome[20];
    struct data compleanno;
} pers;

int main(void) {
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