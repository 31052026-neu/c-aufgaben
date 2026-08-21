#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int opt;

  while ((opt = getopt(argc, argv, ":hla:e:d:c:u:UC")) != -1) {

    switch (opt) {

    case 'h':
      printf(
        "Flags und Ihre Funktion\n"
        "schreibe zuerst *./liste* und dann die jeweiligen Flags mit Leertaste dahinter.\n"
        "Flags:\n"
        "       -h                  Hilfe anzeigen\n"
        "       -l                  Alle Aufgaben anzeigen\n"
        "       -a Text             Aufgabe hinzufügen\n"
        "       -e Text & Nummer    Aufgabe bearbeiten\n"
        "       -d Nummer           Aufgabe löschen\n"
        "       -c Nummer           Aufgabe als erledigt markieren\n"
        "       -u Nummer           Aufgabe wieder öffnen\n"
        "       -U                  Nur offene Aufgaben anzeigen\n"
        "       -C                  Nur erledigte Aufgaben anzeigen\n" 
      );
      break;

    /* -l zeigt die Aufgaben an */
    case 'l': {

      printf("Aufgaben anzeigen.\n");

      FILE *datei = fopen("todo.txt", "r");

      if (datei == NULL) {
        perror("Fehler: Datei konnte nicht geöffnet werden.");
        return 1;
      }

      int aktuelleNummer = 1;
      char zeile[100];

      while (fgets(zeile, sizeof(zeile), datei) != NULL) {

        if (zeile[0] == 'o') {
          printf("%d. [ ] %s", aktuelleNummer, &zeile[1]);

        } else if (zeile[0] == 'e') {
          printf("%d. [x] %s", aktuelleNummer, &zeile[1]);
        }

        aktuelleNummer++;
      }

      fclose(datei);
      break;
    }

    /* -a "Text" lässt Aufgaben hinzufügen */
    case 'a': {

      printf("Aufgabe hinzufuegen.\n");

      FILE *datei = fopen("todo.txt", "a");

      if (datei == NULL) {
        perror("Fehler: Datei konnte nicht geoeffnet werden.");
        return 1;
      }

      fprintf(datei, "o%s\n", optarg);

      fclose(datei);
      break;
    }

    /* //-e "Text" + NUMMER// soll Aufgaben ersetzen */
    case 'e': {

      char *neuerText = optarg;
      char *ende;

      if (optind >= argc) {
        fprintf(stderr, "Fehler: Aufgabennummer fehlt\n");
        return 1;
      }

      long nummerBearbeiten = strtol(argv[optind], &ende, 10);

      if (ende == argv[optind]) {
        fprintf(stderr, "Fehler: Keine gültige Zahl angegeben!\n");
        return 1;
      }

      if (*ende != '\0') {
        fprintf(stderr, "Fehler: Ungültige Aufgabennummer!\n");
        return 1;
      }

      if (nummerBearbeiten <= 0) {
        fprintf(stderr, "Fehler: Aufgabennummer muss größer als 0 sein!\n");
        return 1;
      }

      /* Originaldatei zum Lesen öffnen */
      FILE *datei = fopen("todo.txt", "r");

      if (datei == NULL) {
        perror("Fehler: Datei konnte nicht geöffnet werden.");
        return 1;
      }

      /* Temporäre Datei gehört zu -e */
      FILE *temp = fopen("temp.txt", "w");

      if (temp == NULL) {
        fprintf(stderr,
                "Fehler: Temporäre Datei konnte nicht geöffnet werden.\n");
        fclose(datei);
        return 1;
      }

      int aktuelleNummer = 1;
      int gefunden = 0;
      char zeile[100];

      while (fgets(zeile, sizeof(zeile), datei) != NULL) {

        if (aktuelleNummer == nummerBearbeiten) {
          gefunden = 1;

          fprintf(temp, "%c%s\n", zeile[0], neuerText);

        } else {
          fprintf(temp, "%s", zeile);
        }

        aktuelleNummer++;
      }

      if (gefunden == 0) {
        fprintf(stderr, "Fehler: Falsche Aufgabennummer angegeben!\n");
        return 1;
      }

      printf("Aufgabe bearbeiten.\n");
      printf("Neuer Text: %s\n", neuerText);

      fclose(datei);
      fclose(temp);

      if (rename("temp.txt", "todo.txt") != 0) {
        perror("Fehler: Datei konnte nicht ersetzt werden");
        return 1;
      }
      break;
    }
    /* //-d ZAHL// löscht die Aufgabe die an der angegebenen Stelle steht */
    case 'd': {
      char *ende;
      long nummerLöschen = strtol(optarg, &ende, 10);
      //---------------------Fehlerprüfungen ------------------------//
      if (ende == optarg) {
        fprintf(stderr, "Fehler: Keine gültige Zahl angegeben!\n");
        return 1;
      }
      if (*ende != '\0') {
        fprintf(stderr, "Fehler: Ungültige Aufgabennummer.\n");
        return 1;
      }
      if (nummerLöschen <= 0) {
        fprintf(stderr, "Fehler: Angegebene Zahl muss größer als 0 sein.\n");
        return 1;
      }
      // ---------------------Fehlerprüfungen -----------------------//
      FILE *datei = fopen("todo.txt", "r");
      if (datei == NULL) {
        perror("Fehler: Datei konnte nicht geöffnet werden.");
        return 1;
      }

      FILE *temp = fopen("temp.txt", "w");
      if (temp == NULL) {
        perror("Fehler: Temporäre Datei konnte nicht geöffnet werden.");
        return 1;
      }
      int aktuelleNummer = 1;
      int gefunden = 0;
      char zeile[100];
      
      while (fgets(zeile, sizeof(zeile), datei) != NULL) {
        if (aktuelleNummer == nummerLöschen) {
          gefunden = 1;
        } else {
          fprintf(temp, "%s", zeile);
        }
        aktuelleNummer++;
      }
      if (gefunden == 0) {
        fclose(datei);
        fclose(temp);
        remove("temp.txt");

        fprintf(stderr, "Fehler: Falsche Aufgabennummer angegeben!\n");
        return 1;
      }
      fclose(datei);
      fclose(temp);

      if (rename("temp.txt", "todo.txt") != 0) {
        perror("Fehler: Datei konnte nicht ersetzt werden!");
        return 1;
      }

      break;
    }

    case 'c':{
      char *ende;
      long nummerErledigen = strtol(optarg, &ende, 10);
      //------------------Fehlerprüfung-----------------//
      if (ende == optarg) {
        fprintf(stderr,"Fehler: Keine Zahl angegeben.\n");
        return 1;
      }
      if (*ende != '\0') {
        fprintf(stderr, "Fehler: Ungültiges Zeichen angegebene.\n");
        return 1;
      }
      if (nummerErledigen <= 0) {
        fprintf(stderr, "Fehler: Zahl ist zu klein.\n");
        return 1;
      }
      //---------------------Fehlerprüfung--------------------//

      FILE *datei = fopen("todo.txt", "r");
      if(datei == NULL) {
        perror("Fehler: Datei konnte nicht geöffnet werden!");
        return 1;
      }
      FILE *temp = fopen("temp.txt", "w");
      if (temp == NULL) {
        perror("Fehler: Temporäre Datei konnte nicht geöffnet werden.");
        fclose(datei);
        return 1;
      }

      int aktuelleNummer = 1;
      int gefunden = 0;
      char zeile[100];

      while (fgets(zeile, sizeof(zeile), datei)!= NULL) {
        if (aktuelleNummer == nummerErledigen) {
          gefunden = 1;

          if (zeile[0]== 'o') {
            zeile[0] = 'e';
          }
        }
        fprintf(temp, "%s", zeile);
        aktuelleNummer++;
      }
      if (gefunden == 0) {
        fclose(datei);
        fclose(temp);
        remove("temp.txt");

        fprintf(stderr, "Fehler: Falsche Aufgabennummer angegeben!\n");
        return 1;
      }
      fclose(datei);
      fclose(temp);

      if (rename("temp.txt","todo.txt")!= 0) {
        perror("Fehler: Datei konnte nicht ersetzt werden.");
        return 1;
      }
      printf("Aufgabe %ld wurde als ereledigt markiert.\n", nummerErledigen);
      break;
    
    
    
    case 'u':{
      char *ende;
      long nummerÖffnen = strtol (optarg, &ende,10);

      //------------------Fehlerprüfung-----------------//
      if (ende == optarg) {
        fprintf(stderr,"Fehler: Keine Zahl angegeben.\n");
        return 1;
      }
      if (*ende != '\0') {
        fprintf(stderr, "Fehler: Ungültiges Zeichen angegebene.\n");
        return 1;
      }
      if (nummerÖffnen <= 0) {
        fprintf(stderr, "Fehler: Zahl ist zu klein.\n");
        return 1;
      }
      //---------------------Fehlerprüfung--------------------//

      FILE *datei = fopen("todo.txt", "r");
        if (datei == NULL) {
          perror("Fehler: Datei konnte nicht geöffnet werden!");
          return 1;
        }
        
        FILE *temp = fopen("temp.txt", "w");
        if (temp == NULL) {
          fclose(datei);
          perror("Fehler: Temporäre Datei konnte nicht geöffnet werden!");
          return 1;
        }

        int aktuelleNummer = 1;
        int gefunden = 0;
        char zeile[100];

        while(fgets(zeile, sizeof(zeile), datei)!= NULL) {
          if (aktuelleNummer == nummerÖffnen) {
            gefunden = 1;

            if (zeile[0] == 'e') {
              zeile[0] = 'o';
            }
          }
          fprintf(temp,"%s",zeile);
          aktuelleNummer++;
        }
        if ( gefunden == 0) {
          fclose (datei);
          fclose (temp);
          remove ("temp.txt");

          fprintf(stderr, "Fehler: Falsche Aufgabennummer angegeben!\n");
          return 1;
        }

        fclose (datei);
        fclose (temp);

        if (rename("temp.txt", "todo.txt") != 0) {
          perror("Fehler: Datei konnte nicht ersetzt werden.");
          return 1;
        }
        printf ("Aufgabe %ld wurde wieder geöffnet.\n", nummerÖffnen);
        break;
      }

    case 'U': {
    FILE *datei = fopen("todo.txt", "r");

    if (datei == NULL) {
        perror("Fehler: Datei konnte nicht geöffnet werden.");
        return 1;
    }

    int aktuelleNummer = 1;
    char zeile[100];

    printf("Folgende Aufgaben müssen noch erledigt werden:\n");

    while (fgets(zeile, sizeof(zeile), datei) != NULL) {

        if (zeile[0] == 'o') {
            printf("%d. [ ] %s", aktuelleNummer, &zeile[1]);
        }

        aktuelleNummer++;
    }

    fclose(datei);
    break;
}

    case 'C': {
      FILE *datei = fopen("todo.txt", "r");
        if (datei == NULL) {
          perror("Fehler: Datei konnte nicht geöffnet werden");
          return 1;
        }
        int aktuelleNummer = 1;
        char zeile[100];

        printf("Folgende Aufgaben sind schon erledigt:\n");

        while (fgets(zeile, sizeof(zeile), datei) != NULL) {
          if (zeile[0] == 'e') {
            printf("%d. [x] %s", aktuelleNummer, &zeile[1]);
          }
          aktuelleNummer++;
        }
        fclose(datei);
        break;
    }

    case ':':
      fprintf(stderr, "Fehler: Erforderliches Argument fehlt.\n");
      return 1;

    case '?':
      fprintf(stderr, "Fehler: Unbekanntes Flag!\n");
      return 1;
    }
  }

  return 0;
}
}