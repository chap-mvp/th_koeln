#pragma once
#include <stdbool.h>

typedef struct point {
    float x, y;
} vec_t;

typedef struct rectangle
{
    vec_t midPoint;
    float height, width;
} rectangle_t;

float getArea(rectangle_t rec);

void moveRect(rectangle_t *rec, vec_t offset);

void scaleRect(rectangle_t *rec, float width, float height);

bool intersect(rectangle_t *rec1, rectangle_t *rec2);