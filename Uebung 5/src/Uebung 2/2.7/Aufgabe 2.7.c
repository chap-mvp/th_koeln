/*
Aufgabe 2.7: Standardbibliotheken über Header Datei einbinden
Entwerfen Sie einen Algorithmus, der nRoll mal einen Würfelwurf simuliert und die Summe
der Augenzahlen summiert und am Ende (wenn nRoll mal gewürfelt wurde) die Summe
ausgibt. Recherchieren Sie im Internet nach einer geeigneten Bibliothek (bzw. einer Funktion
daraus), um eine Zufallszahl zu generieren. Setzen Sie diesen Algorithmus in C um. Die
Variable nRoll kann entweder im Programm definiert werden oder aber über scanf()
eingelesen werden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));

    int nRoll;
    int sum = 0, min = 1, max = 6;

    printf("\nHow many times would you like to roll? - ");
    scanf("%d", &nRoll);

    for (int i = 1; i <= nRoll; i++) {
        int r = rand() % max + min;
        sum = sum + r;
        printf("\nR_%d = %d: Sum = %d", i, r, sum);
    }

}