/*
Aufgabe 2.12: n bei gegebener n! bestimmen
Schreiben Sie ein Programm, das eine Zahl einliest und überprüft, ob diese Zahl das
Ergebnis einer Fakultätsberechnung n! ist, mit n=0,…,10? Geben Sie in dem Fall n aus,
andernfalls -1.
Testdaten:
Eingabe 1: myFak: 3.628.800
Eingabe 2: myFak: 3.628.799
Erwartete Ausgabe 1: n = 10
Erwartete Ausgabe 2: n = -1
*/

#include <stdio.h>

int factorial(int inputNumber)
{
    int input;
    int factorial = 1;

    for (int i = 1; i <= 16; i++)
    {
        factorial *= i;

        if (factorial == inputNumber)
        {
            printf("\nYes, %d is a factorial of %d!", inputNumber, i);
            return 0;
        }
    }

    printf("\nNo, %d is not a product of factorials!", inputNumber);
    return 0;
}

int main()
{
    int functionValue;
    printf("What number would u like to check the factorial of? - ");
    scanf("%d", &functionValue);

    factorial(functionValue);

    return 0;
}