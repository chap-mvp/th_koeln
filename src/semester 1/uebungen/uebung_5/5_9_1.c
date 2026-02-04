#include <stdio.h>

void doubleArrayElements(const int arrayOne[], int arrayTwoTimes[], int size)
{
    for (int i = 0; i < size; i++)
        arrayTwoTimes[i] = 2 * arrayOne[i];
}

int main(void)
{
    int arrayOne[] = {1, 2, 3, 4, 5};
    int arrayTwoTimes[5];
    int size = 5;

    doubleArrayElements(arrayOne, arrayTwoTimes, size);

    printf("Original:  ");
    for (int i = 0; i < size; i++)
        printf("%d ", arrayOne[i]);

    printf("\n");

    printf("Doubled:   ");
    for (int i = 0; i < size; i++)
        printf("%d ", arrayTwoTimes[i]);

    printf("\n");

    return 0;
}