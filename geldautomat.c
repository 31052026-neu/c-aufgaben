#include <stdio.h>

int main() {

    int balance = 1000;
    int amount;
    int daily_limit = 500;

    printf("Gewünschter Abhebungsbetrag\n");
    scanf("%d",&amount);

    if (amount <= 0) {
        printf("Ungültiger Betrag\n");
        return 1;
    }
    if (amount > balance) {
        printf("Gewünschter Betrag kann aufgrund ungenügender Deckung nicht ausbezahlt werden!\n");
        return 1;
    }
    if (amount > daily_limit) {
        printf("Gewünschter Betrag kann nicht ausbezahlt werden!\n");
        return 1;
    }
    printf("Gewünschter Bertrag wird ausbezahlt!\n");
    return 0;
}