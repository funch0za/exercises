#include <stdio.h>
#include <string.h>

enum { N = 100 };

int strindex(char s[], char t[]);

int main(void) {
  char s[N], t[N];

  while (fgets(s, N, stdin) != NULL && fgets(t, N, stdin) != NULL) {
    s[strlen(s) - 1] = '\0';
    t[strlen(t) - 1] = '\0';
    printf("strindex(%s, %s) = %d\n", s, t, strindex(s, t));
  }
}

int strindex(char s[], char t[]) {
  int i, j, k;
  int result = -1;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') {
      result = i;
    }
  }

  return result;
}
