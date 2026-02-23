#ifndef _VEC3_T_
#define _VEC3_T_
typedef struct
{
    float x;
    float y;
    float z;
} vec3_t;

extern const vec3_t zero; // coordinate origin
extern const vec3_t e1; // unit vector x Axis
extern const vec3_t e2; // unit vector y Axis
extern const vec3_t e3; // unit vector z Axis

extern float dotProduct (vec3_t v1, vec3_t v2);
extern vec3_t crossProduct (vec3_t v1, vec3_t v2);
extern float magnitude (vec3_t v);
extern float distance (vec3_t v1, vec3_t v2);
extern vec3_t normalize (vec3_t v);

#endif