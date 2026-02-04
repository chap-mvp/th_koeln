/*
4.1 Datentyp float und der Debugger
a) Schreiben Sie das folgende C-Programm und starten es im Debugmodus.

float x = 0.0;
x = 1 - 10 * (1 - 0.9);
if (x < 0)
{
    printf("x < %0.2lf", x);
}
else if (x > 0)
{
    printf("x > %0.2lf", x);
}
else
{
    printf("x == %0.2lf", x);
}

Was wird nach der Ausführung des Programms ausgegeben? Wie kommt es zu dieser Ausgabe? Erstellen Sie im Debugmodus einen Screenshot der Variablen x bezüglich seines Wertes nach der Zuweisung.

b) Schreiben Sie ein C-Programm, das eine short Zahl sNumber deklariert und von der Tastatur eine int-Zahl iNumber einliest. Anschließend soll wie folgt eine Zuweisung mit einer impliziten Typumwandlung (TypeCast) erfolgen:
sNumber=iNumber;
Was wird nach der Ausführung des Programms ausgegeben? Wie kommt es zu dieser Ausgabe? Im Debugmodus, erstellen Sie einen Screenshot der Werte der Variablen iNumber und der Variablen sNumber nach dem impliziten TypeCast.
1. iNumber = 11500
2. iNumber = 1114112
3. iNumber = 17892934
Was wird nach der Ausführung des Programms ausgegeben? Wie kommt es zu dieser Ausgabe? Im Debugmodus, erstellen Sie einen Screenshot der Variablen iNumber und der Variablen sNumber bezüglich seines Wertes nach dem impliziten cast.

c) Schreiben Sie ein C-Programm, das von der Tastatur zwei short-Zahlen Kapital und Zins einliest und anschließend den Zinsfuß berechnet:
p = (Zins * 100); //Zeile 1
p = p / Kapital;  //Zeile 2
Das Programm soll den Benutzer auffordern, einen Wert für Kapital und Zins einzugeben. Bei der Ausgabe soll die Rechenoperation und das Ergebnis angezeigt werden. Würde man beispielsweise für Kapital 10000 und für Zins 400 eingegeben, so soll die Ausgabe wie
folgt aussehen:
P = (400 * 100) / 10000 = 4
Testen Sie Ihr Programm im Debugmodus auch für Kapital = 320 , Zins = 50 und Kapital = 4500 , Zins = 100.

Was  wird  nach  der  Ausführung  des  Programms  ausgegeben?  Wie  kommt  es  zu  dieser Ausgabe? Im Debugmodus erstellen Sie einen Screenshot der Variablen p, Zins und Kapital bezüglich seines Wertes in Zeile 1 und Zeile 2.
*/

#include <stdio.h>

int main()
{
    float x = 0.0;
    short sNumber;
    printf("Enter your short number");
    scanf("%d", &sNumber);
    x = 1 - 10 * (1 - 0.9);
    if (x < 0)
    {
        printf("x < %0.2lf", x);
    }
    else if (x > 0)
    {
        printf("x > %0.2lf", x);
    }
    else
    {
        printf("x == %0.2lf", x);
    }

    short sNumber;
    int iNumber;
    scanf("%d", &iNumber);
    sNumber = iNumber;
    printf("iNumber: %d, sNumber: %d\n", iNumber, sNumber);

    short Kapital, Zins, p;
    scanf("%hd %hd", &Kapital, &Zins);
    p = (Zins * 100); // Line 1
    p = p / Kapital;  // Line 2
    printf("P = (%d * 100) / %d = %d\n", Zins, Kapital, p);
}