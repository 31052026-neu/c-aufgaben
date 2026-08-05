#include <stdio.h>

int main() {

  // Die äußere Schleife bestimmt, in welcher Zeile wir uns befinden.
  // Sie läuft insgesamt 5-mal, weil das Dreieck 5 Zeilen hat.
  for (int i = 0; i < 5; i++) {

    // Diese Schleife gibt die Leerzeichen vor den Hashtags aus.
    // In jeder neuen Zeile wird ein Leerzeichen weniger ausgegeben,
    // damit das Dreieck mittig dargestellt wird.
    for (int j = 0; j < (5 - 1) - i; j++) {
      printf(" ");
    }

    // Diese Schleife gibt die Hashtags aus.
    // Die Anzahl der Hashtags wächst in jeder Zeile:
    // 1, 3, 5, 7, 9
    for (int k = 0; k < 2 * i + 1; k++) {
      printf("#");
    }

    // Nach jeder Zeile wird in die nächste Zeile gewechselt.
    printf("\n");
  }

  // Das Programm wurde erfolgreich beendet.
  return 0;
}