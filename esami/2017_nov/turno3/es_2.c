#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i = 10000;
    while (196112 % i != 0 && i > 0) {
        if (i%3)
            i /= 3;
        else
            i--;
    }
    printf("%d", i);
    return 0;
}