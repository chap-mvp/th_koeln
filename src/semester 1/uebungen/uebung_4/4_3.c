#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int num1, num2;           // Input numbers
    int dividend, divisor;    // Working variables for GCD calculation
    int remainder;            // Remainder in division
    int base;                 // Target base for conversion
    int position;             // Position in base representation
    
    // Read two integers from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Initialize variables for Euclidean algorithm
    dividend = num1;
    divisor = num2;
    
    // Calculate GCD using Euclidean algorithm
    // Repeatedly divide and replace with remainder until remainder is 0
    while (divisor != 0) {
        remainder = dividend % divisor;  // Calculate remainder
        dividend = divisor;              // Old divisor becomes new dividend
        divisor = remainder;             // Remainder becomes new divisor
    }
    // When loop ends, dividend contains the GCD
    
    printf("\nThe Greatest Common Divisor (GCD) of %d and %d is: %d\n", 
           num1, num2, dividend);
    
    // Convert GCD to different base
    printf("\nEnter base for number conversion (2-36): ");
    scanf("%d", &base);
    
    printf("\nGCD %d in base %d represented as positional notation:\n", 
           dividend, base);
    printf("%d (base 10) = ", dividend);
    
    // Convert to target base and display in positional notation
    // Example: 6 in base 2 = 0×2^0 + 1×2^1 + 1×2^2
    for (position = 0; dividend > 0; position++) {
        char digit;
        int digitValue = dividend % base;  // Extract rightmost digit in target base
        dividend = dividend / base;        // Remove rightmost digit
        
        // Convert digit value to character (0-9, A-Z)
        if (digitValue < 10)
            digit = digitValue + '0';      // Digits 0-9
        else
            digit = digitValue + 'A' - 10; // Letters A-Z for bases > 10
        
        // Print separator between terms
        if (position > 0)
            printf(" + ");
        
        // Print term: digit × base^position
        printf("%c × %d^%d", digit, base, position);
    }
    
    printf("\n\n");
    
    return EXIT_SUCCESS;
}