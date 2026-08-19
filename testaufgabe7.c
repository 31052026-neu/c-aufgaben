#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  FILE *datei = fopen("todo.txt", "r");
  if (datei == NULL) {
    perror("Datei nicht vorhanden!");
    return 1;
  }
  char zeile[100];
  while (fgets(zeile, sizeof(zeile), datei) != NULL) {
    printf("%s", zeile);
  }
  fclose(datei);
}