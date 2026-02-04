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

/// @brief calculates the dot product of two vectors
/// @param v1 first vector
/// @param v2 second vector
/// @return dot product
extern float dotProduct (vec3_t v1, vec3_t v2);

/// @brief calculates the cross product of two vectors
/// @param v1 first vector
/// @param v2 second vector
/// @return cross product
extern vec3_t crossProduct (vec3_t v1, vec3_t v2);

/// @brief calculates the magnitude of a vector
/// @param v vwctor which magnitude shall be computed
/// @return magnitude (length) of the vector
extern float magnitude (vec3_t v);

/// @brief calculates the distnace between two vectros or points
/// @param v1 first vector (or point)
/// @param v2 second vector (or point)
/// @return distance between vectors
extern float distance (vec3_t v1, vec3_t v2);

/// @brief Normalizes a vector to unit length
/// @param v vector to be mormalized
/// @return normalized vector
extern vec3_t normalize (vec3_t v);
#endif