#include <stdlib.h> 
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordina(int *a, int *b) {
    if (*a > *b)
        swap(a, b);
}

int main(void) {
    int a, b;
    printf("Inserire due numeri: ");
    scanf("%d %d", &a, &b);
    ordina(&a, &b);
    printf("Numeri ordinati: %d %d", a, b);
    return 0;
}