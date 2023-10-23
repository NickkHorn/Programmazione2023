#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    do {
        if (a % 3)
            a--;
        else
            a /= 2;
    } while (a >= 10);
    printf("%d", a); // a = 9

    return 0;
}