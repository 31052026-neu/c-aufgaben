#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Fehler, genau einen Dateinamen angeben!\n");
    return 1;
  }
  printf("%s\n", argv[1]);
}