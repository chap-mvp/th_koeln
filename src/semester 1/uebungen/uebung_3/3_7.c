/*
Strings sind eine Array vom Datentyp char. Daher ist es auch möglich, ein Array von Strings zu erstellen und damit zu arbeiten
Was passiert, wenn X und/oder Y zu gering gewählt werden und woran liegt das? 
Nutzen Sie die Funktion strcmp(), um das Array anschließend alphabetisch zu sortieren und 
sortiert auszugeben.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char names[5][15] = {"Mustermann", "Bracht", "Zimmermann", "Schneider", "Ackermann"};
    char temp[15];

    int min_index = 0;

    for (int i = 0; i < 5 - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(names[j], names[min_index]) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            strcpy(temp, names[i]);
            strcpy(names[i], names[min_index]);
            strcpy(names[min_index], temp);
        }
    }

    for (int i = 0; i < 5; i++)
        printf("%s\n", names[i]);
}
