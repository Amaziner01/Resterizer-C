#include "linear.h"
#include <math.h>

vec3_t vec3_add(vec3_t v1, vec3_t v2)
{
    vec3_t v = {
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    };

    return v;
}

vec3_t vec3_sub(vec3_t v1, vec3_t v2)
{
    vec3_t v = {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };

    return v;
}

vec3_t vec3_mul(vec3_t v1, vec3_t v2)
{
    vec3_t v = {
        v1.x * v2.x,
        v1.y * v2.y,
        v1.z * v2.z
    };

    return v;
}

vec3_t vec3_div(vec3_t v1, vec3_t v2)
{
    vec3_t v = {
        v1.x / v2.x,
        v1.y / v2.y,
        v1.z / v2.z
    };

    return v;
}

float vec3_dot(vec3_t v1, vec3_t v2)
{
    return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

vec3_t vec3_cross(vec3_t v1, vec3_t v2)
{
    vec3_t v = {
        v1.y*v2.z - v1.z*v2.y,
        v1.x*v2.z - v1.z*v2.x,
        v1.y*v2.x - v1.x*v2.y
    };    

    return v;
}

#define sqr(x)((x)*(x))
vec3_t vec3_normalize(vec3_t v)
{
    float dist = sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z));
    vec3_t ret = {
        v.x / dist,
        v.y / dist,
        v.z / dist
    };

    return ret;
}

vec3_t vec3_mul_mat3(vec3_t v1, mat3_t m1)
{
    vec3_t v = {
       v1.x*m1.r1.x + v1.y*m1.r1.y + v1.z*m1.r1.z, 
       v1.x*m1.r2.x + v1.y*m1.r2.y + v1.z*m1.r2.z, 
       v1.x*m1.r3.x + v1.y*m1.r3.y + v1.z*m1.r3.z 
    };

    return v;
}

mat3_t mat3_translate(vec3_t v)
{
    mat3_t m = {
        { 1.0f, 0.0f, v.x },
        { 0.0f, 1.0f, v.y },
        { 0.0f, 0.0f, v.z }
    };

    return m;
}

mat3_t mat3_scale(vec3_t v)
{
    mat3_t m = {
        { v.x, 0.0f, 0.0f },
        { 0.0f, v.y, 0.0f },
        { 0.0f, 0.0f, v.z }
    };

    return m;
}

mat3_t mat3_rotate_x(float a)
{
    float csin = sin(a);
    float ccos = cos(a);

    mat3_t rot = {
        { 1.0f, 0.0f, 0.0f },
        { 0.0f, ccos, csin },
        { 0.0f,-csin, ccos }    
    };

    return rot;
}

mat3_t mat3_rotate_y(float a)
{
    float csin = sin(a);
    float ccos = cos(a);

    mat3_t rot = {
        { ccos, 0.0f, csin },
        { 0.0f, 1.0f, 0.0f },
        {-csin, 0.0f, ccos }
    };

    return rot;
}

mat3_t mat3_rotate_z(float a)
{
    float csin = sin(a);
    float ccos = cos(a);

    mat3_t rot = {
        { ccos, csin, 0.0f },
        {-csin, ccos, 0.0f },
        { 0.0f, 0.0f, 1.0f }
    };

    return rot;
}
