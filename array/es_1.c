#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int ins[5];
    printf("Inserisci cinque numeri: ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &ins[i]);
    for (int i = 0; i < 5; i++)
        printf("%d ", ins[4-i]);
    return 0;
}