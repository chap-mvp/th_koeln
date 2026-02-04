#include <stdio.h>
#include "vec3.h"

void printVec3(const char *name, vec3_t v)
{
    printf("%s = (%.2f, %.2f, %.2f)\n", name, v.x, v.y, v.z);
}

int main(void)
{
    printf("=== Vec3 Module Test ===\n\n");

    // Test constant vectors
    printf("Constant Vectors:\n");
    printVec3("zero", zero);
    printVec3("e1", e1);
    printVec3("e2", e2);
    printVec3("e3", e3);
    printf("\n");

    // Create test vectors
    vec3_t v1 = {3.0f, 4.0f, 0.0f};
    vec3_t v2 = {1.0f, 2.0f, 2.0f};

    printVec3("v1", v1);
    printVec3("v2", v2);
    printf("\n");

    // Test dot product
    float dot = dotProduct(v1, v2);
    printf("Dot product (v1 · v2) = %.2f\n", dot);
    printf("\n");

    // Test cross product
    vec3_t cross = crossProduct(v1, v2);
    printf("Cross product (v1 × v2):\n");
    printVec3("result", cross);
    printf("\n");

    // Test magnitude
    float mag1 = magnitude(v1);
    float mag2 = magnitude(v2);
    printf("Magnitude of v1: %.2f\n", mag1);
    printf("Magnitude of v2: %.2f\n", mag2);
    printf("\n");

    // Test distance
    float dist = distance(v1, v2);
    printf("Distance between v1 and v2: %.2f\n", dist);
    printf("\n");

    // Test normalize
    vec3_t v1_norm = normalize(v1);
    vec3_t v2_norm = normalize(v2);
    printf("Normalized vectors:\n");
    printVec3("v1 normalized", v1_norm);
    printf("Magnitude: %.2f\n", magnitude(v1_norm));
    printVec3("v2 normalized", v2_norm);
    printf("Magnitude: %.2f\n", magnitude(v2_norm));
    printf("\n");

    // Test orthogonality of unit vectors
    printf("Unit vectors orthogonality test:\n");
    printf("e1 · e2 = %.2f (should be 0)\n", dotProduct(e1, e2));
    printf("e1 · e3 = %.2f (should be 0)\n", dotProduct(e1, e3));
    printf("e2 · e3 = %.2f (should be 0)\n", dotProduct(e2, e3));

    return 0;
}