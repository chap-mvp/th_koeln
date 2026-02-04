#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadratic.h"

int main(void)
{
    float p, q;
    char choice;

    printf("=== Quadratic Function Zero Points Calculator ===\n");
    printf("Function form: f(x) = x² + px + q\n\n");

    do
    {
        printf("\nEnter coefficient p: ");
        scanf("%f", &p);

        printf("Enter coefficient q: ");
        scanf("%f", &q);

        printf("\nFunction: f(x) = x² + %.2fx + %.2f\n", p, q);

        // Find and display zero points
        getZeroPointsQuadraticFunction(p, q);

        // Verify zero points if they exist
        float discriminant = pow(p / 2, 2) - q;

        if (discriminant >= 0)
        {
            printf("\nVerification:\n");

            if (fabs(discriminant) < 1e-6)
            {
                // One solution
                float x = -p / 2.0;
                float result = quadraticFunction(p, q, x);
                printf("  f(%.4f) = %.6f\n", x, result);
            }
            else
            {
                // Two solutions
                float x1 = -p / 2.0 - sqrt(discriminant);
                float x2 = -p / 2.0 + sqrt(discriminant);

                float result1 = quadraticFunction(p, q, x1);
                printf("  f(%.4f) = %.6f\n", x1, result1);

                float result2 = quadraticFunction(p, q, x2);
                printf("  f(%.4f) = %.6f\n", x2, result2);
            }
        }

        printf("\nContinue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nProgram terminated.\n");

    return EXIT_SUCCESS;
}