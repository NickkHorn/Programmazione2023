#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NRIGHE 5
#define NCOLONNE 5
#define PROBMINA 0.3

#define max(a,b) ((a>=b)?a:b)
#define min(a,b) ((a<=b)?a:b)

void inizializza(int map[][NCOLONNE]) {
    for (int y = 0; y < NRIGHE; y++) {
        for (int x = 0; x < NCOLONNE; x++) {
            if (rand()%100 < PROBMINA*100)
                map[y][x] = 1; // c'è una mina
            else
                map[y][x] = 0;  // non c'è una mina
        }
    }
}

char mineAdiacenti(int map[][NCOLONNE], int x, int y) {
    int x_start = max(0, x-1), x_end = min(NCOLONNE-1, x+1);
    int y_start = max(0, y-1), y_end = min(NRIGHE-1, y+1);
    char n_mine = 0;
    for (int y = y_start; y <= y_end; y++)
        for (int x = x_start; x <= x_end; x++)
            if (map[y][x] == 1)
                n_mine++;
    return n_mine;
}

void stampaMappa(int map[][NCOLONNE]) {
    for (int y = 0; y < NRIGHE; y++) { 
        for (int x = 0; x < NCOLONNE; x++) {
            char ch = (map[y][x]==1)?'*':mineAdiacenti(map, x, y)+'0';
            printf("%c ", ch);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    
    int map[NRIGHE][NCOLONNE];
    inizializza(map);
    stampaMappa(map);

    return 0;
}