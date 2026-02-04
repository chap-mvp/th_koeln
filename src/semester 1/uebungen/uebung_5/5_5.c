#include <stdio.h>

#define MAX_RESISTORS 10

int readResValue(float resistances[], int maxCount)
{
    int count;

    printf("How many resistors do you want to enter (max %d)? ", maxCount);
    scanf("%d", &count);

    if (count < 1 || count > maxCount)
    {
        printf("Invalid count. Setting to 1.\n");
        count = 1;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Enter resistance value %d (Ohm): ", i + 1);
        scanf("%f", &resistances[i]);
    }

    return count;
}

float calcEquiRes(float resistances[], int count)
{
    float sum = 0.0;

    for (int i = 0; i < count; i++)
        if (resistances[i] != 0)
            sum += 1.0 / resistances[i];

    if (sum == 0)
        return 0.0;

    return 1.0 / sum;
}

int main(void)
{
    float resistances[MAX_RESISTORS];
    int count;

    printf("=== Parallel Resistance Calculator ===\n\n");

    count = readResValue(resistances, MAX_RESISTORS);

    printf("\nEntered resistances:\n");
    for (int i = 0; i < count; i++)
        printf("  R%d = %.2f Ohm\n", i + 1, resistances[i]);

    float equivalent = calcEquiRes(resistances, count);

    printf("\nEquivalent parallel resistance: %.2f Ohm\n", equivalent);
}