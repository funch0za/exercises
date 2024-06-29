#include <stdio.h>
#include <string.h>

#define N 4

int any(char s1[], const char s2[]);

int main() {
  char s11[] = "abbcbsds";
  const char s12[] = "0UL?";

  char s21[] = "llladsddsf i";
  const char s22[] = "iro ";

  char s31[] = "bbbbbbb+abbbbb";
  const char s32[] = "+a";

  char s41[] = "_";
  const char s42[] = "_";

  char *all_1[N] = {s11, s21, s31, s41};
  const char *all_2[N] = {s12, s22, s32, s42};

  for (int i = 0; i < N; ++i) {
    printf("s1 = %s\ns2 = %s\n", all_1[i], all_2[i]);
    printf("res = %d\n", any(all_1[i], all_2[i]));
  }
}

int any(char s1[], const char s2[]) {
  int result = -1;

  for (int i = 0; result == -1 && i < strlen(s1); ++i) {
    for (int j = 0; result == -1 && j < strlen(s2); ++j) {
      if (s1[i] == s2[j]) {
        result = i;
      }
    }
  }

  return result;
}