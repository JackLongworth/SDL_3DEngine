#include <SDL2/SDL.h>
#include "Triangle.h"
#include "Vec2.h"
#include "Vec3.h"
#include "ScreenSpaceTransformer.h"
#include "IndexedVertexList.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char running = 1;

    SDL_Window *window;
    SDL_Renderer *renderer;
    ScreenTransformer *st;

    const int windowWidth = 640;
    const int windowHeight = 640; 

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              windowWidth,
                              windowHeight,
                              0
                              );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    st = ScreenTransformer_Create(windowWidth/2, windowHeight/2);

    while (running) {

        SDL_Event event;
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_WINDOWEVENT_CLOSE:
            {
                if (window)
                {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    running = 0;
                }
            }
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        running = 0;
                    break;
                }
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);  // black
        SDL_RenderClear(renderer); // clear with last colour
        
        Vec3 v0 = { 0.0f,1.0f,0.0f };
        Vec3 v1 = { 0.5f, -0.8f ,0.0f };
        Vec3 v2 = { -0.5f,-0.5f,0.0f };
        
        Vec2 t0 = ScreenTransformer_Transform(st, &v0);
        Vec2 t1 = ScreenTransformer_Transform(st, &v1);
        Vec2 t2 = ScreenTransformer_Transform(st, &v2);

        Triangle *triangle;
        triangle = Triangle_Create(&t0, &t1, &t2);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
        Triangle_Render(triangle, renderer);

        IndexedVertexList *ivl = IVL_Create();
        VertexNode *vHead = ivl->headVertexNode;
        IVL_InsertVertexAtStart(&vHead, &v0);
        IVL_InsertVertexAtStart(&vHead, &v1);
        IVL_InsertVertexAtStart(&vHead, &v2);

        SDL_RenderPresent(renderer);

        Triangle_Destroy(triangle);

        SDL_Delay(100);
    }

    SDL_Quit();
    return 0;
}