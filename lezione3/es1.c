#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    printf("Divisori numero: ");

    for (int i = 1; i <= n; i++) {
        if (n%i == 0)
            printf("%d ", i);
    }

    return 0;
}