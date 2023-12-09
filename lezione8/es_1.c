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

void stampaMappa(int map[][NCOLONNE]) {
    for (int y = 0; y < NRIGHE; y++) { 
        for (int x = 0; x < NCOLONNE; x++) {
            char ch = (map[y][x]==1)?'*':' ';
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