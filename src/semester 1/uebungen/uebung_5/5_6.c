#include <stdio.h>
#include <string.h>

int isNamePaul(char *name)
{
    if (strcmp(name, "Paul") == 0)
        return 1;

    return 0;
}

int main(void)
{
    char names[][20] = {
        "Peter",
        "Paul",
        "Maria",
        "Anna",
        "Paul",
        "Michael"};

    int nameCount = 6;

    printf("=== Name Checker ===\n\n");

    printf("Checking which names are 'Paul':\n\n");

    for (int i = 0; i < nameCount; i++)
    {
        if (isNamePaul(names[i]))
            printf("  %s -> YES, this is Paul!\n", names[i]);
        else
            printf("  %s -> No, this is not Paul.\n", names[i]);
    }
}