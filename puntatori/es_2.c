#include <stdlib.h>
#include <stdio.h>

void divisione(int *quoziente_dest, int *resto_dest, int a, int b) {
    *quoziente_dest = a/b;
    *resto_dest = a%b;
}

int main(void) {
    int a, b;
    printf("Inserisci due numeri: ");
    scanf("%d %d", &a, &b);
    int quoz, resto;
    divisione(&quoz, &resto, a, b);
    printf("Quoziente: %d\nResto: %d\n", quoz, resto);
    return 0;
}