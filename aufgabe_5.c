#include <stdio.h>
#include <string.h>

int main() {

  // Ein Zeichenarray mit Platz für maximal 99 Zeichen + '\0'
  char text[100];

  // Den Benutzer auffordern, einen Text einzugeben
  printf("Gib einen Text ein, um zu überprüfen, ob es ein Palindrom ist:\n");

  // Die Eingabe des Benutzers einlesen
  fgets(text, 100, stdin);

  // Mit dieser Schleife wird der Zeilenumbruch ('\n'),
  // den fgets() durch die Enter-Taste speichert, entfernt.
  for (int i = 0; i < strlen(text); i++) {

    // Prüfen, ob das aktuelle Zeichen ein Zeilenumbruch ist
    if (text[i] == '\n') {

      // Den Zeilenumbruch durch das String-Endezeichen ersetzen,
      // damit die Zeichenkette an dieser Stelle endet.
      text[i] = '\0';

      // Schleife beenden, da der Zeilenumbruch gefunden wurde.
      break;
    }
  }

  // Anfangs gehen wir davon aus, dass der Text ein Palindrom ist.
  // 1 = Ja, es ist ein Palindrom
  // 0 = Nein, es ist kein Palindrom
  int istPalindrom = 1;

  // Länge der Zeichenkette bestimmen
  int laenge = strlen(text);

  // Nur bis zur Hälfte der Zeichenkette laufen.
  // Mehr ist nicht nötig, weil immer zwei Zeichen gleichzeitig
  // verglichen werden (eins von vorne, eins von hinten).
  for (int i = 0; i < laenge / 2; i++) {

    // Vergleicht das Zeichen von vorne mit dem passenden Zeichen von hinten.
    if (text[i] != text[(laenge - 1) - i]) {

      // HINWEIS:
      // Hier fehlt in deinem Code noch:
      // istPalindrom = 0;
      // Sonst erkennt das Programm kein Nicht-Palindrom.

      // Schleife beenden, weil bereits feststeht,
      // dass der Text kein Palindrom ist.
      break;
    }
  }

  // Ergebnis ausgeben
  if (istPalindrom == 1) {
    printf("Dieser Text ist ein Palindrom.\n");
  } else {
    printf("Dieser Text ist kein Palindrom.\n");
  }

  return 0;
}