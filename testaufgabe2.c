#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "Fehler, genau eine Zahl angeben!");
    return 1;
  }
  int zahl;
  zahl = atoi(argv[1]);

  printf("%d\n", zahl);
}
