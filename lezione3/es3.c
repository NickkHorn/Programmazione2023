#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool primo(long int n) {
    for (long int i = 2; i*i <= n; i++)
        if (n%i == 0) 
            return false;
    return true;
}

int main() {
    long int n;
    printf("Inserisci un numero: ");
    scanf("%ld", &n);

    for (int i = 1; i <= n/2; i++) {
        if (n%i == 0 && primo(i))
            printf("Divisore primo: %d\n", i);
    }
    
    return 0;
}