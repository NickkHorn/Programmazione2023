#include <stdlib.h>
#include <stdio.h>

/*
Scrivere un programma che richieda in ingresso un massimo di DIM (dove DIM è una
macro) numeri interi non negativi (fermandosi quando viene inserito un numero
negativo) e stampi il numero minimo, il numero massimo, la media aritmetica e i
numeri più frequenti.
Per testare il programma,
creare un file di testo di nome numeri.in contenente 30 interi casuali compresi fra 0 e
99, seguiti dal numero -1;
eseguire il programma redirigendo l’input su numeri.in. */

#define DIM 100

// fare partire con ./es_2 < numeri.in
int main(void) {
    /*int DIM;
    //printf("Inserisci il numero massimo di numeri in input: ");
    //scanf("%d", &DIM);
    */

    // nums tiene tutti i numeri inseriti, freqs tiene per ogni index i l'ammontare di volte che nums[i] è apparso
    int nums[DIM], freqs[DIM];
    for (int i = 0; i < DIM; i++) freqs[i] = 0;
    int most_freq_idx = 0, p_most_freq_idx = 0;
    int in = 0, min = 1e5, max = 0, sum = 0;
    int n;
    for (n = 0; n < DIM; n++) {
        scanf("%d", &in);
        if (in < 0)
            break;
        nums[n] = in;
        freqs[n]++;
        for (int j = 0; j < DIM; j++) {
            if (nums[j] == in) {
                freqs[j]++;
                if (freqs[j] > freqs[most_freq_idx]) { // più frequente del più grande numero più frequente
                    p_most_freq_idx = most_freq_idx;
                    most_freq_idx = j;
                }
                else if (freqs[j] > freqs[p_most_freq_idx]) // più frequente del più grande numero più frequente
                    p_most_freq_idx = j;
            }
        }
        sum += in;
        if (in > max)
            max = in;
        if (in < min)
            min = in;
    }

    printf("Minimo: %d\nMassimo: %d\nMedia aritmetica: %f\nNumeri più frequenti: %d, %d\n", min, max, sum/((float) n), nums[most_freq_idx], nums[p_most_freq_idx]);

    return 0;
}