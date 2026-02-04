#include <stdio.h>

#define VALUE 5 // Remove ;

int main()
{

    // a)
    int k = 0, i = 0; // Initialize k to 0
    for (i = 0; i < 10; i++)
    {
        k = k + 1;
    }
    printf("%d", k);

    // b)
    int a = 0;
    int b = 0;
    int sum = a + b; // Sum was undeclared
    printf("sum: %d", sum);

    // c)
    int a = 0;
    scanf("%d", &a); // & missing
    printf("Der Wert von a: %d", a);
    return 0;

    // d)
    int k = 0;
    for (int i = 0; i < 10; ++i)
    {
        k += 1; // or k = k + 1; // k soll hoch zaehlen
    }

    // e)
    int i = VALUE + 1;
    printf("%d\n", i);
    return 0;

    // f)
    // fuehre Schleife 12x aus
    for (int i = 0; i < 12; ++i) // Runs exactly 12 times
    {
        //..
    }

    // g)
    int zahl = 1;
    switch (zahl) // break; was missing
    {
    case 1:
        zahl = zahl + 1;
        break;
    case 2:
        zahl = zahl + 2;
        break;
    case 3:
        zahl = zahl + 3;
        break;
    }
    printf("Die doppelte Zahl lautet %d\n", zahl);

    // h)
    int zahl = 1;
    if (zahl == 1) // Else if instead of if
    {
        zahl = zahl + 1;
    }
    else if (zahl == 2)
    {
        zahl = zahl + 2;
    }
    else if (zahl == 3)
    {
        zahl = zahl + 3;
    }
    printf("Die doppelte Zahl lautet %d\n", zahl);

    // i)
    int dividend = 6;
    int divisor = 4;
    float result = (float)dividend / (float)divisor; // add (float) cast
    printf("Das Ergebnis lautet %f\n", result);
}