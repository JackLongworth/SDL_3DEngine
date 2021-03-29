#include <SDL2/SDL.h>
#include <math.h>

#include "Triangle.h"
#include "Vec2.h"

Triangle *Triangle_Create(Vec2 *v0, Vec2 *v1, Vec2 *v2) 
{
    Triangle *triangle = (Triangle *) malloc(sizeof(Triangle));
    triangle->v0 = v0;
    triangle->v1 = v1;
    triangle->v2 = v2;

    return triangle;
}

// the point of the flat topped or bottom triangle must be in v2 of the triangle with v0 and v1 ordered 
// in terms of the x component ( y is obviously the same for each)

void renderFlatBottomOrTopTriangle(const Vec2 *v0, const Vec2 *v1, const Vec2 *v2, SDL_Renderer *renderer)
{
    const float m02 = (float)(v2->x - v0->x) / (float)(v2->y - v0->y);
    const float m12 = (float)(v2->x - v1->x) / (float)(v2->y - v1->y);

    int yStart = (int) ceilf( v2->y - 0.5f );
    int yEnd = (int) ceilf( v0->y - 0.5f );

    if (yStart > yEnd) {
        yStart = yStart^yEnd;
        yEnd = yStart^yEnd;
        yStart = yEnd^yStart;
    }

    for (int y = yStart; y < yEnd; y++) 
    {
        const float centreOfPixelY = (float) y + 0.5f;
        const int leftEdgeX = v0->x + (m02 * (centreOfPixelY - v0->y));
        const int rightEdgeX = v1->x + (m12 * (centreOfPixelY - v1->y));

        SDL_RenderDrawLine(renderer, leftEdgeX, centreOfPixelY, rightEdgeX, centreOfPixelY);
    }
}

void swap(Vec2 **p0, Vec2 **p1) 
{
    Vec2 *tmp = *p0;
    *p0 = *p1;
    *p1 = tmp;
}

void Triangle_Render(Triangle *triangle, SDL_Renderer *renderer)
{
    Vec2 *v0 = triangle->v0;
    Vec2 *v1 = triangle->v1;
    Vec2 *v2 = triangle->v2;

    // sort the points into ascending y component order
    if (v0->y > v1->y) swap(&v0, &v1);
    if (v1->y > v2->y) swap(&v1, &v2);
    if (v0->y > v1->y) swap(&v0, &v1);

    // flat top
    if (v0->y == v1->y) 
    {
        if (v0->x > v1->x) swap(&v0, &v1);
        renderFlatBottomOrTopTriangle(v0, v1, v2, renderer);
    } 
    // flat bottom
    else if (v1->y == v2->y) 
    {
        swap(&v0, &v2);
        if (v0->x > v1->x) swap(&v0, &v1);
        renderFlatBottomOrTopTriangle(v0, v1, v2, renderer);
    }
    // generic triangle
    else 
    {
        // find the splitting line
        const float alpha = (float)(v1->y - v0->y) / (float)(v2->y - v0->y);
        Vec2 v02 = Vec2_Minus(v2, v0);
        Vec2_Scale(&v02, alpha);
        
        const Vec2 split = Vec2_Add(v0, &v02);

        //major right
        if (triangle->v1->x < split.x) 
        {
            renderFlatBottomOrTopTriangle(v1, &split, v0, renderer);
            renderFlatBottomOrTopTriangle(v1, &split, v2, renderer);
        } 
        else // major left
        {
            renderFlatBottomOrTopTriangle(&split, v1, v0, renderer);
            renderFlatBottomOrTopTriangle(&split, v1, v2, renderer);
        }
    }
}

void Triangle_Destroy(Triangle *triangle) 
{
    free(triangle);
}