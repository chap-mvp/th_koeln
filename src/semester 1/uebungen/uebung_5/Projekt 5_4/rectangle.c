#include "rectangle.h"

/**
 * Returns the area of the rectangle
 */
float getArea(rectangle_t rect)
{
    return rect.width * rect.height;
}

/**
 * Moves the rectangle by the given offset
 */
void moveRect(rectangle_t *rect, float offsetX, float offsetY)
{
    rect->position.x += offsetX;
    rect->position.y += offsetY;
}

/**
 * Scales the rectangle to new dimensions
 * Reference point (bottom-left) stays fixed
 */
void scaleRect(rectangle_t *rect, float newWidth, float newHeight)
{
    rect->width = newWidth;
    rect->height = newHeight;
}

/**
 * Checks if two rectangles intersect
 * Returns 1 if they intersect, 0 otherwise
 */
int intersect(rectangle_t rect1, rectangle_t rect2)
{
    // Calculate boundaries for rect1
    float r1_left = rect1.position.x;
    float r1_right = rect1.position.x + rect1.width;
    float r1_bottom = rect1.position.y;
    float r1_top = rect1.position.y + rect1.height;

    // Calculate boundaries for rect2
    float r2_left = rect2.position.x;
    float r2_right = rect2.position.x + rect2.width;
    float r2_bottom = rect2.position.y;
    float r2_top = rect2.position.y + rect2.height;

    // Check if rectangles do NOT overlap
    if (r1_right <= r2_left || r2_right <= r1_left ||
        r1_top <= r2_bottom || r2_top <= r1_bottom)
    {
        return 0; // No intersection
    }

    return 1; // Intersection exists
}