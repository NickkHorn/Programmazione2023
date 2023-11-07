#include <stdlib.h>
#include <stdio.h>

int main() {
    int i = 1;
    while (i <= 196112)
        i += i % 4 ? 3 : 5;
    printf("%d", i);
    return 0;
}