#include <stdlib.h>
#include <stdio.h>

int MCD(int a, int b) {
    while (a != b) {
        if (a < b)
            b -= a;
        else
            a -= b;
    }
    return a;
}

int main() {
    int M;
    printf("Inserire M: ");
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            float f = 1.0/MCD(i,j);
            printf("%.3f ", f);
        }
        printf("\n");
    }

    return 0;
}