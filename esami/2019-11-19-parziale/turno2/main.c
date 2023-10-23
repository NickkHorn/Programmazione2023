#include <stdio.h>
#include <stdlib.h>

float radice3(float y) {
    float a = 1;
    float b = y;
    float x;
    do {
        x = (a+b)/2;
        if (x*x*x > y)
            b = x;
        else 
            a = x;
    } while (b-a > 10e-5);
    return x;
}

int main() {
    float arr[10];
    float radici[10] = {0,0,0,0,0,0,0,0,0,0};
    int N = 0;

    for (int i = 0; i < 10; i++) {
        printf("Inserisci il numero %d: ", i);
        scanf("%f", &arr[i]);
        float rad = radice3(arr[i]);
        if (rad > 1) {
            radici[N] = rad;
            N++;
        }
    }

    for (int j = 0; j < N; j++)
        printf("%.3f\n", radici[j]);
    return 0;
}