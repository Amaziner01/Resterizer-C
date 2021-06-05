#ifndef LINEAR_H
#define LINEAR_H

struct _vec3
{
    float x, y, z;
};

typedef struct _vec3 vec3_t;

struct _vec3i
{
    int x, y, z;
};

typedef struct _vec3i ivec3_t;

struct _vec2
{
    float x, y;
};

typedef struct _vec2 vec2_t;


struct _mat3
{
    vec3_t r1;
    vec3_t r2;
    vec3_t r3;
};

typedef struct _mat3 mat3_t;

vec3_t vec3_add(vec3_t v1, vec3_t v2);
vec3_t vec3_sub(vec3_t v1, vec3_t v2);
vec3_t vec3_mul(vec3_t v1, vec3_t v2);
vec3_t vec3_div(vec3_t v1, vec3_t v2);

float vec3_dot(vec3_t v1, vec3_t v2);
vec3_t vec3_cross(vec3_t v1, vec3_t v2);

vec3_t vec3_normalize(vec3_t v);

vec3_t vec3_mul_mat3(vec3_t v, mat3_t m);

mat3_t mat3_translate(vec3_t v);
mat3_t mat3_scale(vec3_t v);
mat3_t mat3_rotate_x(float a);
mat3_t mat3_rotate_y(float a);
mat3_t mat3_rotate_z(float a);

#endif
