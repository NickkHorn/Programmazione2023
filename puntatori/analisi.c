#include <stdlib.h>

// h punta alla memoria di d (nel main), inizialmente è 3 (PASSO 3)
void g(int *h) {
    (*h)++; // aumenta il valore nella memoria di d, d = 4 (PASSO 4)
}

// a = c = 1 (per valore), b = d = 3 (per riferimento) (PASSO 2)
int f(int a, int *b) {
    g(b);
    return a + (*b); // a è ancora uno, *b è il valore di d che ora è 4, dunque f ritorna 5 (PASSO 5)
}

int main (void ) {
    int c = 1, d = 3, s = 6; // PASSO 1
    s = f(c, &d) ; // s diventa 5 dopo che la chiamata a f è finita (PASSO 6)

    /*In conclusione si ha s = 5, c= 1, d = 4*/
}