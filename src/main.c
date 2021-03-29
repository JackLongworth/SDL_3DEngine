#include <SDL2/SDL.h>
#include "Triangle.h"

int main(int argc, char *argv[]) 
{
    char running = 1;

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              640,
                              640,
                              0
                              );

    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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

        SDL_Point v0;
        v0.x = 500.0f;
        v0.y = 100.0f;

        SDL_Point v1;
        v1.x = 500.0f;
        v1.y = 200.0f;

        SDL_Point v2;
        v2.x = 100.0f;
        v2.y = 300.0f;
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);  // black
        SDL_RenderClear(renderer); // clear with last colour

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white

        Triangle *triangle;
        triangle = Triangle_Create(&v0, &v1, &v2);

        Triangle_Render(triangle, renderer);

        SDL_RenderPresent(renderer);

        Triangle_Destroy(triangle);

        SDL_Delay(100);
    }

    SDL_Quit();
    return 0;
}