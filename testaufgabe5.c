#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Fehler: Kein Flag angegeben!\n");
    return 1;
  }
  if (strcmp(argv[1], "-h") == 0) {
    printf("Hilfe wird angezeigt.\n");
  } else if (strcmp(argv[1], "-a") == 0) {
    if (argc != 3) {
      fprintf(stderr, "Fehler: Text für Aufgabe fehlt!\n");
      return 1;
    }
    printf("Neue Aufgabe: %s\n", argv[2]);

  } else if (strcmp(argv[1], "-d") == 0) {
    if (argc != 3) {
      fprintf(stderr, "Fehler: Aufgabennummer fehlt.\n");
      return 1;
    }
    int nummer = atoi(argv[2]);
    printf("Aufgabe %d wird gelöscht.\n", nummer);

  } else if (strcmp(argv[1], "-c") == 0) {
    if (argc != 3) {
      fprintf(stderr, "Fehler: Aufgabenmarkierung fehlt\n");
      return 1;
    }
    int nummer = atoi(argv[2]);
    printf("Aufgabe %d: wurde als erledigt markiert.\n", nummer);
  } else {
    fprintf(stderr, "Flag ist unbekannt\n");
    return 1;
  }
}