#include "Vec3.h"
#include "Mat3.h"
#include <math.h>

float Vec3_LengthSquared(const Vec3 *v) 
{
    float lengthSquared = v->x*v->x + v->y*v->y + v->z*v->z;
    return lengthSquared;
}

float Vec3_Length(const Vec3 *v)
{
    float length = sqrtf(Vec3_LengthSquared(v));
    return length;
}

void Vec3_Normalise(Vec3 *v) 
{
    float length = Vec3_Length(v);
    v->x/=length;
    v->y/=length;
    v->z/=length;
}

Vec3 Vec3_Normalised(Vec3 *v) 
{
    Vec3 temp = *v;
    Vec3_Normalise(&temp);
    return temp;
}

Vec3 Vec3_Minus(const Vec3 *v1, const Vec3 *v2)
{
    Vec3 result;
    result.x = v1->x - v2->x;
    result.y = v1->y - v2->y;
    result.z = v1->z - v2->z;
    return result;
}

Vec3 Vec3_Add(const Vec3 *v1, const Vec3 *v2)
{
    Vec3 result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;
    return result;
}

void Vec3_Scale(Vec3 *v, const float scalar)
{
    v->x *= scalar;
    v->y *= scalar;
    v->z *= scalar;
}

Vec3 Vec3_Scaled(const Vec3 *v, const float scalar) 
{
    Vec3 result;
    result.x = v->x * scalar;
    result.y = v->y * scalar;
    result.z = v->z * scalar;
    return result;
}

float Vec3_DotProduct(const Vec3 *v1, const Vec3 *v2)
{
    float result;
    result = v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
    return result;
}

Vec3 Vec3_TimesMat3(const Vec3 *lhs, const struct Mat3 *rhs)
{
    Vec3 result;
    result.x = lhs->x * rhs->elements[0][0] + lhs->y * rhs->elements[1][0] + lhs->z * rhs->elements[2][0];
    result.y = lhs->x * rhs->elements[0][1] + lhs->y * rhs->elements[1][1] + lhs->z * rhs->elements[2][1];
    result.z = lhs->x * rhs->elements[0][2] + lhs->y * rhs->elements[1][2] + lhs->z * rhs->elements[2][2];
    return result;
}

void Vec3_ApplyMat3(Vec3 *lhs, const struct Mat3 *rhs)
{
    *lhs = Vec3_TimesMat3(lhs, rhs);
}