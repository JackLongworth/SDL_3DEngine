#ifndef VEC2_H
#define VEC2_H

typedef struct Vec2 {
    float x;
    float y;
} Vec2;

float Vec2_LengthSquared(const Vec2 *v);
float Vec2_Length(const Vec2 *v);
void Vec2_Normalise(Vec2 *v);
Vec2 Vec2_Minus(const Vec2 *v1, const Vec2 *v2);
Vec2 Vec2_Add(const Vec2 *v1, const Vec2 *v2);
void Vec2_Scale(Vec2 *v, const float scalar);
Vec2 Vec2_TimesScalar(const Vec2 *v, const float scalar);
float Vec2_DotProduct(const Vec2 *v1, const Vec2 *v2);
Vec2 Vec2_TimesMat2(const Vec2 *lhs, const struct Mat2 *rhs);
void Vec2_ApplyMat2(Vec2 *lhs, const struct Mat2 *rhs);

#endif