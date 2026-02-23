#include <stdio.h>
#include "vec3.c"

void printVec3(const char *name, vec3_t v)
{
    printf("%s = (%.2f, %.2f, %.2f)\n", name, v.x, v.y, v.z);
}

int main()
{
    printf("=== Vec3 Module Test ===\n");
    printf("Constant Vectors\n");
    printf("zero = (%.2f, %.2f, %.2f)\n", zero.x, zero.y, zero.z);
    printf("e1   = (%.2f, %.2f, %.2f)\n", e1.x, e1.y, e1.z);
    printf("e2   = (%.2f, %.2f, %.2f)\n", e2.x, e2.y, e2.z);
    printf("e3   = (%.2f, %.2f, %.2f)\n", e3.x, e3.y, e3.z);

    vec3_t v1 = {3.0f, 4.0f, 0.0f};
    vec3_t v2 = {1.0f, 2.0f, 2.0f};
    printVec3("v1", v1);
    printVec3("v2", v2);
    printf("\n");

    float dot = dotProduct(v1, v2);
    printf("Dot product (v1 · v2) = %0.2f\n", dot);
    printf("\n");

    vec3_t cross = crossProduct(v1, v2);
    printf("Cross product (v1 x v2):\n");
    printVec3("result", cross);
    printf("\n");

    float mag1 = magnitude(v1);
    float mag2 = magnitude(v2);
    printf("Magnitude of v1: %0.2f\n", mag1);
    printf("Magnitude of v2: %0.2f\n", mag2);

    float dist = distance(v1, v2);
    printf("Distance between v1 & v2: %0.2f\n", dist);
    printf("\n");

    vec3_t v1_norm = normalize(v1);
    vec3_t v2_norm = normalize(v2);
    printf("Normalized vectors:\n");
    printVec3("v1 normalised", v1_norm);
    printf("Magnitude: %0.2f\n", magnitude(v1_norm));
    printVec3("v1 normalised", v1_norm);
    printf("Magnitude: %0.2f\n", magnitude(v1_norm));
    printf("\n");

    printf("Unit vectors orthoginality test:\n");
    printf("e1 · e2 = %0.2f (should be 0)\n", dotProduct(e1, e2));
    printf("e1 · e3 = %0.2f (should be 0)\n", dotProduct(e1, e3));
    printf("e2 · e3 = %0.2f (should be 0)\n", dotProduct(e2, e3));
}