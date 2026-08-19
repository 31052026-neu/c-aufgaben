#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int opt;
  while ((opt = getopt(argc, argv, "hla:d:c:")) != -1) {

    if (opt == 'h') {
      printf("Hilfe wird angezeigt.\n");
    } else if (opt == 'l') {
      printf("Liste wird angezeigt\n");
    } else if (opt == 'a') {
      printf("Neue Aufgabe: %s\n", optarg);
    } else if (opt == 'd') {
      int nummer = atoi(optarg);
      printf("Aufgabe %d wird gelöscht.\n", nummer);
    } else if (opt == 'c') {
      int nummer = atoi(optarg);
      printf("Aufgabe %d wird als erledigt markiert.", nummer);
    }
  }
}