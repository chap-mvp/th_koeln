/*
Aufgabe 2.6: Header Datei untersuchen und einbinden
Öffnen Sie die Header Datei myHeader26.h (im selben Ordner wie dieses Aufgabenblatt)
Fügen Sie ein eigenes Makro ein, binden die HeaderDatei in die Quellcode Datei main26.c
ein, rufen dort Ihr erzeugtes Makro auf, kompilieren die Dateien und führen sie aus. Zeigen
Sie das Vorgehen.
*/

#include <stdio.h>
#include "2_6.h"

int main(void)
{
    printf("Die Antwort auf alles ist %d \n", answerToEverything);

    printf("Die Antwort auf alles quadriert ist: %d", square(answerToEverything));
    return 0;
}
