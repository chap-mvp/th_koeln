/*
Aufgabe 2.9: Endlosschleife umschreiben
Wie kann man folgenden Programmteil so umschreiben, dass keine Endlosschleife
verwendet wird. Erweitern Sie den Code dann so, dass nach Verlassen der while-Schleife
ausgegeben wird, wie oft diese durchlaufen wurde.

int zahl, summe = 0;
printf("Summenberechnung\nBeenden der Eingabe mit -1\n");
while (1)
{
    printf("Bitte Wert eingeben > ");
    scanf("%d", &zahl);
    if (zahl == -1)
        break;
    else
        summe += zahl;
}
printf("Die Summe aller Werte beträgt: %d\n", summe);


*/


#include <stdio.h>

int main()
{
    int zahl, summe = 0;
    printf("Summenberechnung\nBeenden der Eingabe mit -1\n");
    while (1)
    {
        printf("Bitte Wert eingeben > ");
        scanf("%d", &zahl);
        if (zahl == -1)
            break;
        else
            summe += zahl;
    }
    printf("Die Summe aller Werte beträgt: %d\n", summe);
}
