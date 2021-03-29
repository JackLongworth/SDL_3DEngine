#include "Vec2.h"
#include "Mat2.h"
#include <math.h>

float Vec2_LengthSquared(const Vec2 *v)
{
    float lengthSquared = (v->x * v->x) + (v->y * v->y);
    return lengthSquared;
}

float Vec2_Length(const Vec2 *v) 
{
    float length = sqrt(Vec2_LengthSquared(v));
    return length;
}

void Vec2_Normalise(Vec2 *v) 
{
    float length = Vec2_Length(v);
    v->x /= length;
    v->y /= length;
}

Vec2 Vec2_Minus(const Vec2 *v1, const Vec2 *v2)
{
    Vec2 result;
    result.x = v1->x - v2->x;
    result.y = v1->y - v2->y;
    return result;
}

Vec2 Vec2_Add(const Vec2 *v1, const Vec2 *v2)
{
    Vec2 result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    return result; 
}

void Vec2_Scale(Vec2 *v, const float scalar)
{
    v->x *= scalar;
    v->y *= scalar;
}

Vec2 Vec2_TimesScalar(const Vec2 *v, const float scalar)
{
    Vec2 result;
    result.x = v->x * scalar;
    result.y = v->y * scalar;
    return result;
}

float Vec2_DotProduct(const Vec2 *v1, const Vec2 *v2) 
{
    float result = (v1->x * v2->x) + (v1->y * v2->x);
    return result;
}

Vec2 Vec2_TimesMat2(const Vec2 *lhs, const struct Mat2 *rhs)
{
    Vec2 result;
    result.x = lhs->x * rhs->elements[0][0] * rhs->elements[1][0];
    result.y = lhs->x * rhs->elements[0][1] * rhs->elements[1][1];
    return result;
}

void Vec2_ApplyMat2(Vec2 *lhs, const struct Mat2 *rhs)
{
    Vec2 v;
    v = Vec2_TimesMat2(lhs, rhs);
    lhs = &v;
}