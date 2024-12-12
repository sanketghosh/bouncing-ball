#include<stdio.h>
#include<SDL2/SDL.h>

#define WIDTH 1200
#define HEIGHT 700

int main(){
    // printf("hello");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindow(
        "Bouncy Ball",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        0
    );
    SDL_Delay(3000);
    return 0;
}
