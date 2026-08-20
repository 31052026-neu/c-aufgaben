#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int opt;
  char aktion = '\0';
  int gesucht = 0;
  char *ende;

  while ((opt = getopt(argc, argv, ":c:u:")) != -1) {

    switch (opt) {

    case 'c': {
      aktion = 'c';
      gesucht = strtol(optarg, &ende, 10);
      if (ende == optarg) {
        fprintf(stderr, "Fehler: Keine gültige Zahl angegeben!\n");
        return 1;
      }
      if (*ende != '\0') {
        fprintf(stderr, "Fehler: Ungültige Aufgabennummer!\n");
        return 1;
      }
      if (gesucht <= 0) {
        fprintf(stderr, "Fehler: Aufgabennummer muss größer als 0 sein!\n");
        return 1;
      }
      printf("Aufgabe %d soll erledigt werden.\n", gesucht);
      break;
    }
    case 'u': {
      aktion = 'u';
      gesucht = strtol(optarg, &ende, 10);
      if (ende == optarg) {
        fprintf(stderr, "Fehler: Keine gültige Zahl angegeben!\n");
        return 1;
      }
      if (*ende != '\0') {
        fprintf(stderr, "Fehler: Ungültige Aufgabennummer!\n");
        return 1;
      }
      if (gesucht <= 0) {
        fprintf(stderr, "Fehler: Aufgabennummer muss größer als 0 sein!\n");
        return 1;
      }
      printf("Aufgabe %d soll wieder geöffnet werden.\n", gesucht);
      break;
    }

    case ':':
      fprintf(stderr, "Fehler: Erforderliches Argument fehlt!\n");
      return 1;
    case '?':
      fprintf(stderr, "Fehler: Unbekanntes Flag!\n");
      return 1;
    }
  }
  if (aktion == '\0') {
    fprintf(stderr, "Fehler: Keine Aktion angegeben!\n");
    return 1;
  }
  FILE *datei = fopen("todo.txt", "r");
  if (datei == NULL) {
    perror("Fehler: Datei konnte nicht gefunden werden");
    return 1;
  }
  FILE *temp = fopen("temp.txt", "w");
  if (temp == NULL) {
    perror("Fehler: Datei konnte nicht gefunden werden");
    return 1;
  }
  int nummer = 1;
  int gefunden = 0;
  char zeile[100];
  while (fgets(zeile, sizeof(zeile), datei) != NULL) {
    if (nummer == gesucht) {
      gefunden = 1;
      if (aktion == 'c') {
        if (zeile[0] == 'o') {
          zeile[0] = 'e';
        }
      }
      if (aktion == 'u') {
        if (zeile[0] == 'e') {
          zeile[0] = 'o';
        }
      }
    }
    fprintf(temp, "%s", zeile);
    nummer++;
  }
  if (gefunden == 0) {
    fclose(datei);
    fclose(temp);

    remove("temp.txt");

    fprintf(stderr, " Fehler: Keine Aufgabe mit dieser Nummer gefunden.\n");
    return 1;
  }
  fclose(datei);
  fclose(temp);
  if (rename("temp.txt", "todo.txt") != 0) {
    perror("Datei konnte nicht ersetzt werden!");
    return 1;
  }
}
