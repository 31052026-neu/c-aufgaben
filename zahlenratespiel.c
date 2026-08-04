#include <stdio.h>

int main() {

    int geheime_zahl = 23;
    int eingabe;
    printf("Gib eine Zahl ein, von der du denkst sie wäre die Geheime Zahl: ");
    scanf("%d", &eingabe );

    if(eingabe == geheime_zahl) {
        printf("richtig!\n");
    }
    else if(eingabe < geheime_zahl) {
        printf("Die Zahl ist kleiner als die geheime Zahl!\n");
    }
    else if(eingabe > geheime_zahl) {
        printf("die Zahl ist größer als die geheime Zahl\n");

    }

    

    return 0;
}