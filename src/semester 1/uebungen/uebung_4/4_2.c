#include <stdio.h>
#include <stdlib.h>

void foo()
{
    float i;
    for (i = 0.0; i != 1.0; i += 0.1)
    {
        printf("%1.12f\t\t", i);
    }
}

int main()
{
    foo();
    return 0;
}