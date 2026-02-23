#include <stdlib.h>

#define MEAS_MAX 20 // Preprocessor (kein Speicher)

float x = 0; // DATA Segment (initialised global variable)

float polynom(float a1, float a2, float x) // CODE Segment
{
    static int a3 = 0; // static variable
    a3++;
    return a1 * x * x + a2 * x + a3;
}

int main()
{ 
    float coefficients[] = {1.5, 12}; // STACK 
    float step = 1.0 / MEAS_MAX; // STACK
    float *measValues = (float *)malloc(MEAS_MAX * sizeof(float)); // STACK
    // HEAP (allocated DATA)
    for (int i = 0; i < MEAS_MAX; i++) // i: STACK
    {
        measValues[i] = polynom(coefficients[0], coefficients[1], x);
        x += step;
    }
    return EXIT_SUCCESS;
}