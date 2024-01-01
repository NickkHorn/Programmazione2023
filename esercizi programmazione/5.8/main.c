#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void chiediInInput(int *vet, int N) {
    for (int i = 0; i < N; i++)
        scanf("%d", &vet[i]);
}

void costruisciNuovoVettore(int *vet, int N, int *vet_new, int *new_effective_size) {
    int new_size = 0;
    for (int i = 0; i < N; i++) {
        if (vet[i] == 0) // se l'elemento è 0 non inserirlo
            continue;
        
        // controllo se l'elemento è già presente nel nuovo vettore
        bool present = false;
        for (int j = 0; j < new_size; j++) {
            if (vet_new[j] == vet[i]) {
                present = true;
                break;
            }
        }
        if (!present) { // se non lo è inseriscilo in quello nuovo
            vet_new[new_size] = vet[i];
            new_size++;
        }
    }
    *new_effective_size = new_size;
}

void stampa(int *vet, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main(void) {
    int N;
    printf("Quanti numeri vuoi utilizzare? ");
    scanf("%d", &N);
    while (N <= 0 || N > 20) {
        printf("Il numero deve essere compreso tra 1 e 20, estremi inclusi!\nQuanti numeri vuoi utilizzare? ");
        scanf("%d", &N);
    }
    int vet[N];
    chiediInInput(vet, N);
    
    int vet_new[N];
    int new_effective_size;
    costruisciNuovoVettore(vet, N, vet_new, &new_effective_size);
    stampa(vet_new, new_effective_size);    
    return 0;
}