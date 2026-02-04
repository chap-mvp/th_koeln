#include <stdio.h>

// Call by reference version
void checkIfOdd(int* checkVariable, int* result)
{
    *result = (*checkVariable % 2);
}

int main(void)
{
    int oddOrEven = 42346;
    int isOdd;
    
    checkIfOdd(&oddOrEven, &isOdd);
    
    if(isOdd)
    {
        printf("Die Zahl ist ungerade\n");
    }
    else
    {
        printf("Die Zahl ist gerade\n");
    }
    
    return 0;
}