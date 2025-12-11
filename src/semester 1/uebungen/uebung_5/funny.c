#include <stdio.h>

void add(int *a, int *b, int *sum)
{
    *sum = *a + *b;
}

int main()
{
    int num1;
    int num2;
    printf("\nEnter the first value - ");
    scanf("%d", &num1);
    printf("\nEnter the second value - ");
    scanf("%d", &num2);

    int final;

    add(&num1, &num2, &final);
    printf("\nSum: %d", final);
}