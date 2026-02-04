#ifndef RECTANGLE_H
#define RECTANGLE_H

// Structure for 2D point
typedef struct
{
    float x;
    float y;
} vec_t;

// Structure for rectangle
// Reference point is bottom-left corner
typedef struct
{
    vec_t position; // Reference point (bottom-left corner)
    float width;
    float height;
} rectangle_t;

// Function declarations
float getArea(rectangle_t rect);
void moveRect(rectangle_t *rect, float offsetX, float offsetY);
void scaleRect(rectangle_t *rect, float newWidth, float newHeight);
int intersect(rectangle_t rect1, rectangle_t rect2);

#endif