#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void getRandomString(char *dest, int length) {
    for (int i = 0; i < length; i++)
        dest[i] = (rand()%('z'-'a'+1)) + 'a';
    dest[length] = '\0';
}

int main(void) {
    srand(time(NULL));
    printf("https://meet.google.com/");
    char s1[4], s2[5], s3[4];
    getRandomString(s1, 3);
    getRandomString(s2, 4);
    getRandomString(s3, 3);
    printf("%s-%s-%s\n", s1, s2, s3);

    return 0;
}