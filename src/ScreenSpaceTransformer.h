#ifndef SCREEN_SPACE_TRANSFORMER_H
#define SCREEN_SPACE_TRANSFORMER_H

#include "Vec2.h"
#include "Vec3.h"

typedef struct ScreenTransformer {
    float xFactor;
    float yFactor;
} ScreenTransformer;

ScreenTransformer *ScreenTransformer_Create(const float xFactor_in, const float yFactor_in);
Vec2 ScreenTransformer_Transform(ScreenTransformer *st, Vec3 *v);
void ScreenTransformer_Destroy(ScreenTransformer *st);

#endif