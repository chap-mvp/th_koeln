#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Zufallsgenerator initialisieren
    srand(time(NULL));

    // 1. Array für 10 Elemente allokieren
    int size = 10;
    double *array = (double *)malloc(size * sizeof(double));

    if (array == NULL)
    {
        printf("Fehler: Speicher konnte nicht allokiert werden!\n");
        return EXIT_FAILURE;
    }

    // Initialisieren mit Zufallswerten zwischen 0 und 1
    printf("Erste 10 Elemente (0 bis 1):\n");
    for (int i = 0; i < 10; i++)
    {
        array[i] = (double)rand() / RAND_MAX; // Werte zwischen 0 und 1
        printf("array[%d] = %.4f\n", i, array[i]);
    }

    // 2. Array um 5 Elemente erweitern
    size = 15;
    double *temp = (double *)realloc(array, size * sizeof(double));

    if (temp == NULL)
    {
        printf("Fehler: Speicher konnte nicht erweitert werden!\n");
        free(array);
        return EXIT_FAILURE;
    }
    array = temp;

    // Neue Elemente mit Zufallswerten zwischen 1 und 2
    printf("\nNeue 5 Elemente (1 bis 2):\n");
    for (int i = 10; i < 15; i++)
    {
        array[i] = 1.0 + (double)rand() / RAND_MAX; // Werte zwischen 1 und 2
        printf("array[%d] = %.4f\n", i, array[i]);
    }

    // 3. Komplettes Array ausgeben
    printf("\n=== Komplettes Array ===\n");
    for (int i = 0; i < size; i++)
    {
        printf("array[%d] = %.4f\n", i, array[i]);
    }

    // 4. Speicher freigeben
    free(array);
    printf("\nSpeicher erfolgreich freigegeben.\n");

    return EXIT_SUCCESS;
}