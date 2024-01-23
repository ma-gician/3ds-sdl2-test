//c++ standard libs
#include <iostream>
//3rd party libs
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//include other scripts
#include "window.h"
int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    windowFunction(400,240);
    return 0;
}
