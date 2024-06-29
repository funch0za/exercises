#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 4

void squeeze(char s1[], const char s2[]);

int main() {
  char s11[] = "abcda232";
  const char s12[] = "0UL?";

  char s21[] = "rtyr lol -21+ iiii";
  const char s22[] = "iro ";

  char s31[] = "+++++++++++++++++";
  const char s32[] = "+a";

  char s41[] = "_+_+_+_+_+_+_+_+";
  const char s42[] = "_";

  char *all_1[N] = {s11, s21, s31, s41};
  const char *all_2[N] = {s12, s22, s32, s42};

  for (int i = 0; i < N; ++i) {
    printf("s1 = %s\ns2 = %s\n", all_1[i], all_2[i]);
    squeeze(all_1[i], all_2[i]);
    printf("res = %s\n", all_1[i]);
  }
}

void squeeze(char s1[], const char s2[]) {
  int last = 0;

  for (int i = 0; i < strlen(s1); ++i) {
    bool flag = true;

    for (int j = 0; flag && j < strlen(s2); ++j) {
      if (s1[i] == s2[j]) {
        flag = false;
      }
    }

    if (flag) {
      s1[last++] = s1[i];
    }
  }

  s1[last] = '\0';
}
