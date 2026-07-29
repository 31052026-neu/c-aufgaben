#include <stdio.h>

int main() {
  char zustaende[][29] = {"glücklich", "traurig", "müde", "verwirrt"};
  char befehle[][20] = {"blinkt", "dreht", "hupt"};
  int zustand;
  int befehl;

  printf("Wähle einen Gemütszustand!:\n");
  scanf("%d", &zustand);

  if (zustand < 1 || zustand > 4) {
    puts("Ungültige Eingabe!");
    return 1;
  }

  printf("Wähle eine Aktion aus!\n");
  scanf("%d", &befehl);

  if (befehl < 1 || befehl > 3) {
    puts("Eingabe ungültig!");
    return 1;
  }

  // printf("Der Roboter %s %s%s", befehle [befehl-1], befehl - 1 == 1 ? "sich "
  // : "", zustaende[zustand - 1]);
  printf("Der Roboter %s ", befehle[befehl - 1]);
  if (befehl - 1 == 1) {
    printf("sich ");
  }
  printf("%s\n", zustaende[zustand - 1]);

  return 0;
}