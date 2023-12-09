#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long int getByteSize(FILE *f) {
    fseek(f, 0, SEEK_END);
    long int size = ftell(f);
    fseek(f, 0, SEEK_SET);
    return size;
}


int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Devi inserire almeno il percorso di un file di output e di due file di testo come argomenti in linea di comando!");
        exit(-1);
    }

    FILE *out_file = fopen(argv[1], "w");
    if (out_file == NULL) {
        printf("Errore riscontrato nell'apertura del file di output!");
        exit(-1);
    }

    for (int n = 2; n < argc; n++) {
        FILE *fn = fopen(argv[n], "r");
        const long int f_size = getByteSize(fn) + 1;
        printf("Lunghezza %s: %ld\n", argv[n], f_size);
        char dest[f_size];
        if (fn == NULL) {
            printf("Errore nell'apertura del file \"%s\"", argv[n]);
            exit(-1);
        }

        fgets(dest, f_size, fn);
        fprintf(out_file, "%s", dest);

        if (fclose(fn) != 0) {
            printf("Errore nella chiusura del file \"%s\"", argv[n]);
            exit(-1);
        }
    }


    if (fclose(out_file) != 0) {
        printf("Errore riscontrato nella chiusra del file di output!");
    }
    return 0;
}