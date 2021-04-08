#include "ScreenSpaceTransformer.h"
#include <stdlib.h>

ScreenTransformer *ScreenTransformer_Create(const float xFactor_in, const float yFactor_in) 
{
    ScreenTransformer *st = (ScreenTransformer *) malloc(sizeof(ScreenTransformer));
    st->xFactor = xFactor_in;
    st->yFactor = yFactor_in;
    return st;
}

Vec2 ScreenTransformer_Transform(ScreenTransformer *st, Vec3 *v) 
{
    Vec2 transformed;
    transformed.x = (v->x + 1.0f) * st->xFactor;
    transformed.y = (-v->y + 1.0f) * st->yFactor;
    return transformed;
}

void ScreenTransformer_Destroy(ScreenTransformer *st) 
{
    free(st); 
}