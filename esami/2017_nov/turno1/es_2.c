#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i = 200, s = 0;

  do {
    if (i % 2)
      s += (i /= 2);
    else
      i--;
  } while (i > 2);
  printf("%d", s);
  return 0;
}