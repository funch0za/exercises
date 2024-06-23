#include <stdio.h>

#define MAX_CH 128

int main() {
  int c;

  int fr[MAX_CH] = {0};

  while ((c = getchar()) != EOF) {
    ++fr[c];
  }

  for (int i = 0; i < MAX_CH; ++i) {
    if (fr[i] > 0) {
      printf("%c ", i);
      for (int j = 0; j < fr[i]; ++j) {
        putchar('#');
      }
      putchar('\n');
    }
  }
}
