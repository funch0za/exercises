#include <stdio.h>
#include <string.h>

#define N 3

int htoi(char s[]);

int main() {
  char s1[] = "AAA";
  char s2[] = "0x888";
  char s3[] = "0xFFA10";

  char *all[N] = {s1, s2, s3};

  for (int i = 0; i < N; ++i) {
    puts(all[i]);
    printf("%u\n\n", htoi(all[i]));
  }
}

int htoi(char s[]) {
  int result = 0, stop = 0;
  if (s[0] == '0' && (s[1] == 'x' || s[0] == 'X')) {
    stop = 2;
  }

  for (int i = strlen(s) - 1, pow = 1; i >= stop; --i, pow *= 16) {
    if ('a' <= s[i] && s[i] <= 'z') {
      result += (s[i] - 'a' + 10) * pow;
    } else if ('A' <= s[i] && s[i] <= 'Z') {
      result += (s[i] - 'A' + 10) * pow;
    } else {
      result += (s[i] - '0') * pow;
    }
  }

  return result;
}
