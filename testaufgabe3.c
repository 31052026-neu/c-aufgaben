#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "Fehler: Genau eine Flag angeben!\n");
    return 1;
  }
  if (strcmp(argv[1], "-h") == 0) {
    printf("Hilfe wird angezeigt.\n");
  } else if (strcmp(argv[1], "-l") == 0) {
    printf("Liste wird angezeigt.\n");
  } else {
    fprintf(stderr, "Flag unbekannt!\n");
    return 1;
  }
}
/* strcpm fungiert als vergleichsoperator. 0 bedeutet wahr und != 0 bedeutet
 * falsch */