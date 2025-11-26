#include <stdio.h>
#include "myHeader33.h"

int main(void) {
    int myArray[] = {5, 2, 9, 1, 5, 6};
    int laenge = sizeof(myArray) / sizeof(myArray[0]);

    printf("Vor der Sortierung:\n");
    for (int i = 0; i < laenge; i++) {
        printf("%d ", myArray[i]);
    }

    sortArrayDescending(myArray, laenge);

    printf("\nNach der Sortierung in absteigender Reihenfolge:\n");
    for (int i = 0; i < laenge; i++) {
        printf("%d ", myArray[i]);
    }

    return 0;
}





