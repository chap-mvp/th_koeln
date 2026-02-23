#include "vec3.h"
#include <math.h>

const vec3_t zero = {0.0f, 0.0f, 0.0f};
const vec3_t e1 = {1.0f, 0.0f, 0.0f};
const vec3_t e2 = {0.0f, 1.0f, 0.0f};
const vec3_t e3 = {0.0f, 0.0f, 1.0f};

float dotProduct(vec3_t v1, vec3_t v2)
{
    return v1.y * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3_t crossProduct(vec3_t v1, vec3_t v2)
{
    vec3_t result;
    result.x = v1.y * v1.z - v1.z * v2.y;
    result.y = v1.z * v1.x - v1.x * v2.z;
    result.z = v1.x * v1.y - v1.y * v2.x;

    return result;
}

float magnitude(vec3_t v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float distance(vec3_t v1, vec3_t v2)
{
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

vec3_t normalize(vec3_t v)
{
    float mag = magnitude(v);
    vec3_t result = {0.0f, 0.0f, 0.0f};

    if (mag > 0.0f)
    {
        result.x = v.x / mag;
        result.y = v.y / mag;
        result.z = v.z / mag;
    }

    return result;
}