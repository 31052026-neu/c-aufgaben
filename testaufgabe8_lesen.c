#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "Fehler: Genau eine Aufgabennummer angeben!\n");
    return 1;
  }
  FILE *datei = fopen("todo.txt", "r");
  if (datei == NULL) {
    perror(" Fehler: Datei konnte nicht gefunden werden!");
    return 1;
  }
  FILE *temp = fopen("temp.txt", "w");
  if (temp == NULL) {
    perror("Fehler: Datei konnte nicht gefunden werden!");
    return 1;
  }

  int nummer = 1;
  char zeile[100];
  int gesucht = atoi(argv[1]);
  while (fgets(zeile, sizeof(zeile), datei) != NULL) {
    if (nummer == gesucht) {
      printf("Aufgabe %d gefunden!\n", gesucht);
      if (zeile[0] == 'o') {
        zeile[0] = 'e';
        printf("%d. [x] %s", nummer, &zeile[1]);
      } else if (zeile[0] == 'e') {
        printf("%d. [x] %s", nummer, &zeile[1]);
      }
    }
    fprintf(temp, "%s", zeile);
    nummer++;
  }
  fclose(datei);
  fclose(temp);
  if (rename("temp.txt", "todo.txt") != 0) {
    perror("Datei konnte nicht ersetzt werden!");
    return 1;
  }
}