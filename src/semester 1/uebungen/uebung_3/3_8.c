/*
Das Ziehen der Lottozahlen soll realisiert werden, in folgenden Teilschritten:
a)  Definieren Sie ein Feld für 6 Lottozahlen.
b)  Initialisieren Sie den Zufallszahlengenerator, so dass er jedes Mal neue Zahlenserien erzeugt.
c)  In einer Schleife sollen 6 zufällige Zahlen zwischen 1 und 49 erzeugt werden.
d)  Geben Sie anschließend die Zahlen aus.

Es gibt noch ein kleines Problem: Es könnte sei, dass die gleichen Zahlen mehrmals
generiert werden, aber die Lottozahlen können nur einmal vorkommen. Entwerfen Sie einen
Algorithmus, um dieses Problem zu beheben.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int lotteryNumbers[6] = {0};

    // Generate random numbers
    for (int i = 0; i < 6; i++)
        lotteryNumbers[i] = 1 + (rand() % 49 - 1 + 1);

    // Check for doubles and fix
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (lotteryNumbers[i] == lotteryNumbers[j])
                lotteryNumbers[i] = 1 + (rand() % 49 - 1 + 1);

    for (int i = 0; i < 6; i++)
        printf("[%d] ", lotteryNumbers[i]);
}
