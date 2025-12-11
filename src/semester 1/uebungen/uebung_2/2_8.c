/*
Aufgabe 2.8: ASCI/ANSI
Weisen Sie in einem C Programm nach, dass das Zeichen "g" tatsächlich als 0b1100111
abgelegt wird. Erweitern Sie dieses Programm, um zu bestimmen, wie "G" abgespeichert
wird und überprüfen anhand einer weiteren Kleinbuchstaben-Großbuchstaben-Paarung, ob
auch hier der Abstand 32 beträgt.
*/

#include <stdio.h>
#include <math.h>

int main()
{

    char large[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char small[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int charSize = sizeof(large);

    for (int i = 0; i < charSize; i++)
    {
        printf("|%d - %d| = %d (%c & %c)\n", large[i], small[i], abs(large[i] - small[i]), large[i], small[i]);       
    }
}