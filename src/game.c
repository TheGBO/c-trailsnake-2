#include "game.h"

SDL_Rect r;
SDL_Rect trails[2400];
SDL_Rect walls[2400];
SDL_Rect fruits[2400];
SDL_Keycode keyp = SDLK_d;
int trail_num = 0;
int score = 0;

void removeFruit(SDL_Rect *array, int index, int array_length)
{
   int i;
   for(i = index; i < array_length - 1; i++) array[i] = array[i + 1];
}

void updateScore(){
    score++;
    printf("New Score: %d \n", score);
}

void gameOver(){
    printf("Game Over :( \n");
    SDL_Quit();
    exit(0);
}

void start(){
    srand(time(NULL));
    r.x = 0;
    r.y = 0;
    r.w = block_size;
    r.h = block_size;
    for (int x = 0; x < 80; x++)
    {
        SDL_Rect wall;
        wall.y = rand() % 60 * block_size;
        wall.x = rand() % 80 * block_size;
        wall.h = block_size;
        wall.w = block_size;
        walls[x] = wall;
    }

    for (int x = 0; x < 80; x++)
    {
        SDL_Rect fruit;
        fruit.y = rand() % 60 * block_size;
        fruit.x = rand() % 80 * block_size;
        fruit.h = block_size;
        fruit.w = block_size;
        fruits[x] = fruit;
    }
}

void input(SDL_Keycode key){
    keyp = key;
}

void tick(){
    SDL_Rect trail;
    trail.x = r.x;
    trail.y = r.y;
    trail.w = block_size;
    trail.h = block_size;
    trails[trail_num] = trail;

    if(keyp == SDLK_d){
        r.x += block_size;
    }
    if(keyp == SDLK_a){
        r.x -= block_size;
    }
    if(keyp == SDLK_w){
        r.y -= block_size;
    }
    if(keyp == SDLK_s){
        r.y += block_size;
    }

    for (int i = 0; i < 2400; i++)
    {
        SDL_Rect testTrail;
        testTrail = trails[i];

        SDL_Rect testWall;
        testWall = walls[i];

        SDL_Rect testFruit;
        testFruit = fruits[i];
        if(r.x == testTrail.x && r.y == testTrail.y){
            gameOver();
        }
        if(r.x == testWall.x && r.y == testWall.y){
            gameOver();
        }
        if(r.x == testFruit.x && r.y == testFruit.y){
            updateScore();
            removeFruit(fruits, i, 2400);
        }
    }
    SDL_Delay(1000/12);
    trail_num++;
}

void render(SDL_Renderer* renderer){
    for (int i = 0; i < 2400; i++)
    {
        SDL_SetRenderDrawColor( renderer, 170, 15, 170, 255 );
        SDL_RenderFillRect( renderer, &fruits[i] );
        SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
        SDL_RenderFillRect( renderer, &trails[i] );
        SDL_SetRenderDrawColor( renderer, 90, 90, 90, 255 );
        SDL_RenderFillRect( renderer, &walls[i] );
    }
    
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect( renderer, &r );
}