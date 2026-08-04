#include <stdio.h>
int main() {
    int balance = 300;
    int amaount;
    int amount = 500;

    printf("Gewünschter Auszahlungsbetrag\n");
    scanf("%d",&amount);

    if(amount <=0) {
        printf("Ungültiger Betrag\n");
    }
    else if(amount >500) {
        printf("Tageslimit überschritten!\n");
    }
    else if(amount > balance) {
        printf("Keine ausreichende Deckung!\n");
    }
    else {
        puts("Betrag wird ausbezahlt");
    }
    return 0;
}