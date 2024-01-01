#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LUNGHEZZA_MAX 24

int main(void) {
    char num_binario[LUNGHEZZA_MAX];
    printf("Inserisci il numero binario: ");
    scanf("%s", num_binario);
    
    bool valido = false;
    while (!valido) {
        valido = true;
        for (int i = 0; i < strlen(num_binario); i++) {
            if (num_binario[i] != '0' && num_binario[i] != '1') {
                valido = false;
                break;
            }
        }
        if (!valido) {
            printf("Il numero inserito non e' binario!\nReinserisci il numero: ");
            scanf("%s", num_binario);
        }
    }

    int n_bits = strlen(num_binario);
    int decimale = 0;
    for (int n = 0; n < n_bits; n++)
        decimale += (int) pow(2, n_bits-n-1)*(num_binario[n] - '0');
    
    printf("Decimale: %d", decimale);

    return 0;
}