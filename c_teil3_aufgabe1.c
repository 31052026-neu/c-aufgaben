#include <stdio.h>

int main(int argc, char*argv[] ) {
    if (argc !=2) {
        printf("Fehler: Bitte genau einen Dateinamen angeben.\n");
        return 1;
    }
    FILE *datei;
    datei = fopen(argv[1],"r");

    if (datei == NULL) {
        perror("Fehler beim Öffnen der Datei");
        return  2;
    }
    int zeichen;
    int woerter = 0;
    int kwoerter = 0;
    while ((zeichen = fgetc(datei)) != EOF) {
        if (zeichen == ' '  || zeichen == '\n' || zeichen == '\t') {
            kwoerter = 0;
        }
    else if (kwoerter == 0) {
        woerter ++;
        kwoerter = 1;
    }
}
printf("woerter: %d\n",woerter);

    fclose(datei);
    return 0;

}