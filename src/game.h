#ifndef GAME_H_INC
#define GAME_H_INC

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#define block_size 10

void start();
void input(SDL_Keycode key);
void tick();
void render(SDL_Renderer* renderer);


#endif