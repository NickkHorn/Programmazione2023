#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Scrivere un programma che scriva in uscita la fattorizzazione in numeri primi del
numero ricevuto in ingresso.
Ad esempio: se riceve 60, dovrà scrivere (in qualche formato) 22 ˆ 3 ˆ 5.
*/

int main() {
    int n;
    printf("Inserire un numero: ");
    scanf("%d", &n);

    for (int i = 2; i <= n/2; i++) {
        int num_exp = 0;
        while (n%i == 0) {
            n /= i;
            num_exp++;
        }
        if (num_exp > 1) {
            printf("%d^%d x ", i, num_exp);
            i = 2;
        }
        else if (num_exp == 1) {
            printf("%d x ", i);
            i = 2;
        }
    }
    printf("%d", n);

    return 0;
}
