#include <stdio.h>

int main() {
  int lim = 200;
  char s[lim - 1];
  for (int i = 0, c;
       (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF) == 1; ++i) {
    s[i] = c;
  }

  printf("%s", s);

  return 0;
}
