#include<stdio.h>
#include<SDL2/SDL.h>

#define WIDTH 1200
#define HEIGHT 700
#define COLOR_WHITE 0xffffffff
#define COLOR_BLACK 0x00000000
#define COLOR_ORANGISH 0xff9966

struct Circle{
    int x;
    int y;
    int radius;
};

/**
    - PARAMS:
        - SDL_Surface* surface: The SDL surface to draw on.
        - struct Circle circle: The circle to fill, defined by its center coordinates (x, y) and radius.

    - DESCRIPTION: This function iterates over each pixel within the circle's bounding box and checks if it lies within the circle. If it does, the pixel is filled with white color.

    - NOTE: This function assumes that the SDL surface is already initialized and that the circle's radius is non-negative.
*/

void FillCircle(SDL_Surface* surface, struct Circle circle){

    int low_x = circle.x - circle.radius;
    int low_y = circle.y - circle.radius;
    int high_x = circle.x + circle.radius;
    int high_y = circle.y + circle.radius;


    int radius_squared = circle.radius * circle.radius;

    for(int x = low_x; x < high_x; x++){
        for (int y = low_y; y < high_y; y++){

            int center_distance_squared = (x-circle.x)*(x-circle.x) + (y-circle.y)*(y-circle.y);
            // is co-ordinate within circle
            if(center_distance_squared<radius_squared){
                SDL_Rect pixel = (SDL_Rect){x,y,1,1};
                SDL_FillRect(surface, &pixel, COLOR_ORANGISH);
            }
        }
    }
};


int main(){
    // printf("hello");
    SDL_Init(SDL_INIT_VIDEO);

    //
    SDL_Window* window = SDL_CreateWindow(
        "Bouncy Ball",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        0
    );


    SDL_Surface* surface = SDL_GetWindowSurface(window);

    /*
    // creating circle
    SDL_Rect rect = (SDL_Rect){
        200, 200, 100, 100
    };
    SDL_FillRect(surface, &rect, 0xffffffff);
    */


    struct Circle circle = (struct Circle){200, 200, 50};
    FillCircle(surface, circle);

    SDL_UpdateWindowSurface(window);
    SDL_Delay(3000);

    return 0;
}
