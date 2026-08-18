#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Fehler: Bitte genau einen Dateinamen angeben.\n");
    return 1;
  }
  /* pointer gesetzt */
  FILE *datei;
  /* hier soll die Datei mit den Namen, der direkt nach der Initialisierung
   * kommt öffnen */
  datei = fopen(argv[1], "r");

  if (datei == NULL) {
    perror("Fehler beim Öffnen der Datei");
    return 1;
  }
  int zeichen;
  int woerter = 0;
  int kwoerter = 0;
  int anzahlZeichen = 0;
  int zeilen = 0;
  int letztesZeichen = '\0';
  /* in der While-Schleife speichert er Zeichen für Zeichen in "zeichen" und
   * zählt "anzahlZeichen immer um eins Hoch" */
  while ((zeichen = fgetc(datei)) != EOF) {
    anzahlZeichen++;
    /* wenn ein newline Zeichen kommt, dann soll er "zeilen" um eins hochrechnen
     */
    if (zeichen == '\n') {
      zeilen++;
    }
    /* wenn Leerzeichen, newline oder Tabulator vorkommt, sind wir in keinem
    wort bzw. es ist kein mitzuzählendes Zeichen */
    if (zeichen == ' ' || zeichen == '\n' || zeichen == '\t') {
      kwoerter = 0;
      /* ansonsten ist es ein wort. es ist wie ein Schalter, solange kein
      Leerzeichen, newline oder tabulator vorkommt, ist der schalter auf 1, aber
      wenn eins der drei Zeichen vorkommt, dann wird der Schalter wieder auf 0
      gelegt und das Programm weiß, dass das Wort dort endet. es würde bei "h"
      eingeschlatet werden und nach "o" wieder ausgeschaltet werden */
    } else if (kwoerter == 0) {
      woerter++;
      kwoerter = 1;
    }
    letztesZeichen = zeichen;
  }
  /* wenn anzahlZeichen größer als 0 ist und letztesZeichen nicht newline, dann
   * zähle zeilen um eins hoch */
  if (anzahlZeichen > 0 && letztesZeichen != '\n') {
    zeilen++;
  }
  printf("woerter: %d\n", woerter);
  printf("zeichen: %d\n", anzahlZeichen);
  printf("zeilen: %d\n", zeilen);

  fclose(datei);
  return 0;
}