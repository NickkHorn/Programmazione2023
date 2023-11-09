#include <stdlib.h>
#include <stdio.h>

int cubo(int n);

int main() {
    int arr[100];
    unsigned short int M;
    printf("Inserisci un numero minore o uguale a 100: ");
    scanf("%u", &M);
    for (int i = 1; i <= M; i++) {
        arr[i-1] = cubo(i);
        printf("%u ", arr[i-1]);
    }
    return 0;
}

int cubo(int n) {
    int s = 0;
    int i = 1;
    while (i <= n) {
        int j = 0;
        while (j < n) {
            s += n;
            j++;
        }
        i++;
    }
    return s;
}