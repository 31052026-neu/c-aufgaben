```C
#include <stdio.h>

int main() {

// Array mit den Zahlen, die wir untersuchen möchten.
// Die Indizes sind:
// Index: 0 1 2 3 4 5 6 7 8
// Wert: 1 3 2 4 0 9 1 1 4
int a[9] = {1, 3, 2, 4, 0, 9, 1, 1, 4};

// Dieses Array dient als Zähler.
// Jeder Index steht für eine Zahl.
//
// zaehler[0] zählt, wie oft die 0 vorkommt.
// zaehler[1] zählt, wie oft die 1 vorkommt.
// ...
// zaehler[9] zählt, wie oft die 9 vorkommt.
//
// Alle Werte werden zu Beginn auf 0 gesetzt,
// weil wir noch keine Zahl gezählt haben.
int zaehler[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Diese Variable wird im Programm nicht benutzt
// und könnte deshalb entfernt werden.
int number = 0;

// Die Schleife läuft durch jedes Element des Arrays "a".
//
// i ist der Index des Arrays.
// Beim Durchlaufen hat i nacheinander die Werte:
// 0,1,2,3,4,5,6,7,8
for (int i = 0; i < 9; i++) {

    // a[i] liefert den aktuellen Wert aus dem Array.
    //
    // Beispiel:
    // i = 0 -> a[0] = 1
    // i = 1 -> a[1] = 3
    // i = 2 -> a[2] = 2
    //
    // Dieser Wert wird gleichzeitig als Index
    // für das Zähler-Array verwendet.
    //
    // Beispiel:
    // a[0] = 1
    // -> zaehler[1]++
    //
    // Das bedeutet:
    // "Die Zahl 1 wurde gefunden.
    // Erhöhe den Zähler für die 1 um eins."
    zaehler[a[i]]++;

}

// Jetzt geben wir die Ergebnisse aus.
//
// j nimmt nacheinander die Werte
// 0,1,2,3,4,5,6,7,8,9 an.
for (int j = 0; j < 10; j++) {

    // j ist die Zahl, über die wir gerade sprechen.
    //
    // zaehler[j] enthält,
    // wie oft diese Zahl gefunden wurde.
    //
    // Beispiel:
    // j = 1
    // -> zaehler[1] = 3
    //
    // Ausgabe:
    // "1 kommt 3 mal vor."
    printf("%d kommt %d mal vor.\n", j, zaehler[j]);

}

return 0;
}
```
