#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void) {
  int numbers[5] = {-((1 << 30) + ((1 << 30) - 1)), 45, -12, 0, INT_MIN};

  for (int i = 0; i < 5; ++i) {
    printf("%d\n", numbers[i]);
    char s[10];
    itoa(numbers[i], s);
    puts(s);
  }
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[]) {
  int i, sign;

  unsigned int buffer = n;

  if ((sign = n) < 0) {
    buffer = -n;
  }
  i = 0;
  do {
    s[i++] = buffer % 10 + '0';
  } while ((buffer /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
