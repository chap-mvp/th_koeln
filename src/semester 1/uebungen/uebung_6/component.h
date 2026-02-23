#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdio.h>

typedef enum
{
    RESISTOR = 0,
    CAPACITOR = 1,
    INDUCTOR = 2
} ComponentType;

typedef struct
{
    int id;
    ComponentType type;
    float nominalValue;
    float tolerance;
} Component;

void addComponent();
void listAllComponents();
void searchID();
void deleteID();
void calcAverageTolerance();
const char *getComponentTypeName(ComponentType type);

#define DATABASE_FILE "database.txt"

#endif