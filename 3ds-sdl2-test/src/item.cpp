#include "item.h"
#include <iostream>

void itemInit()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
}

void itemQuit()
{
    SDL_Quit();
    IMG_Quit();
}

item::item()
{
    pos.x = 27;
    pos.y = 63;
    image = NULL;
    pos.w = 100;
    pos.h = 100;

}

item::~item()
{
    if(image != NULL)
    {
        SDL_DestroyTexture(image);
        image = NULL;
    }
}

bool item::loadImage(std::string filename)
{
    if(image != NULL)
    {
        SDL_DestroyTexture(image);
        image = NULL;
    }
    SDL_Surface * temp = IMG_Load(filename.c_str());
    if(temp != NULL)
    {
        image = SDL_CreateTextureFromSurface(ren, temp);
        SDL_FreeSurface(temp);
        if(image != NULL)
            return true;
    }
    return false;
}

void item::setSize(int w, int h)
{
    pos.w = w;
    pos.h = h;
}

void item::setRenderer(SDL_Renderer * dest)
{
    ren = dest;
}

void item::draw(double angle)
{
    if(image != NULL)
    {
        SDL_Point pt;
        pt.x = pos.w/2;
        pt.y = pos.h/2;
        pt.x += pos.x;
        pt.y =+ pos.y;
        SDL_RenderCopyEx(ren, image, NULL, &pos, angle, &pt, SDL_FLIP_NONE);
    }
}

void item::draw()
{
    if(image != NULL)
    {
        SDL_RenderCopy(ren, image, NULL, &pos);
    }
    else
    {
        std::cout << "bruh the image is NULL!?! (in draw of course)";
    }
}
