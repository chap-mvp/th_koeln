#include <stdio.h>
#include <stdlib.h>
#include "component.h"

void displayMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("  Bauelemente-Datenbank Verwaltung\n");
    printf("========================================\n");
    printf("1. Bauelement hinzufuegen\n");
    printf("2. Alle Bauelemente anzeigen\n");
    printf("3. Bauelement suchen (nach ID)\n");
    printf("4. Bauelement loeschen (nach ID)\n");
    printf("5. Durchschnittliche Toleranz berechnen\n");
    printf("0. Programm beenden\n");
    printf("========================================\n");
    printf("Ihre Auswahl: ");
}

int main(void)
{
    int choice;

    printf("Willkommen zur Bauelemente-Datenbank!\n");

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addComponent();
            break;
        case 2:
            listAllComponents();
            break;
        case 3:
            searchID();
            break;
        case 4:
            deleteID();
            break;
        case 5:
            calcTolerance();
            break;
        case 0:
            printf("\nProgramm wird beendet. Auf Wiedersehen!\n");
            break;
        default:
            printf("\nUngueltige Auswahl! Bitte waehlen Sie 0-5.\n");
        }

    } while (choice != 0);

    return EXIT_SUCCESS;
}