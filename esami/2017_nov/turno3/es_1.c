#include <stdlib.h>
#include <stdio.h>

int primo(int n);

// numero primo <= n
int f(int n);

int main() {
    unsigned int M;
    printf("Inserisci M: ");
    scanf("%u", &M);
    int curr_primi = 0;
    for (int n = 2; n <= M; n++) {
        if (primo(n))
            curr_primi++;
        printf("%d %d %d\n", n, f(n), curr_primi);
    }
    return 0;
}

int primo(int n) {
    int i, potenzialmente_primo;
    potenzialmente_primo = n % 2 || n == 2;
    i = 3;
    while (potenzialmente_primo && i * i <= n) {
        if (n % i == 0)
            potenzialmente_primo = 0;
        i += 2;
    }
    return potenzialmente_primo;
}

int f(int n) {
    for (int i = n; i >= 0; i--)
        if (primo(i))
            return i;
    return 0;
}