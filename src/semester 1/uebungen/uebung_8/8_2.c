#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    double *array = (double *)malloc(10 * sizeof(double));

    if (array == NULL)
    {
        printf("Array was not allocated!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++)
    {
        array[i] = (double)rand() / RAND_MAX;
        printf("array[%d] = %.4f\n", i, array[i]);
    }

    double *temp = (double *)realloc(array, 15 * sizeof(double));

    if (temp == NULL)
    {
        printf("Array was not allocated!\n");
        free(array);
        return EXIT_FAILURE;
    }
    array = temp;

    for (int i = 10; i < 15; i++)
    {
        array[i] = 1 + (double)rand() / RAND_MAX;
        printf("array[%d] = %.4f\n", i, array[i]);
    }

    printf("Whole array:\n");
    for (int i = 0; i < 15; i++)
    {

        printf("array[%d] = %.4f\n", i, array[i]);
    }

    free(array);
    printf("Array has been emptied!\n");

    return EXIT_SUCCESS;
}