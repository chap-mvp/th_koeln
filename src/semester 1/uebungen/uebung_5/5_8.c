#include <stdio.h>
#define ISOK 0

int addFavoriteNumber(int valueToAdd)
{
    return valueToAdd + 42;
}

int main(void)
{
    int somethingMissing = 12;
    int returnAddFunction = -1;

    somethingMissing = addFavoriteNumber(somethingMissing);
    returnAddFunction = ISOK;

    if (returnAddFunction == ISOK)
    {
        printf("Jetzt ist sie vollstaendig, lautet: %d\n", somethingMissing);
    }
    else
        printf("Da fehlt was, die Zahl lautet: %d\n", somethingMissing);
}