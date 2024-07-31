#include <string.h>
#include <stdio.h>

 #define max(a,b) \
      ({ __typeof__ (a) _a = (a); \
              __typeof__ (b) _b = (b); \
                   _a > _b ? _a : _b; })


enum {N = 100};

void reverse(char s[]);
void itoa(int n, char s[], int w);

int main() {
  int n, w;
  while (scanf("%d%d", &n, &w) == 2) {
    char s[N];
    itoa(n, s, w);
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

void itoa(int n, char s[], int w) {
  int i, sign;
 
  unsigned int buffer = n;
  memset(s, ' ', w);
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

  s[max(i, w)] = '\0';
  reverse(s);
}
    
