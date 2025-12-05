/*
Aufgabe 2.10: Zweierpotenzen
Entwickeln Sie einen Algorithmus (Darstellung bleibt Ihnen überlassen), der in einer Schleife
2er Potenzen 2n ausgibt für n=0,...,10. Verwenden Sie dabei nicht die pow() Funktion.
Erwartete Ausgabe:
20 = 1
21 = 2
22 = 4
...
29 = 512
210 = 1024
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