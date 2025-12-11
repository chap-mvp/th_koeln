#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size = 0;
    int a[size][size][size];
    int b[size][size];

    // srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("[%d] ", b[j][i]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < size; i++) // depth
    {
        for (int j = 0; j < size; j++) // row
        {
            for (int k = 0; k < size; k++) // col
            {
                a[k][j][i] = rand() % 11;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                b[j][i] = b[j][i] + a[k][j][i];
            }
            printf("%d + %d + %d = %d \n", a[i][j][0], a[i][j][1], a[i][j][2], b[j][i]);
        }
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                printf("[%d] ", a[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Array a:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                printf("a[%d][%d][%d] = %d\n", i, j, k, a[i][j][k]);

    printf("\nArray b:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            printf("b[%d][%d] = %d\n", i, j, b[i][j]);
}
