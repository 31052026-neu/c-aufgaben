#include <stdio.h>

int main() {
  int glücklich = 1;
  int traurig = 2;
  int müde = 3;
  int verwirrt = 4;
  int zustand;
  int befehl;

  printf("Wähle eine Gemütszustand.\n");
  scanf("%d", &zustand);
  if (zustand < 1 || zustand > 4) {
    printf("Ungültiger Befehl!\n");
    return 1;
  }
  printf("Gib eine Zahl ein um einen Befehl durchzuführen!: \n");
  scanf("%d", &befehl);
  if (befehl < 1 || befehl > 3) {
    printf("Ungültiger Befehl!\n");
    return 1;
  }

  if (befehl == 1) {
    if (zustand == 1) {
      printf("Der Roboter blinkt fröhlich\n");
    } else if (zustand == 2) {
      printf("Der Roboter blinkt traurig\n");
    } else if (zustand == 3) {
      printf("Der Roboter blinkt müde\n");
    } else if (zustand == 4) {
      printf("Der Roboter blinkt verwirrt\n");
    }
  }
  if (befehl == 2) {
    if (zustand == 1) {
      printf("Der Roboter dreht sicht fröhlich\n");
    } else if (zustand == 2) {
      printf("Der Roboter dreht sich traurig\n");
    } else if (zustand == 3) {
      printf("Der Roboter dreht sich müde\n");
    } else if (zustand == 4) {
      printf(" Der Roboter dreht sich verwirrt\n");
    }
  }

  if (befehl == 3) {
    if (zustand == 1) {
      printf("Der Roboter hupt fröhlich!\n");
    } else if (zustand == 2) {
      printf("Der Roboter hupt traurig.\n");
    } else if (zustand == 3) {
      printf("Der Roboter hupt müde.\n");
    } else if (zustand == 4) {
      printf("Der Roboter hupt verwirrt.\n");
    }
  }
}