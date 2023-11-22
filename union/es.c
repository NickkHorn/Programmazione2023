#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159265358979

// dimensioni
typedef struct {
    float l1,l2,l3;
} dims;

typedef union {
    dims dim;
} figura;

typedef enum {
    QUADRATO,
    CERCHIO,
    RETTANGOLO,
    TRIANGOLO
} tipo;

float area(figura fig, tipo tipo) {
    switch (tipo) {
        case QUADRATO: return fig.dim.l1*fig.dim.l1; break;
        case CERCHIO: return PI*fig.dim.l1*fig.dim.l1; break;
        case RETTANGOLO: return fig.dim.l1*fig.dim.l2; break;
        case TRIANGOLO: return fig.dim.l1*fig.dim.l2/2.0; break;
    }
}

float perimetro(figura fig, tipo tipo) {
    switch (tipo) {
        case QUADRATO: return 4*fig.dim.l1; break;
        case CERCHIO: return 2*PI*fig.dim.l1; break;
        case RETTANGOLO: return 2*(fig.dim.l1+fig.dim.l2); break;
        case TRIANGOLO: return fig.dim.l1+fig.dim.l2+fig.dim.l3; break;
    }
}

int main(void) {
    // fare test se si vuole
    return 0;
}