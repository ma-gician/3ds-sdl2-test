#include <iostream>
#include "item.h"
#include <3ds.h>

void windowFunction(int winX, int winY){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "sdl no worky :(" << std::endl;
    }else{
        std::cout << "sdl does work actually tho" << std::endl;
    }

    SDL_Window* topscr = SDL_CreateWindow("SDL2_Test",0,0,400,240,0);
    SDL_Window * bottomscr = SDL_CreateWindow("SDL2_Test",0,240,320,240,0);

    SDL_Renderer * topscreen = SDL_CreateRenderer(topscr,-1, SDL_RENDERER_SOFTWARE);
    SDL_Renderer * bottomscreen = SDL_CreateRenderer(bottomscr,-1, SDL_RENDERER_SOFTWARE);

    item card;
    card.setRenderer(bottomscreen);
    card.loadImage("cards/w.png");

    item card2;
    card2.setRenderer(topscreen);
    card2.loadImage("cards/b4.png");

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
        SDL_RenderClear(bottomscreen);
        card.setSize(20,30);
        card.draw(ang);
        SDL_RenderPresent(bottomscreen);

        SDL_RenderClear(topscreen);
        card2.setSize(20,30);
        card2.draw(ang);
        SDL_RenderPresent(topscreen);

        ang ++;
    }
}
