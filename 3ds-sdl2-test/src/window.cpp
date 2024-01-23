#include <iostream>
#include "item.h"
#include <3ds.h>

void windowFunction(int winX, int winY){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "sdl no worky :(" << std::endl;
    }else{
        std::cout << "sdl does work actually tho" << std::endl;
    }

    SDL_Window* win = SDL_CreateWindow("SDL2_Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,winX,winY,0);

    SDL_Renderer * screen = SDL_CreateRenderer(win,-1, SDL_RENDERER_SOFTWARE);

    item bob;
    bob.setRenderer(screen);
    bob.loadImage("cards/w.png");

    int close = 0;

    double ang = 0;

    while(!close){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    close = 1;
                    break;
            }
        }
        SDL_RenderClear(screen);
        bob.setSize(235,325);
        bob.draw(ang);
        SDL_RenderPresent(screen);
        ang ++;
    }
}
