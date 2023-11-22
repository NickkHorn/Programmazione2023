#include <stdlib.h>
#include <stdio.h>

int main(void) {
    double x[20];
    double y[20];
    double a,b,c;
    printf("Inserisci tre numeri reali: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    for (int i = 0; i <= 20; i++) {
        x[i] = 2*(i-10)/20.0;
        y[i] = a*(x[i]*x[i]) + b*x[i] + c;
        printf("<%lf, %lf>\n", x[i], y[i]);
    }

    return 0;
}