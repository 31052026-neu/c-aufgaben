#include <stdio.h>
int main() {

  int a[9] = {1, 3, 2, 4, 0, 9, 1, 1, 4};
  int zaehler[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int number = 0;
  for (int i = 0; i < 9; i++) {
    zaehler[a[i]]++;
  }
  for (int j = 0; j < 10; j++) {
    printf("%d kommt %d mal vor. \n", j, zaehler[j]); //
  }
  /*
    printf("%d kommt %d mal vor. \n", 0, zaehler[0]);
    printf("%d kommt %d mal vor. \n", 1, zaehler[1]);
    printf("%d kommt %d mal vor. \n", 2, zaehler[2]);
    printf("%d kommt %d mal vor. \n", 3, zaehler[3]);
    printf("%d kommt %d mal vor. \n", 4, zaehler[4]);
    printf("%d kommt %d mal vor. \n", 5, zaehler[5]);
      ...
    printf("%d kommt %d mal vor. \n", 9, zaehler[9]);
  */
  return 0;
}
