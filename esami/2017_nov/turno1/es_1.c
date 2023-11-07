#include <stdlib.h>
#include <stdio.h>

float radice(float a);
float valoreAssolute(float a);
float f(float n) {
    return radice((n-1)/(n+1));
}

int main() {
    unsigned int a, b;
    printf("Inserisci i numeri A e B: ");
    scanf("%ud %ud", &a, &b);
    for (int n = a; n <= b; n++) {
        if (n%2 == 1)
            printf("%d\n", n);
        else
            printf("%f\n", f(n));
    }

    return 0;
}

float valoreAssoluto(float a) {
    return (a>=0)?a:-a;
}

float radice(float a) {
  float x = 1.0;
  while (valoreAssoluto(x * x - a) > 1e-5)
    x = (x + a / x) / 2.0;
  return x;
}
