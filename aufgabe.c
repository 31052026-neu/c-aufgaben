#include <stdio.h>

int main() 
{


    int A;
    int B;
    
    printf("\nAND\n");                                //*Der erste Absatz zeigt an was in der Kopfzeile stehen soll//
    printf("A | B | A AND B\n");
    printf("----------------\n");

    A = 0;                                          //*Hier gebe ich den Variablen einen Wert//
    B = 0;
    printf("%d | %d | %d\n", A, B, A && B);         //* Hier steht die funktion, die ausgeführt werden soll. "wenn A und B falsch sind dann muss die ausgabe auch falsch sein"

    A = 0;
    B = 1;
    printf("%d | %d | %d\n", A, B, A && B);

    A = 1;
    B = 0;
    printf("%d | %d | %d\n", A, B , A && B);

    A = 1;
    B = 1;
    printf("%d | %d | %d\n", A, B, A && B);
    

    printf("\nOR\n");                                 // Hier fängt die nächste Tabelle an und zeigt mir die angegebene Kopfzeile an//
    printf("A | B | A OR B\n");
    printf("---------------\n");

    A = 0;
    B = 0;
    printf ("%d | %d | %d\n", A, B, A || B);

    A = 0;
    B = 1;
    printf("%d | %d | %d\n", A, B, A || B);

    A = 1;
    B = 0;
    printf("%d | %d | %d\n", A, B, A || B);

    A = 1;
    B = 1;
    printf("%d | %d | %d\n", A, B, A || B);

    printf("\nXOR\n");
    printf("A | B | A XOR B\n");
    printf("----------------\n");

    A = 0;
    B = 0;
    printf("%d | %d | %d\n", A, B, (A && !B) || (!A && B));

    A = 0;
    B = 1;
    printf("%d | %d | %d\n", A, B, (A && !B) || (!A && B));

    A = 1;
    B = 0;
    printf("%d | %d | %d\n", A, B, (A && !B) || (!A && B));

    A = 1;
    B = 1;
    printf("%d | %d | %d\n", A, B, (A && !B) || (!A && B));

    printf("\nNOT\n");
    printf("A | B | A NOT B\n");
    printf("----------------\n");

    A = 0;
    B = 0;
    printf("%d | %d | %d\n", A, B, !A );
    
    A = 0;
    B = 1;
    printf("%d | %d | %d\n", A, B ,!A);

    A = 1;
    B = 0;
    printf("%d | %d | %d\n", A, B ,!A);

    A = 1;
    B = 1;
    printf("%d | %d | %d\n", A, B ,!A);

     return 0;

}