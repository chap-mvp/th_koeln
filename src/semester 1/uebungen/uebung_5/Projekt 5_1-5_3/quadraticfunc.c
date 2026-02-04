#include <stdio.h>
#include "quadratic.h"

/**
 * Evaluates quadratic function f(x) = x² + px + q at position x
 * Also counts total zero points verified since program start
 */
float quadraticFunction(float p, float q, float x)
{
    static int totalZeroPointsFound = 0; // Persists between function calls

    float result = x * x + p * x + q;

    // Check if x is a zero point (result close to 0)
    if (result >= -0.0001 && result <= 0.0001)
    {
        totalZeroPointsFound++;
        printf(">> Zero point verified! Total zero points found since start: %d\n",
               totalZeroPointsFound);
    }

    return result;
}