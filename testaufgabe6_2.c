#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int opt;
  opterr = 0;
  while ((opt = getopt(argc, argv, ":hla:d:c:")) != -1) {

    switch (opt) {
    case 'h':
      printf("Hilfe wird angezeigt.\n");
      break;
    case 'l':
      printf("Liste wird angezeigt\n");
      break;
    case 'a':
      printf("neue Aufgaben: %s\n", optarg);
      break;

    case 'd': {
      int nummer = atoi(optarg);
      printf("Aufgabe %d wird gelöscht.\n", nummer);
      break;
    }
    case 'c': {
      int nummer = atoi(optarg);
      printf("Aufgabe %d wird als erledigt markiert.\n", nummer);
      break;
    }
    case '?':
      fprintf(stderr, "Fehler: Unbekanntes Flag!\n");
      return 1;
    case ':':
      fprintf(stderr, "Erforderliches Argument fehlt!\n");
      return 1;
    }
  }
}