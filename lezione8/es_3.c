#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define NRIGHE 5
#define NCOLONNE 5
#define PROBMINA 0.3

#define max(a,b) ((a>=b)?a:b)
#define min(a,b) ((a<=b)?a:b)

typedef struct {
    bool minata, scoperta;
} Casella;

void inizializza(Casella map[][NCOLONNE], int *n_mine) {
    *n_mine = 0;
    for (int y = 0; y < NRIGHE; y++) {
        for (int x = 0; x < NCOLONNE; x++) {
            map[y][x].minata = rand()%100 < PROBMINA*100;
            map[y][x].scoperta = false;
            if (map[y][x].minata)
                (*n_mine)++;
        }
    }
}

char mineAdiacenti(Casella map[][NCOLONNE], int x, int y) {
    int x_start = max(0, x-1), x_end = min(NCOLONNE-1, x+1);
    int y_start = max(0, y-1), y_end = min(NRIGHE-1, y+1);
    char n_mine = 0;
    for (int y = y_start; y <= y_end; y++)
        for (int x = x_start; x <= x_end; x++)
            if (map[y][x].minata)
                n_mine++;
    return n_mine;
}

void stampaMappa(Casella map[][NCOLONNE]) {
    // stampa lettere di riferimento
    printf("    ");
    for (int x = 0; x < NCOLONNE; x++)
        printf("%c ", x+'a');
    printf("\n\n");

    for (int y = 0; y < NRIGHE; y++) { 
        printf("%d   ", NRIGHE-y);
        for (int x = 0; x < NCOLONNE; x++) {
            char ch;
            if (map[y][x].scoperta)
                ch = (map[y][x].minata)?'*':mineAdiacenti(map, x, y)+'0';
            else
                ch = '#';
            printf("%c ", ch);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));

    Casella map[NRIGHE][NCOLONNE];
    int n_mine;
    inizializza(map, &n_mine);

    while (true) {
        stampaMappa(map);
        printf("Mine: %d\n", n_mine);

        char ins[3]; // l'input deve essere qualcosa del tipo 'a6', ma mi serve un byte in più per il terminatore
        int x_coord, y_coord;
        do {
            printf("Inserisci le coordinate da scoprire: ");
            scanf("%s", ins);

            int y_in = ins[1]-'0'; // y_coord = n_righe - y' --> y' = n_righe - y_coord
            y_coord = NRIGHE - y_in;
            x_coord = ins[0]-'a'; // il -1 è per portarlo in [0, NCOLONNE-1] piuttosto che in [1, NCOLONNE]

            if (x_coord < 0 || x_coord >= NCOLONNE || y_coord <= 0 || y_coord >= NRIGHE) {
                printf("Le coordinate non sono valide, riprova, ");
                continue;
            }
            else if (map[y_coord][x_coord].scoperta) {
                printf("La casella selezionata è già scoperat, riprova, ");
                continue;
            }
            break;
        } while (true);
        Casella selezionata = map[y_coord][x_coord];
        if (selezionata.minata) {
            printf("La casella che hai scoperto era minata, hai perso\n");
            break;
        }
        else if (selezionata.scoperta) {
            printf("La casella che hai inserito è già scoperta, prova ancora\n");
            continue;
        } 
        else
            map[y_coord][x_coord].scoperta = true;
    }

    return 0;
}