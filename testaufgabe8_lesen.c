#include <stdio.h>
#include <stdlib.h>

int main(void) {

  FILE *datei = fopen("todo.txt", "r");
  if (datei == NULL) {
    perror(" Fehler: Datei konnte nicht gefunden werden!");
    return 1;
  }
  char zeile[100];
  while (fgets(zeile, sizeof(zeile), datei) != NULL) {
    if (zeile[0] == 'o') {
      printf("[ ] %s", &zeile[1]);
    }
  }
  fclose(datei);
}