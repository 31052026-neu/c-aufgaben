#include <stdio.h> 
int main()
{
    int  eingabe1;
    int  eingabe2;
    int  eingabe3;

    printf("Gib drei verschiedene Zahlen ein: ");

    scanf("%d", &eingabe1);

    scanf("%d", &eingabe2);

    scanf("%d", &eingabe3);
    if (eingabe1 == eingabe2 && eingabe1 == eingabe3) {         //
        printf("Alle Zahlen sind gleich\n");
    }
    else if (eingabe1 >= eingabe2 && eingabe1 >= eingabe3) {
        printf("Die größte Zahl ist %d\n", eingabe1);

    }
    else if (eingabe2 >= eingabe1 && eingabe2 >= eingabe3 ) {
        printf("Die größte Zahl ist %d\n", eingabe2);
    }
    else {
        printf("Die größte Zahl ist %d\n",eingabe3);
    }
    return 0;
}