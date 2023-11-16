#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    char s1[100], s2[100];
    printf("Inserisci due stringhe: ");
    scanf("%s %s", s1, s2);

    // se l'indice a cui sono arrivato è parte di una istanza di s2 in s1
    int subword_idx = 0;
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] == s2[subword_idx]) {
            subword_idx++;
            if (subword_idx == strlen(s2)) {
                printf("la parola %s appare in %s\n", s2, s1);
                exit(0);
            }
        } else 
            subword_idx = 0;
    }

    printf("la parola %s non appare in %s\n", s2, s1);


    return 0;
}