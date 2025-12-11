/*
Aufgabe 2.10: Zweierpotenzen
Entwickeln Sie einen Algorithmus (Darstellung bleibt Ihnen überlassen), der in einer Schleife
2er Potenzen 2n ausgibt für n=0,...,10. Verwenden Sie dabei nicht die pow() Funktion.
Erwartete Ausgabe:
2^0 = 1
2^1 = 2
2^2 = 4
...
2^9 = 512
2^10 = 1024
*/

#include <stdio.h>

int main () {
    int exponent;
    printf("What exponent of 2 would you like to print? - ");
    scanf("%d", &exponent);

    for (int i = 0; i <= exponent; i++) {
        printf("2^(%d) = %d\n", i, 1 << i);
    }
}