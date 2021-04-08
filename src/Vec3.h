#ifndef VEC3_H
#define VEC3_H

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

float Vec3_Length(const Vec3 *v);
void Vec3_Normalise(Vec3 *v);
Vec3 Vec3_Normalised(Vec3 *v);
Vec3 Vec3_Minus(const Vec3 *v1, const Vec3 *v2);
Vec3 Vec3_Add(const Vec3 *v1, const Vec3 *v2);
void Vec3_Scale(Vec3 *v, const float scalar);
Vec3 Vec3_Scaled(const Vec3 *v, const float scalar);
float Vec3_DotProduct(const Vec3 *v1, const Vec3 *v2);
Vec3 Vec3_TimesMat3(const Vec3 *lhs, const struct Mat3 *rhs);
void Vec3_ApplyMat3(Vec3 *lhs, const struct Mat3 *rhs);

#endif