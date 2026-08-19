#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int opt;
  while ((opt = getopt(argc, argv, ":a:l")) != -1) {
    switch (opt) {
    case 'a': {
      FILE *datei = fopen("todo.txt", "a");
      if (datei == NULL) {
        perror("Datei konnte nicht geöffnet werden");
        return 1;
      }
      fprintf(datei, "%s\n", optarg);
      fclose(datei);
      break;
    }
    case 'l': {
      FILE *datei = fopen("todo.txt", "r");
      if (datei == NULL) {
        perror("Datei konnte nicht geöffnet werden");
        return 1;
      }
      char zeile[100];
      while (fgets(zeile, sizeof(zeile), datei) != NULL) {
        printf("%s", zeile);
      }
      fclose(datei);
      break;
    }
    }
  }
}