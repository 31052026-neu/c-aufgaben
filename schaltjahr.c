#include <stdio.h>

int main() {
    int jahr;

    printf("Gib ein Jahr ein: ");
    scanf("%d", &jahr);

    if (jahr % 400 == 0) {
        printf("Dieses Jahr ist ein Schaltjahr.\n");
    }
    else if (jahr % 100 == 0) {
        printf("Dieses Jahr ist kein Schaltjahr.\n");
    }
    else if (jahr % 4 == 0) {
        printf("Dieses Jahr ist ein Schaltjahr.\n");
    }
    else {
        printf("Dieses Jahr ist kein Schaltjahr.\n");
    }

    return 0;
}