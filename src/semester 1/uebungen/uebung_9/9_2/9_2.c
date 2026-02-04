#include <stdio.h>
#include <stdlib.h>
#include "statistics.h"

int main(void)
{
    // Test data
    float measurements[] = {5.2, 3.8, 7.1, 2.9, 6.5, 4.3, 8.0, 3.2, 5.9, 6.8};
    int size = 10;

    printf("=== Statistical Analysis ===\n\n");

    printf("Measurements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", measurements[i]);
    }
    printf("\n\n");

    // Calculate statistics
    printf("Maximum:    %.2f\n", getMaximum(measurements, size));
    printf("Minimum:    %.2f\n", getMinimum(measurements, size));
    printf("Mean:       %.2f\n", getMean(measurements, size));
    printf("Variance:   %.2f\n", getVariance(measurements, size));

    // Copy array for median (since it gets sorted)
    float measurementsCopy[10];
    for (int i = 0; i < size; i++)
    {
        measurementsCopy[i] = measurements[i];
    }
    printf("Median:     %.2f\n", getMedian(measurementsCopy, size));

    return EXIT_SUCCESS;
}