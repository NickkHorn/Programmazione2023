#include <stdlib.h>
#include <stdio.h>

void stampa(int *vet, int size) {
    printf("Vettore: ");
    for (int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

void leftShift(int *vet, int size) {
    for (int i = 0; i < size-1; i++)
        vet[i] = vet[i+1];
    vet[size-1] = 0;
}

void rightShift(int *vet, int size) {
    for (int i = size-1; i > 0; i--)
        vet[i] = vet[i-1];
    vet[0] = 0;
}

int main(void) {
    int n;
    printf("Quanti numeri vorresti inserire in input: ");
    scanf("%d", &n);

    while (n <= 0) {
        printf("Il numero dato deve essere positivo, riprova: ");
        scanf("%d", &n);
    }

    int vet[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    stampa(vet, n);
    leftShift(vet, n);
    stampa(vet, n);
    rightShift(vet, n);
    stampa(vet, n);

    return 0;
}