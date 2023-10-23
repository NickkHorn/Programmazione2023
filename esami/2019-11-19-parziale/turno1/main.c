#include <stdlib.h>
#include <stdio.h>

int MCD(int a, int b) {
    if (a > b) {
        int t = b;
        b = a;
        a = t;
    }

    int m = 1;
    int i = 2;
    while (i <= a) {
        if (a % i == 0 && b % i == 0)
            m = i;
        i++;
    }

    return m;
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

int main() {
    int arr[10];
    int M;
    printf("Inserisci un numero: ");
    scanf("%d", &M);
    for (int i = 1; i <= 10; i++) {
        arr[i-1] = MCD(M, i);
        printf("MCD(%d, %d) = %d\n", M, i, arr[i-1]);
    }
    
    // ES 2
    int num;
    for (num = 196113; !primo(num); num++);
    printf("%d", num);
    return 0;
}