#include <stdio.h>

int main (int argc, char *argv []) {
    if (argc != 2) {
        printf("Fehler, bitte genau einen Dateinamen angeben!");
        return 1;
    }
    FILE *datei;
    datei = fopen(argv[1], "r");
    if (datei == NULL) {
        perror("Die Datei kann nicht geöffnet werden!");
        return 1;
    }
    int zeichen;
    int anzahl = 0;
    /* die innere Klammer heißt " lies ein Zeichen aus der Datei und speichere sie in "zeichen""
    und tue das solange bis End Of File Dabei zähle anzahl um eins hoch.
    es werden Leerzeichen und alle anderenj zeichen auch mitgezählt. */
    while ((zeichen = fgetc(datei)) != EOF) {
        anzahl++;
    }

    printf("Es sind %d zeichen vorhanden\n", anzahl);

    return 0;
}