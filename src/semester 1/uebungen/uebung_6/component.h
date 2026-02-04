#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdio.h>

// Enum for component types
typedef enum
{
    RESISTOR = 0,
    CAPACITOR = 1,
    INDUCTOR = 2
} ComponentType;

// Structure for electronic component
typedef struct
{
    int id;
    ComponentType type;
    float nominalValue;
    float tolerance;
} Component;

// Function declarations
void addComponent(void);
void listAllComponents(void);
void searchID(void);
void deleteID(void);
void calcTolerance(void);
const char *getComponentTypeName(ComponentType type);

#define DATABASE_FILE "database.txt"

#endif