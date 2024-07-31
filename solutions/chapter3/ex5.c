#include <string.h>
#include <stdio.h>

enum {N = 10};

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
  int n, b;
  while (scanf("%d%d", &n, &b) == 2) {
    char s[N];
    itob(n, s, b);
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

void itob(int n, char s[], int b) {
  int i, sign;
  
  unsigned int buffer = n;

  if ((sign = n) < 0) {
    buffer = -n;
  }
  
  i = 0;
  do {
    if (buffer % b >= 10) {
      s[i++] = buffer % b - 10 + 'a';
    } else {
      s[i++] = buffer % b + '0';
    }

  } while ((buffer /= b) > 0);
  
  if (sign < 0) {
    s[i++] = '-';
  }
  
  s[i] = '\0';
  reverse(s);
}
