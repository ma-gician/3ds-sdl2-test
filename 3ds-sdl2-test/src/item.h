#ifndef IMAGESANDITEMS
#define IMAGESANDITEMS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <3ds.h>

void itemInit();
void itemQuit();

class item
{
    public:
        item();
        virtual ~item();
        bool loadImage(std::string filename);
        void setRenderer(SDL_Renderer * renderer);
        void setSize(int w, int h);
        void draw(double angle);
        void draw();

    private:
        SDL_Renderer * ren;
        SDL_Texture * image;
        SDL_Rect pos;
};

#endif
