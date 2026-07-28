#include <stdio.h>

int main() {
    int jahr;

    printf("Gib ein Jahr ein, um zu errechnen welches Jahr ein Schaltjahr ist!: ");                           // das ist immer meine Information die ich dem User gebe
    scanf("%d", &jahr);

    if (jahr % 400 == 0) {                                  //hier gebe ich an "wenn das Jahr durch 400 teilbar ist ohne rest"
        printf("Dieses Jahr ist ein Schaltjahr.\n");                
    }
    else if (jahr % 100 == 0) {                             //hier gebe ich an " wenn das Jahr durch 100 teilbar ist ohne rest"
        printf("Dieses Jahr ist kein Schaltjahr.\n");
    }
    else if (jahr % 4 == 0) {                               //hier gebe ich an "wenn das Jahr durch 4 teilbar ist ohne rest"
        printf("Dieses Jahr ist ein Schaltjahr.\n");
    }
    else {                                                  //wenn keines der vorherigen else if`s eintritt dann kommt das "else" ins spiel
        printf("Dieses Jahr ist kein Schaltjahr.\n");
    }

    return 0;
}