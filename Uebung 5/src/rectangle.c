#include "rectangle.h"

float getArea(rectangle_t rec)
{
    return rec.width * rec.height;
}

void moveRect(rectangle_t *rec, vec_t offset)
{
    rec->midPoint.x = offset.x;
    rec->midPoint.y = offset.y;
}

void scaleRect(rectangle_t *rec, float width, float height)
{
    rec->height = height;
    rec->width = width;
}

bool intersect(rectangle_t *rec1, rectangle_t *rec2)
{
    
    return false;
}