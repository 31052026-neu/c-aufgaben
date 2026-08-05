
#include <stdio.h>

int main() {

  int matrix[4][4] = {
      {2, 3, 5, 7},
      {11, 13, 17, 19},
      {23, 29, 31, 37},
      {41, 43, 47, 53},
  };
  for (int i = 0; i < 4; i++) {
    int summe = 0;
    for (int j = 0; j < 4; j++) {
      summe += matrix[i][j];
    }
    printf("Die Zeile %d hat die Summe %d\n", i, summe);
  }
  for (int i = 0; i < 4; i++) {
    int summe = 0;
    for (int j = 0; j < 4; j++) {
      summe += matrix[j][i];
    }
    printf("Die Spalte %d hat die Summe %d\n", i, summe);
  }
  int summe = 0;
  for (int i = 0; i < 4; i++) {
    summe += matrix[i][i];
  }
  printf("Die Diagonale von oben links hat die Summe %d\n", summe);

  summe = 0;
  for (int i = 0; i < 4; i++) {
    summe += matrix[i][3 - i];
  }
  printf("Die Diagonale von oben rechts hat die Summe %d\n", summe);
  return 0;
}