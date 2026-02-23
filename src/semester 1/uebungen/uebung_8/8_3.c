#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define GROWTH_SIZE 10

int numSentences(char *text);

int main()
{
    int capacity = INITIAL_CAPACITY;
    int length = 0;
    char *text = (char *)malloc(capacity * sizeof(char));

    if (text == NULL)
        return EXIT_FAILURE;

    char c;
    while ((c = getchar()) != EOF)
    {
        if (length >= capacity - 1)
        {
            capacity += GROWTH_SIZE;
            char *temp = (char *)realloc(text, capacity * sizeof(char));

            if (temp == NULL)
            {
                free(text);
                return EXIT_FAILURE;
            }

            text = temp;
        }
        text[length] = c;
        length++;
    }

    text[length] = '\0';

    int sentences = numSentences(text);
    printf("%d Sentences\n", sentences);

    free(text);

    return EXIT_SUCCESS;
}

int numSentences(char *text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            count++;

    return count;
}