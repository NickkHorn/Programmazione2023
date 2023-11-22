#include <stdlib.h>
#include <stdio.h>

#define DIM 10

int main(void) {
    int ins[DIM];
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    for (int i = 0; i < DIM; i++) {
        ins[i] = n+i+1;
        printf("%d\n", ins[i]);
    }
    return 0;
}