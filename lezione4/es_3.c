#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Scrivere un programma che approssimi il valore della funzione seno utilizzando i primi
// dieci addendi del suo sviluppo in serie di Taylor:

long factorial(int n) {
    long val = n;
    for (int i = n-1; i > 1; i--)
        val *= i;
    return val;
}

// approssimazione attorno allo 0
double sin(double x) {
    double val = 0;
    for (int n = 0; n < 10; n++)
        val += pow(-1, n) * pow(x, 2*n+1)/factorial(2*n + 1);
    return val;
}

int main(void) {
    for (double x = -0.5; x <= 0.5; x+=0.1) 
        printf("sin(%lf): %lf\n", x, sin(x));
    return 0;
}