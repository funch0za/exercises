#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum {N = 100};

double atof(char s[]);
  
int main(void) {
  char s[N];
  while (fgets(s, N, stdin) != NULL) {
    s[strlen(s) - 1] = '\0';
    printf("atof(%s) = %lf\n", s, atof(s));
  }
}

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] -'0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    ++i;
    if (s[i] == '-') {
      ++i;
      int power_val = 0; 
      for (;isdigit(s[i]); i++) {
        power_val = 10.0 * power_val + (s[i] - '0');
      } 
      for (int j = 0; j < power_val; ++j) {
        power *= 10;
      }
    } else {
      int power_val = 0; 
      for (;isdigit(s[i]); i++) {
        power_val = 10.0 * power_val + (s[i] - '0');
      }
      for (int j = 0; j < power_val; ++j) {
        power /= 10;
      }
    }
  }

  return sign * val / power;
}
