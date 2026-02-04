#include <stdio.h>
#include <math.h>
#include "quadratic.h"

/**
 * Calculates and prints zero points of quadratic function f(x) = x² + px + q
 */
void getZeroPointsQuadraticFunction(float p, float q)
{
    float first, second;
    float discriminant = pow(p / 2, 2) - q;

    if (discriminant < 0)
    {
        printf("No real solutions!\n");
    }
    else if (fabs(discriminant) < 1e-6) // Use fabs for float comparison
    {
        first = -p / 2.0;
        printf("One real solution: %.4f\n", first);
    }
    else
    {
        first = -p / 2.0 - sqrt(discriminant);
        second = -p / 2.0 + sqrt(discriminant);
        printf("Two real solutions: %.4f & %.4f\n", first, second);
    }
}