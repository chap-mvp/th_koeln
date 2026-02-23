#include "statistics.h"
#include <float.h>
#include <math.h>

static void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

float getMaximum(const float data[], int size)
{
    if (size <= 0)
        return 0.0;

    float max = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > max)
            max = data[i];

    return max;
}

float getMinimum(const float data[], int size)
{
    if (size <= 0)
        return 0.0;

    float min = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] < min)
            min = data[i];

    return min;
}

float getMean(const float data[], int size)
{
    if (size <= 0)
        return 0.0;

    float sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += data[i];

    return sum / size;
}

float getVariance(const float data[], int size)
{
    if (size <= 0)
        return 0.0;

    float mean = getMean(data, size);
    float sumSquaredDiff = 0.0;

    for (int i = 0; i < size; i++)
    {
        float diff = data[i] - mean;
        sumSquaredDiff += diff * diff;
    }

    return sumSquaredDiff / size;
}

float getMedian(float data[], int size)
{
    if (size <= 0)
        return 0.0;

    // Sort array (modifies original!)
    quickSort(data, 0, size - 1);

    // Median calculation
    if (size % 2 == 0)
        // Even number of elements: average of two middle values
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    else
        // Odd number of elements: middle value
        return data[size / 2];
}