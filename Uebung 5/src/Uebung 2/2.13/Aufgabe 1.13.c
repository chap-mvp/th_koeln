/*
Aufgabe 2.13: Dezimalzahlzerlegung
Gegeben ist eine Zahl z vom Datentyp int, deren Wert zwischen 0 und 999 liegt.
Ermitteln Sie den Wert der Hunderter-, Zehner- und Einerziffer von z und speichern Sie diese
in den drei Variablen zH, zZ und zE ab. Geben Sie die jeweiligen Werte auf dem Bildschirm
aus.
Testdaten:
Eingabe z: 15
Erwartete Ausgabe:
15 = 0 x 100 + 1 x 10 + 5 x 1
*/

#include <stdio.h>

int main()
{
    char number[2];
    int digit[100];
    int i = 0;

    printf("Input your number: ");
    scanf("%s", number);

    number[0] = digit[0];

    if (digit[0] != 0)
    {
        printf("100 * %d + ", digit[0]);
    }
    else
    {
        printf("100 * %d + ", digit[0]);
    }

    if (digit[1] != 0)
    {
        printf("10 * %d + ", digit[1]);
    }
    else
    {
        printf("10 * %d + ", digit[1]);
    }

    if (digit[2] != 0)
    {
        printf("1 * %d = ", digit[2]);
    }
    else
    {
        printf("1 * %d = ", digit[2]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d", digit[i]);
    }
}
