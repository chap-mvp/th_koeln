/*
Aufgabe 2.14: Umwandlung Dezimal- in Hexadezimalzahl
Entwickeln sie einen Algorithmus zur Umrechnung einer positiven Dezimalzahl in eine
Hexadezimalzahl und setzen sie diesen in der Programmiersprache C um.
• Lesen Sie die umzurechnende Zahl als integer-Wert von der Tastatur ein.
• Ermitteln sie die Hexadezimalziffern und speichern sie diese als ASCII-Zeichen in
den vier char-Variablen HexZiffer3, HexZiffer2, HexZiffer1 und HexZiffer0 ab
• Geben sie die Ziffern auf dem Bildschirm aus.
 */


#include <stdio.h>


int main () {
    int value;

    printf("Which number would you like to convert into HEX? - ");
    scanf("%u", &value);

    char hex[] = {value};

    printf("\n0x%X", value);
}