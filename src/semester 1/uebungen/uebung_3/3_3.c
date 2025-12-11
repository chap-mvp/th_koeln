/*
Aufgabe 3.3: Array initialisieren und deklarieren 
- Versucht man, ein Array wie gezeigt zu initialisieren und zu deklarieren, liefert der Compiler die 
Fehlermeldung für Zeile 4 "Array Size must be defined". Beheben Sie den Fehler und machen den 
Code lauffähig. Achtung: Deklaration und Initialisierung sollen getrennt geschehen. 
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int length = 3;

    int zahlen[length]; // Größe fehlt

    for (int i = 0; i < 4; i++) {
            zahlen[i] = i + 1; // Deklaration Elemente
            printf("%d, ", zahlen[i]);
    }

    int len = sizeof(zahlen)/length;
    printf("\nAnzahl der Elemente: %d\n", len);
    
    return EXIT_SUCCESS;
}