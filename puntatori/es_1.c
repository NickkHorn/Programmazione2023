#include <stdlib.h>
#include <stdio.h>

void azzera(int *pv) {
    *pv = 0;
}

int main(void) {
    int a = 10;
    azzera(&a);
    printf("%d\n", a);
    return 0;
}