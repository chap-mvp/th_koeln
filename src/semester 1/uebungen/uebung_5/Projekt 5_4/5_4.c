#include <stdio.h>
#include "rectangle.h"

int main(void)
{
    // Create two rectangles
    rectangle_t rect1 = {{1.0, 1.0}, 4.0, 3.0}; // pos(1,1), width=4, height=3
    rectangle_t rect2 = {{3.0, 2.0}, 3.0, 2.0}; // pos(3,2), width=3, height=2

    printf("=== Rectangle Operations ===\n\n");

    // Test getArea
    printf("Rectangle 1: position(%.1f, %.1f), width=%.1f, height=%.1f\n",
           rect1.position.x, rect1.position.y, rect1.width, rect1.height);
    printf("Area of Rectangle 1: %.2f\n\n", getArea(rect1));

    // Test moveRect
    printf("Moving Rectangle 1 by offset (2, 3)...\n");
    moveRect(&rect1, 2.0, 3.0);
    printf("New position: (%.1f, %.1f)\n\n", rect1.position.x, rect1.position.y);

    // Test scaleRect
    printf("Scaling Rectangle 1 to width=6, height=5...\n");
    scaleRect(&rect1, 6.0, 5.0);
    printf("New dimensions: width=%.1f, height=%.1f\n", rect1.width, rect1.height);
    printf("New area: %.2f\n\n", getArea(rect1));

    // Test intersect
    printf("Rectangle 1: position(%.1f, %.1f), width=%.1f, height=%.1f\n",
           rect1.position.x, rect1.position.y, rect1.width, rect1.height);
    printf("Rectangle 2: position(%.1f, %.1f), width=%.1f, height=%.1f\n",
           rect2.position.x, rect2.position.y, rect2.width, rect2.height);

    if (intersect(rect1, rect2))
    {
        printf("Result: Rectangles DO intersect\n\n");
    }
    else
    {
        printf("Result: Rectangles DO NOT intersect\n\n");
    }

    // Test non-intersecting rectangles
    rectangle_t rect3 = {{0.0, 0.0}, 1.0, 1.0};
    rectangle_t rect4 = {{5.0, 5.0}, 2.0, 2.0};

    printf("Rectangle 3: position(%.1f, %.1f), width=%.1f, height=%.1f\n",
           rect3.position.x, rect3.position.y, rect3.width, rect3.height);
    printf("Rectangle 4: position(%.1f, %.1f), width=%.1f, height=%.1f\n",
           rect4.position.x, rect4.position.y, rect4.width, rect4.height);

    if (intersect(rect3, rect4))
    {
        printf("Result: Rectangles DO intersect\n");
    }
    else
    {
        printf("Result: Rectangles DO NOT intersect\n");
    }

    return 0;
}