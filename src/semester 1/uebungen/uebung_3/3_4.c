#include <stdio.h>

int sortArrayDescending(int sortArray[], int sizeArray)
{
    for (int i = 0; i < sizeArray - 1; i++)
    {
        for (int j = 0; j < sizeArray - i - 1; j++)
        {
            if (sortArray[j] < sortArray[j + 1])
            {
                // Vertausche die Elemente, um in absteigender Reihenfolge zu sortieren
                int temp = sortArray[j];
                sortArray[j] = sortArray[j + 1];
                sortArray[j + 1] = temp;
            }
        }
    }
    return 0;
}

int main()
{
    int myArray[] = {5, 2, 9, 1, 5, 6};
    int length = sizeof(myArray) / sizeof(myArray[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", myArray[i]);
    }

    sortArrayDescending(myArray, length);

    printf("\nAfter sorting (decreasing order):\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", myArray[i]);
    }

    int median;

    if (length % 2 == 0) {
        median = (myArray[length/2 - 1] + myArray[length/2])/2;
    } else {
        median = myArray[(length)/2];
    }

    printf("\n%d is the median.", median);
    return 0;
}