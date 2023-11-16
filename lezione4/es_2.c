#include <stdlib.h>
#include <stdio.h>

/*
Scrivere un programma che calcoli un’approssimazione della radice quadrata di un
numero reale a con il cosiddetto metodo babilonese: una successione x di
approssimazioni in cui il primo elemento x1 è 1.0 e il successore x_(k+1) di xk è la media
aritmetica fra xk e a/xk
Testarlo chiamandolo con input significativi. */

double absolute(double x) {
    return (x>=0)?x:-x;
}

double radice(double a) {
    double x = 1.0;
    while (absolute(x*x - a) > 1e-5)
        x = (x + a/x)/2.0;
    return x;
}

int main(void) {
    double val;
    printf("Inserisci un numero: ");
    scanf("%lf", &val);
    printf("sqrt(%lf) = %lf", val, radice(val));
    return 0;
}