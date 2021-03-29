#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct Triangle {
    struct Vec2 *v0;
    struct Vec2 *v1;
    struct Vec2 *v2;
} Triangle;

Triangle *Triangle_Create(struct Vec2 *v0, struct Vec2 *v1, struct Vec2 *v2);
void Triangle_Render(Triangle *triangle, struct SDL_Renderer *renderer);
void Triangle_Destroy(Triangle *triangle);

#endif