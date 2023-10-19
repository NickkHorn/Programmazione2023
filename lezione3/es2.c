#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Scrivere un programma che determini se un numero inserito dall'utente è primo

int main() {
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    bool primo = true;

    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            primo = false;
            break;
        }
    }
    
    if (primo || n == 2)
        printf("Il numero inserito e' primo!");
    else
        printf("Il numero inserito non e' primo!");

    return 0;
}