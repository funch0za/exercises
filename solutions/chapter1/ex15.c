#include <stdio.h>

float get_fahr(float celsius);

int main() {
  int lower, upper, step;
  float celsius, fahr;

  lower = -60;
  upper = 60;
  step = 5;

  celsius = lower;
  while (celsius <= upper) {
    fahr = get_fahr(celsius);
    printf("%5.0f %9.1f\n", celsius, fahr);
    celsius += 5.0;
  }
}

float get_fahr(float celsius) { return (9.0 / 5.0) * celsius + 32.0; }
