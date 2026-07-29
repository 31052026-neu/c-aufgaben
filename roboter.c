#include <stdio.h>

int main() {
    int glücklich = 1;
    int traurig = 2;
    int müde = 3;
    int verwirrt = 4;
    int zustand = traurig;
    int befehl;

    printf("Gib eine Zahl ein um einen Befehl durchzuführen!: \n");
    scanf("%d", &befehl);

    printf("Der Roboter ist glücklich.\n");
    
    if (befehl == 1) {
        printf(" Der Roboter blinkt fröhlich!\n");
    }
    else if (befehl == 2) {
        printf("Der Roboter dreht sich!\n");
    }
    else if (befehl == 3) {
        printf("Der Roboter hupt!\n");
    }
    else {
        printf("Befehl ist ungültig!\n");
    }

    return 0;
}