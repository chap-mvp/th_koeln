/*
Aufgabe 3.5: Post-Auto-Detektion 
Bilder werden auf dem Rechner abgelegt in Form von Arrays. Handelt es sich dabei um 
klassische RotGrünBlau Bilder, haben diese Arrays allgemein die folgende Form;  
int arrayImage[cntWidth] [cntHeight] [nColors], 
wobei der Farbwert eines jeden Bildpunkts (Pixels) als Wert zwischen 0 (schwarz) und 255 
(voller Farbwert) in dem Array abgelegt wird und wobei cntWidth die Anzahl der Pixel auf 
der Breite des Bildes und cntHeight die Anzahl der Pixel auf der Höhe des Bildes sind. 
Das Bild besteht somit aus (cntWidth x cntHeight) Pixeln und jeder Pixel hat einen 
entsprechenden R-, G- und B-Wert. Im dem Beispiel der folgenden Abbildungen beträgt der 
blaue Farbwert an der Stelle 42(Breite),18(Höhe) also 128. Der entsprechende Grün Wert 
könnte abgefragt werden über arrayImage[42][18][1].
Nutzen Sie diese Information, um einen Algorithmus zu entwickeln, der in einem 20x10 RGB-
Bild, ein Postauto detektiert, sobald mehr als 40% der Pixel "gelb sind". Pixel gelten als 
"gelb", wenn der entsprechende Rot- und Blau-Wert des Pixels größer als 220 ist.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CNT_HEIGHT 10
#define CNT_WIDTH 10
#define PRIMARY_COLORS 3

// yellow when intensity over 220 out of 255

float checkYellow(float arrayImage[CNT_HEIGHT][CNT_WIDTH][PRIMARY_COLORS])
{
    float sumAveragedArray[CNT_HEIGHT][CNT_WIDTH] = {0};
    float pixels = CNT_WIDTH * CNT_HEIGHT * PRIMARY_COLORS;

    for (int i = 0; i < PRIMARY_COLORS; i++)
    {
        if (i == 0)
            printf("RED:\n");
        if (i == 1)
            printf("GREEN:\n");
        if (i == 2)
            printf("BLUE:\n");

        for (int j = 0; j < CNT_HEIGHT; j++)
        {
            for (int k = 0; k < CNT_WIDTH; k++)
                printf("[%.2f]  \t", arrayImage[k][j][i]);
            printf("\n");
        }
    }

    for (int i = 0; i < CNT_HEIGHT; i++)
        for (int j = 0; j < CNT_WIDTH; j++)
            for (int k = 0; k < PRIMARY_COLORS; k++)
                sumAveragedArray[i][j] += (arrayImage[i][j][k] / 3);

    printf("AVERAGE:\n");
    for (int i = 0; i < CNT_HEIGHT; i++)
    {
        for (int j = 0; j < CNT_WIDTH; j++)
            printf("[%.2f]  \t", sumAveragedArray[i][j]);
        printf("\n");
    }

    int yellowPixels = 0;

    for (int i = 0; i < CNT_HEIGHT; i++)
        for (int j = 0; j < CNT_WIDTH; j++)
            if (sumAveragedArray[i][j] >= 220)
                yellowPixels++;

    printf("There are %d Yellow pixels!\n", yellowPixels);

    return yellowPixels;
}

int main()
{
    srand(time(NULL));
    float arrayImage[CNT_HEIGHT][CNT_WIDTH][PRIMARY_COLORS];

    for (int i = 0; i < PRIMARY_COLORS; i++)
        for (int j = 0; j < CNT_HEIGHT; j++)
            for (int k = 0; k < CNT_WIDTH; k++)
                arrayImage[k][j][i] = (rand() % 220) + 1;

    float pixels = CNT_HEIGHT * CNT_WIDTH;

    return (float)checkYellow(arrayImage) / pixels >= 0.4 ? printf("Yes!") : printf("No!");
}