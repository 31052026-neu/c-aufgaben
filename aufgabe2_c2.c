#include <stdio.h>

int main() {
  int zahl[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int zahl2[9] = {};

  for (int i = 0; i <= 8; i++) {
    zahl2[i] = zahl[8 - i];
    printf("%d\n", zahl[i]);
  }
  for (int i = 0; i <= 8; i++) {
    printf("%d\n", zahl2[i]);
  }

  return 0;
}