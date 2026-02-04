#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define GROWTH_SIZE 10

/**
 * Counts number of sentences in text
 * Sentences end with '.', '?', or '!'
 */
int numSentences(char *text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    int capacity = INITIAL_CAPACITY;
    int length = 0;
    char *text = (char *)malloc(capacity * sizeof(char));

    if (text == NULL)
    {
        printf("Fehler: Speicher konnte nicht allokiert werden!\n");
        return EXIT_FAILURE;
    }

    printf("DEBUG: Initiales Array allokiert mit Kapazitaet %d\n", capacity);
    printf("\nBitte Text eingeben (beenden mit Ctrl+Z unter Windows oder Ctrl+D unter Linux):\n");

    char c;
    while ((c = getchar()) != EOF)
    {
        // Prüfen ob Array voll ist
        if (length >= capacity - 1)
        { // -1 für '\0'
            capacity += GROWTH_SIZE;
            char *temp = (char *)realloc(text, capacity * sizeof(char));

            if (temp == NULL)
            {
                printf("Fehler: Speicher konnte nicht erweitert werden!\n");
                free(text);
                return EXIT_FAILURE;
            }

            text = temp;
            printf("\nDEBUG: Array erweitert auf Kapazitaet %d (bei Zeichen %d)\n",
                   capacity, length);
        }

        text[length] = c;
        length++;
    }

    // Null-Terminator hinzufügen
    text[length] = '\0';

    printf("\n\n=== Analyse ===\n");
    printf("Eingegebener Text hat %d Zeichen\n", length);
    printf("Finale Array-Kapazitaet: %d\n", capacity);

    // Anzahl Sätze bestimmen
    int sentences = numSentences(text);
    printf("Anzahl Saetze: %d\n", sentences);

    printf("\n=== Eingegebener Text ===\n");
    printf("%s\n", text);

    // Speicher freigeben
    free(text);

    return EXIT_SUCCESS;
}