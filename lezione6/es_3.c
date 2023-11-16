#include <stdlib.h>
#include <stdio.h>

/*
Scrivere un programma che richieda in ingresso i voti ottenuti agli esami da uno
studente (terminando quando viene inserito il voto -1) e scriva il voto minimo, il voto
massimo, la media e i voti più frequenti. Si tenga presente che possono essere
registrati anche voti insufficienti. 30 e lode = 31.
Per testare il programma,
creare un file di testo di nome voti.in contenente 20 interi compresi fra 0 e 30,
seguiti dal numero -1;
eseguire il programma redirigendo l’input su voti.in. */

#define DIM 32 // massimo numero di voti

// fare partire con ./es_3 < voti.in
int main(void) {
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

    if (max < 31) 
        printf("Voto minimo: %d\nVoto massimo: %d\n", min, max);
    else
        printf("Voto Minimo: %d\nVoto massimo: 30 e lode\n", min);
    printf("Media: %f\nVoti più frequenti: %d, %d\n", sum/((float) n), nums[most_freq_idx], nums[p_most_freq_idx]);

    return 0;
}