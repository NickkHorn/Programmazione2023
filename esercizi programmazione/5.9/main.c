#include <stdlib.h>
#include <stdio.h>

#define max(a,b) ((a>=b)?a:b)

void ottieniLunghezze(int *N1, int *N2) {
    printf("Inserire la lunghezza del primo vettore: ");
    scanf("%d", N1);
    while (*N1 <= 0 || *N1 > 30) {
        printf("La lunghezza dei vettori deve essere compresa tra 1 e 30 (estremi inclusi!)\nInserire la lunghezza del primo vettore: ");
        scanf("%d", N1);
    }   
    printf("Inserire la lunghezza del secondo vettore: ");
    scanf("%d", N2);
    while (*N2 <= 0 || *N2 > 30) {
        printf("La lunghezza dei vettori deve essere compresa tra 1 e 30 (estremi inclusi!)\nInserire la lunghezza del primo vettore: ");
        scanf("%d", N2);
    }
}

void leggiVettore(int *vet, int size) {
    for (int n = 0; n < size; n++)
        scanf("%d", &vet[n]);
}

void stampa(int *vet, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main(void) {
    int N1, N2;
    ottieniLunghezze(&N1, &N2);
    int vet1[N1], vet2[N2];
    printf("Inserire gli elementi del primo vettore:\n");
    leggiVettore(vet1, N1);
    printf("Inserire gli elementi del secondo vettore:\n");
    leggiVettore(vet2, N2);

    int intersezione[max(N1, N2)];
    int effective_size = 0;
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            if (vet1[i] == vet2[j]) {
                intersezione[effective_size] = vet1[i];
                effective_size++;
                break;
            }
        }
    }

    stampa(intersezione, effective_size);

    return 0;
}