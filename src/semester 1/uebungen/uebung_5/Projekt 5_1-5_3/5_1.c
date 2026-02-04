#include <stdio.h>
#include <time.h>
#include <math.h>

void getCurrentDate()
{
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);

    printf("Todays date is %02d.%02d.%04d\n", 
           time_info->tm_mday, 
           time_info->tm_mon + 1, 
           time_info->tm_year + 1900);
}

void getWhiteNumSpaces(int n, char a[n])
{
    int spaces = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == ' ')
            spaces++;
    printf("There are %d spaces in the string\n", spaces);
}

float quadraticFunction(float p, float q, float x)
{
    return x * x + p * x + q;
}

void getZeroPointsQuadraticFunction(float p, float q)
{
    float first, second;
    float discriminant = pow(p / 2, 2) - q;
    
    if (discriminant < 0)
    {
        printf("No real solutions!\n");
    }
    else if (discriminant == 0)
    {
        first = -p / 2.0;
        printf("One real solution: %.2f\n", first);
    }
    else
    {
        first = -p / 2.0 - sqrt(discriminant);
        second = -p / 2.0 + sqrt(discriminant);
        printf("Two real solutions: %.2f & %.2f\n", first, second);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

double polynomial(int n, float coefficients[n], double x)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
        result += coefficients[i] * pow(x, i);
    return result;
}

int main()
{
    getCurrentDate();
    
    char str[] = "Hello World  Test";
    getWhiteNumSpaces(17, str);
    
    printf("f(2) = %.2f\n", quadraticFunction(-3, 2, 2));
    
    getZeroPointsQuadraticFunction(-3, 2);
    
    int a = 5, b = 10;
    printf("Before: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After: a=%d, b=%d\n", a, b);
    
    float coeffs[] = {1, 2, 3};
    printf("P(2) = %.2f\n", polynomial(3, coeffs, 2.0));
    
    return 0;
}