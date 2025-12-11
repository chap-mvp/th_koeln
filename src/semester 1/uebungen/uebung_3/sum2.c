#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a[2][2][2];
    int b[2][2] = {0};

    int size_a = sizeof(a) / sizeof(a[0][0][0]);
    int size_b = sizeof(b) / sizeof(b[0][0]);

    int *p_a = &a[0][0][0];
    int *p_b = &b[0][0];

    for (int i = 0; i < size_a; i++)
        *(p_a + i) = rand() % 11;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
            {
                b[i][j] += a[i][j][k];
            }

    printf("Array a:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                printf("a[%d][%d][%d] = %d\n", i, j, k, a[i][j][k]);

    printf("\nArray b:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("b[%d][%d] = %d\n", i, j, b[i][j]);
}