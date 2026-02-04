#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "component.h"

/**
 * Returns string representation of component type
 */
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

/**
 * Gets next available ID from database
 */
int getNextID(void)
{
    FILE *file = fopen(DATABASE_FILE, "r");
    int maxID = 0;
    Component comp;

    if (file != NULL)
    {
        while (fscanf(file, "%d %d %f %f",
                      &comp.id, (int *)&comp.type,
                      &comp.nominalValue, &comp.tolerance) == 4)
        {
            if (comp.id > maxID)
            {
                maxID = comp.id;
            }
        }
        fclose(file);
    }

    return maxID + 1;
}

/**
 * Adds a new component to the database
 */
void addComponent(void)
{
    Component comp;
    int typeChoice;

    printf("\n=== Neues Bauelement hinzufuegen ===\n");

    // Get next ID automatically
    comp.id = getNextID();
    printf("Automatisch zugewiesene ID: %d\n", comp.id);

    // Get component type
    printf("\nBauteiltyp waehlen:\n");
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

    // Get nominal value
    printf("Nennwert eingeben: ");
    scanf("%f", &comp.nominalValue);

    // Get tolerance
    printf("Toleranz eingeben (in %%): ");
    scanf("%f", &comp.tolerance);

    // Open file in append mode
    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL)
    {
        printf("FEHLER: Datei konnte nicht geoeffnet werden!\n");
        return;
    }

    // Write component to file
    fprintf(file, "%d %d %.6f %.2f\n",
            comp.id, comp.type, comp.nominalValue, comp.tolerance);

    fclose(file);

    printf("\nBauteil erfolgreich hinzugefuegt!\n");
    printf("ID: %d | Typ: %s | Nennwert: %.2f | Toleranz: %.2f%%\n",
           comp.id, getComponentTypeName(comp.type),
           comp.nominalValue, comp.tolerance);
}

/**
 * Lists all components in the database
 */
void listAllComponents(void)
{
    FILE *file = fopen(DATABASE_FILE, "r");
    Component comp;
    int count = 0;

    printf("\n=== Alle Bauelemente ===\n");

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden oder Datei konnte nicht geoeffnet werden.\n");
        return;
    }

    printf("\n%-5s | %-15s | %-15s | %-10s\n",
           "ID", "Typ", "Nennwert", "Toleranz");
    printf("------+----------------+----------------+-----------\n");

    while (fscanf(file, "%d %d %f %f",
                  &comp.id, (int *)&comp.type,
                  &comp.nominalValue, &comp.tolerance) == 4)
    {
        printf("%-5d | %-15s | %-15.6f | %-9.2f%%\n",
               comp.id, getComponentTypeName(comp.type),
               comp.nominalValue, comp.tolerance);
        count++;
    }

    fclose(file);

    if (count == 0)
    {
        printf("Keine Bauteile in der Datenbank.\n");
    }
    else
    {
        printf("\nGesamt: %d Bauteile\n", count);
    }
}

/**
 * Searches for a component by ID
 */
void searchID(void)
{
    FILE *file = fopen(DATABASE_FILE, "r");
    Component comp;
    int searchID;
    int found = 0;

    printf("\n=== Bauelement suchen ===\n");
    printf("ID eingeben: ");
    scanf("%d", &searchID);

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden oder Datei konnte nicht geoeffnet werden.\n");
        return;
    }

    while (fscanf(file, "%d %d %f %f",
                  &comp.id, (int *)&comp.type,
                  &comp.nominalValue, &comp.tolerance) == 4)
    {
        if (comp.id == searchID)
        {
            printf("\nBauteil gefunden:\n");
            printf("ID:        %d\n", comp.id);
            printf("Typ:       %s\n", getComponentTypeName(comp.type));
            printf("Nennwert:  %.6f\n", comp.nominalValue);
            printf("Toleranz:  %.2f%%\n", comp.tolerance);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Bauteil nicht gefunden.\n");
    }
}

/**
 * Deletes a component by ID
 */
void deleteID(void)
{
    FILE *file = fopen(DATABASE_FILE, "r");
    FILE *tempFile;
    Component comp;
    int deleteID;
    int found = 0;
    char confirm;

    printf("\n=== Bauelement loeschen ===\n");
    printf("ID eingeben: ");
    scanf("%d", &deleteID);

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden oder Datei konnte nicht geoeffnet werden.\n");
        return;
    }

    // Check if component exists
    while (fscanf(file, "%d %d %f %f",
                  &comp.id, (int *)&comp.type,
                  &comp.nominalValue, &comp.tolerance) == 4)
    {
        if (comp.id == deleteID)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Bauteil nicht gefunden.\n");
        fclose(file);
        return;
    }

    // Confirmation
    printf("\nWollen Sie wirklich das Bauteil mit der ID %d loeschen? (j/n): ", deleteID);
    scanf(" %c", &confirm);

    if (confirm != 'j' && confirm != 'J')
    {
        printf("Loeschen abgebrochen.\n");
        fclose(file);
        return;
    }

    // Rewind file and create temp file
    rewind(file);
    tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL)
    {
        printf("FEHLER: Temporaere Datei konnte nicht erstellt werden!\n");
        fclose(file);
        return;
    }

    // Copy all components except the one to delete
    while (fscanf(file, "%d %d %f %f",
                  &comp.id, (int *)&comp.type,
                  &comp.nominalValue, &comp.tolerance) == 4)
    {
        if (comp.id != deleteID)
        {
            fprintf(tempFile, "%d %d %.6f %.2f\n",
                    comp.id, comp.type, comp.nominalValue, comp.tolerance);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace original file with temp file
    remove(DATABASE_FILE);
    rename("temp.txt", DATABASE_FILE);

    printf("Bauteil mit ID %d erfolgreich geloescht.\n", deleteID);
}

/**
 * Calculates and displays average tolerance
 */
void calcTolerance(void)
{
    FILE *file = fopen(DATABASE_FILE, "r");
    Component comp;
    float sumTolerance = 0.0;
    int count = 0;

    printf("\n=== Durchschnittliche Toleranz ===\n");

    if (file == NULL)
    {
        printf("Keine Datenbank gefunden oder Datei konnte nicht geoeffnet werden.\n");
        return;
    }

    while (fscanf(file, "%d %d %f %f",
                  &comp.id, (int *)&comp.type,
                  &comp.nominalValue, &comp.tolerance) == 4)
    {
        sumTolerance += comp.tolerance;
        count++;
    }

    fclose(file);

    if (count == 0)
    {
        printf("Keine Bauteile in der Datenbank.\n");
    }
    else
    {
        float average = sumTolerance / count;
        printf("Anzahl Bauteile: %d\n", count);
        printf("Durchschnittliche Toleranz: %.2f%%\n", average);
    }
}