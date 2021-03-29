#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct Triangle {
    struct SDL_Point *v0;
    struct SDL_Point *v1;
    struct SDL_Point *v2;
} Triangle;

Triangle *Triangle_Create(struct SDL_Point *v0, struct SDL_Point *v1, struct SDL_Point *v2);
void Triangle_Render(Triangle *triangle, struct SDL_Renderer *renderer);
void Triangle_Destroy(Triangle *triangle);

#endif