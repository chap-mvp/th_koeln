/*
Aufgabe 2.5: Kompilierung eines einfachen Programms
Setzen Sie den folgenden PAP als C Programm um, kompilieren Ihren Code und zeigen
sowohl Terminalein-/-ausgabe als auch die Hinweise des Compilers.
*/

#include <stdio.h>

int main()
{
    int countOdd = 0, countEven = 0, i = 0;

    while (i <= 5)
    {

        int termVariable;
        printf("What number would you like to check? - ");
        scanf("%d", &termVariable);

        if (termVariable % 2 == 0)
        {
            countEven++;
            printf("The number %d is divisible by 2\n", termVariable);
        }
        else
        {
            countOdd++;
            printf("The number %d is NOT divisible by 2\n", termVariable);
        }
        i++;
    }

    printf("countOdd: %d\ncountEven: %d", countOdd, countEven);

    return 0;
}
