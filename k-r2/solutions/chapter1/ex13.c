#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_COUNT 100

int main() {
  int c, n, state;
  int h[MAX_COUNT] = {0};

  state = OUT;
  n = -1;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else {
      if (state == OUT) {
        ++n;
        state = IN;
      }
      ++h[n];
    }
  }

  for (int i = 0; i < n; ++i) {
    h[i] = MAX_COUNT - h[i];
  }

  printf("%3c", ' ');
  for (int i = 1; i <= n; ++i) {
    printf("%3d", i);
  }
  putchar('\n');
  for (int i = MAX_COUNT; i >= 1; --i) {
    printf("%3d", i);
    for (int j = 0; j < n; ++j) {
      char ch = '#';
      if (h[j] > 0) {
        ch = ' ';
        --h[j];
      }
      printf("%3c", ch);
    }
    putchar('\n');
  }
}
