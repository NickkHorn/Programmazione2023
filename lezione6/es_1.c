#include <stdlib.h>
#include <stdio.h>

int absolute(int x) {
    return (x>=0)?x:-x;
}

int main(void) {
    int ins[5];
    int min_val_idx = 0;
    for (int i = 0; i < 5; i++) {
        printf("Inserisci il numero #%d: ", i);
        scanf("%d", &ins[i]);
        if (absolute(ins[i]) < absolute(ins[min_val_idx]))
            min_val_idx = i;
    }
    printf("Valore assoluto minimo: %d", ins[min_val_idx]);

    return 0;
}