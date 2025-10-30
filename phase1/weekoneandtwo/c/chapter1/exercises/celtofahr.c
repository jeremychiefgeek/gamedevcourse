// Chapter 1 Section 1.2 excercise 2
#include <stdio.h>

int main() {
  float fahr, celcius;
  float lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  celcius = lower;

  // Excercise for 1.2
  printf("%3s %6s\n", "Celcius", "Fahr");

  while (celcius <= upper) {
    fahr = (9.0 / 5.0) * celcius + 32.0;
    printf("%3.1f  %6.1f\n", celcius, fahr);
    celcius = celcius + step;
  }

  return 0;
}
