#include <stdlib.h>
#include <stdio.h>

void stampaMatrice(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int mat[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat[i][j] = (i==j)?1:0;
    stampaMatrice(mat);
    return 0;
}