#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Fehler: Genau eine Aufgabe angeben\n");
    return 1;
  }
  FILE *datei = fopen("todo.txt", "a");
  if (datei == NULL) {
    perror("Datei konnte nicht geöffnet werden");
    return 1;
  }
  fprintf(datei, "o%s\n", argv[1]);
  fclose(datei);
}