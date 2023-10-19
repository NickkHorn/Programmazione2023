#include <stdlib.h>
#include <stdio.h>

int main() {
    int ip_max;
    printf("Inserisci il valore massimo dell'ipotenusa: ");
    scanf("%d", &ip_max);

    int n = 0;
    for (int d = 0; d < ip_max; d++) {
        for (int j = 0; d*d + j*j <= ip_max; j++) {
            printf("Terna pitagorica: %d %d %d\n", d, j, d*d + j*j);
            n++;
        }
    }

    printf("%d terne trovate nello stesso numero di calcoli", n);
    return 0;
}