#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Fehler: Flag und Text angeben im String!\n ");
    return 1;
  }
  if (strcmp(argv[1], "-a") == 0) {
    printf("Neue Aufgabe: %s\n", argv[2]);
  } else {
    fprintf(stderr, "Flag ist nicht bekannt!\n");
    return 1;
  }
}