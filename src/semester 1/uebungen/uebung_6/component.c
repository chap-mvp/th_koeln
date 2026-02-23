#include <stdio.h>
#include "component.h"

const char *getComponentTypeName(ComponentType type)
{
    switch (type)
    {
    case RESISTOR:
        return "Widerstand";
    case CAPACITOR:
        return "Kondensator";
    case INDUCTOR:
        return "Spule";
    default:
        return "Unbekannt";
    }
}

int getNextID()
{
    FILE *file = fopen(DATABASE_FILE, "r");
    int maxID = 0;
    Component comp;

    if (file != NULL)
    {
        while (fscanf(file, "%d %d %f %f", &comp.id, (int *)&comp.type, &comp.nominalValue, &comp.tolerance) == 4)
            if (comp.id > maxID)
                maxID = comp.id;

        fclose(file);
    }
    return maxID + 1;
}

void addComponent()
{
    Component comp;
    int typeChoice;

    printf("\nNeues bauelement Hinzufuegen\n");

    comp.id = getNextID();
    printf("Automatisch zugewiesene ID: %d\n", comp.id);

    printf("\nBauteiltyp waehlen\n");
    printf("0 - Widerstand\n");
    printf("1 - Kondensator\n");
    printf("2 - Spule\n");
    printf("Eingabe: ");
    scanf("%d", &typeChoice);

    if (typeChoice < 0 || typeChoice > 2)
    {
        printf("Ungueltige Auswahl! Abbruch.\n");
        return;
    }
    comp.type = (ComponentType)typeChoice;

    printf("Nennwert Eingeben: ");
    scanf("%f", &comp.nominalValue);

    printf("Toleranz Eingeben: ");
    scanf("%f", &comp.tolerance);

    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL)
    {
        printf("Fehler: Datei konnte nicht geoeffnet werden!");
        return;
    }

    printf("ID: %d | Typ: %s | Nennwert: %.2f | Toleranz: %.2f%%\n",
           comp.id, getComponentTypeName(comp.type),
           comp.nominalValue, comp.tolerance);

    fprintf(file, "%d %d %.6f %.2f\n",
            comp.id, comp.type, comp.nominalValue, comp.tolerance);

    fclose(file);

    printf("\nBauteil erfolgreich hinzugefuegt!\n");
    printf("ID: %d | Typ: %s | Nennwert: %.2f | Toleranz: %.2f%%\n", comp.id, getComponentTypeName(comp.type), comp.nominalValue, comp.tolerance);
}

void listAllComponents()
{
    FILE *file = fopen(DATABASE_FILE, "r");
    Component comp;
    int count = 0;

    printf("\n  Alle Elemente");

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden!\n");
        return;
    }

    printf("\n%-5s | %-15s | %-15s | %-10s\n",
           "ID", "Typ", "Nennwert", "Toleranz");
    printf("------+-----------------+-----------------+-----------\n");

    while (fscanf(file, "%d %d %f %f", &comp.id, (int *)&comp.type, &comp.nominalValue, &comp.tolerance) == 4)
    {
        printf("%-5d | %-15s | %-15.6f | %-9.2f%%\n", comp.id, getComponentTypeName(comp.type), comp.nominalValue, comp.tolerance);
        count++;
    }
    fclose(file);

    if (count == 0)
        printf("Keine Bauteile in der Datenbank.\n");
    else
        printf("\nGesamtbauteile: %d \n", count);
}

void searchID()
{
    FILE *file = fopen(DATABASE_FILE, "r");
    Component comp;
    int searchID;
    int found = 0;

    printf("\nBauelement Suchen\n");
    printf("ID Eingeben: ");
    scanf("%d", &searchID);

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden.\n");
        return;
    }

    while (fscanf(file, "%d %d %f %f", &comp.id, (int *)&comp.type, &comp.nominalValue, &comp.tolerance) == 4)
        if (comp.id == searchID)
        {
            printf("Bauteil gefunden:\n");
            printf("ID:        %d\n", comp.id);
            printf("Typ:       %s\n", getComponentTypeName(comp.type));
            printf("Nennwert:  %.6f\n", comp.nominalValue);
            printf("Toleranz:  %.2f\n", comp.tolerance);
            found = 1;
            break;
        }

    fclose(file);

    if (!found)
        printf("Bauteil nicht gefunden.\n");
}

void deleteID()
{
    FILE *file = fopen(DATABASE_FILE, "r");
    FILE *tempFile;
    Component comp;
    int deleteID;
    int found = 0;
    char confirm;

    printf("Bauelement loeschen.\n");
    printf("ID Eingeben: ");
    scanf("%d", &deleteID);

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden.\n");
        return;
    }

    while (fscanf(file, "%d %d %f %f", &comp.id, (int *)&comp.type, &comp.nominalValue, &comp.tolerance) == 4)
        if (comp.id == deleteID)
        {
            found = 1;
            break;
        }

    if (!found)
    {
        printf("Bauteil nicht gefunden.\n");
        fclose(file);
        return;
    }

    printf("Wollen sie das Bauteil wirklich loeschen? (j/n): ");
    scanf(" %c", &confirm);

    if (confirm != 'j' && confirm != 'J')
    {
        printf("Loeschen abgebrochen.\n");
        fclose(file);
        return;
    }

    rewind(file);
    tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL)
    {
        printf("FEHLER: TempFile konnte nicht erstellt werden!");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d %d %f %f", &comp.id, (int *)&comp.type, &comp.nominalValue, &comp.tolerance) == 4)
        if (comp.id != deleteID)
            fprintf(file, "%d %d %.2f %.2f\n", comp.id, getComponentTypeName(comp.type), comp.nominalValue, comp.tolerance);

    fclose(file);
    fclose(tempFile);

    remove(DATABASE_FILE);
    rename("temp.txt", DATABASE_FILE);

    printf("Bauteil mit ID %d geloescht.\n", deleteID);
}

void calcAverageTolerance()
{
    FILE *file = fopen(DATABASE_FILE, "r");
    Component comp;
    float sumTolerance = 0.0;
    int count = 0;

    // printf("Durchschnittliche Toleranz");

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden.\n");
        return;
    }

    while (fscanf(file, "%d %d %f %f", &comp.id, (int *)&comp.type, &comp.nominalValue, &comp.tolerance) == 4)
    {
        sumTolerance += comp.tolerance;
        count++;
    }

    fclose(file);

    if (count == 0)
        printf("Keine Bauteile in der Datenbank.\n");
    else
        printf("\nDurchschnittliche Toleranz: %.2f%%\n", sumTolerance / count);
}