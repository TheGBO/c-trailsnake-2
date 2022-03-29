#include "game.h"

int main(){
    SDL_Keycode key = SDLK_d;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){
        printf("SDL2 Error - Failed to init SDL2\n");
        return -1;
    }

    SDL_Window* win = SDL_CreateWindow("The W", 0, 0, 800, 600, 0);
    Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, renderer_flags);

    SDL_Surface *surface = SDL_GetWindowSurface(win);
    if(!surface){
        printf("error initializing surface");
        return -1;
    } 

    int close_requested = 0;

    start();
    while (!close_requested)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                close_requested = 1;
            }
            if(event.type == SDL_KEYDOWN){
                key = event.key.keysym.sym;
                input(key);
                
            }
        }
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderClear(renderer);
        tick();
        render(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(win);
    
    return 0;
}