#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100
 
int main()
{
    char *completeText = NULL; // Speichert gesamten Text
    char buffer[MAXLINE];      // Temporärer Buffer für jede Zeile
    int totalLen = 0;

    printf("Bitte einen beliebigen Text eingeben und mit ^Z beenden.\n");

    while (fgets(buffer, MAXLINE, stdin))
    {
        int lineLen = strlen(buffer);

        // Speicher für gesamten Text erweitern
        char *temp = (char *)realloc(completeText, (totalLen + lineLen + 1) * sizeof(char));

        if (temp == NULL)
        {
            printf("Fehler: Speicher konnte nicht allokiert werden!\n");
            free(completeText);
            return EXIT_FAILURE;
        }

        completeText = temp;

        // Erste Zeile: String initialisieren
        if (totalLen == 0)
        {
            completeText[0] = '\0';
        }

        // Neue Zeile anhängen
        strcat(completeText, buffer);
        totalLen += lineLen;

        printf("DEBUG: Zeile eingelesen (%d Zeichen), Gesamt: %d\n",
               lineLen, totalLen);
    }

    printf("\nDer Text hat %d Zeichen.\n", totalLen);
    printf("Gesamte Eingabe:\n%s\n", completeText);

    free(completeText);
    return 0;
}