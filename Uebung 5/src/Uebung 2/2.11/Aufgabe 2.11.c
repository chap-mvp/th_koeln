/*
Aufgabe 2.11: Fakultät berechnen
Schreiben Sie ein Programm, das eine Zahl n einliest, dazu die Fakultät n! berechnet und
das Ergebnis am Terminal ausgibt. Bis zu welcher Zahl n liefert das Programm das richtige
Ergebnis, ab wann liefert es nicht mehr das richtige Ergebnis und woran liegt das?
Testdaten:
Eingabe n: 10
Erwartete Ausgabe:
10! = 3.628.800
*/

#include <stdio.h>

int main () {
    int factorial = 1, inputNumber;
    printf("What number factorial do you want? - ");
    scanf("%d", &inputNumber);
    for (int i = 1; i <= inputNumber; i++) {
        factorial *= i;
        printf("\n%d! = %d", i, factorial);

    }

    printf("\n%d! = %d", inputNumber, factorial);

    return 0;
}

// keine werte nach 16! wegen overflow (2^31 ~ 21 mio.)