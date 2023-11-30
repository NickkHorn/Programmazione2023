#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int mat[3][3];
    printf("Prima   riga: ");
    scanf("%d %d %d", &mat[0][0], &mat[0][1], &mat[0][2]);
    printf("Seconda riga: ");
    scanf("%d %d %d", &mat[1][0], &mat[1][1], &mat[1][2]);
    printf("Terza   riga: ");
    scanf("%d %d %d", &mat[2][0], &mat[2][1], &mat[2][2]);

    bool simmetrica = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != mat[j][i] && i != j) {
                simmetrica = false;
                break;
            }
        }
        if (!simmetrica)
            break;
    }

    if (simmetrica)
        printf("Simmetrica\n");
    else
        printf("Non simmetrica\n");

    return 0;
}