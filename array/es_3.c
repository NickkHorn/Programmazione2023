#include <stdlib.h>
#include <stdio.h>

#define DIM 10

int main(void) {
    int nums[DIM];
    for (int i = 1; i <= DIM; i++)
        nums[i-1] = i*i;
    for (int i = 0; i < DIM; i++)
        printf("%d\n", nums[i]);
    return 0;
}