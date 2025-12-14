/*
Aufgabe 3.9: Palindrom prüfen
Ein Palindrom ist ein Wort, das von vorne und von hinten gelesen gleich ist, z.B. „Anna“, „Reittier“, „Otto“, „Rentner“. Erstellen Sie ein Programm, das eine Zeichenkette von der Standardeingabe einliest und prüft ob es sich um ein Palindrom handelt. Hinweis: wandeln Sie alle Buchstaben in Kleinbuchstaben um mit der Funktion tolower().
int tolower(int c) - wenn c nicht schon ein Kleinbuchstabe ist, wird c umgewandelt in einen Kleinbuchstaben und als return Wert zurückgegeben.
*/

#include <stdio.h>
// #include <ctype.h>

int main()
{
    char palindrome[15] = {0};
    int characters = 0;

    for (int i = 0; i < 15; i++)
    {
        char c = getchar();
        if (c == '\n')
            break;

        palindrome[i] = c;

        if (palindrome[i] != 0)
            characters++;

        if (palindrome[i] < 'a')
            palindrome[i] += 'a' - 'A';
    }

    printf("There are %d characters!\n", characters);

    for (int i = 0; i < characters; i++)
    {
        printf("[%c] ", palindrome[i]);
        if (palindrome[i] != palindrome[characters - 1 - i])
        {
            printf("\nNot a palindrome!");
            return 0;
        }
    }
    printf("Its a palindrome!");
}