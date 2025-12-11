/*
Aufgabe 3.2: Wahr oder falsch? 
Erklären Sie, welches Ergebnis der folgende Code liefert und was das mit Typumwandlung 
zu tun hat.

#include <stdio.h>

int main()
{
    int isTrue = 42;
    if (isTrue)
    {
        printf("Es ist wahr\n");
    }
    else
    {
        printf("Es ist nicht wahr;");
    }

    return EXIT_SUCCESS;
}

Implizite Typumwandlung zwischen booleschen (0/1) Werten und Integer
*/