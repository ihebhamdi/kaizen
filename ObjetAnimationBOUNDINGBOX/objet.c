#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "objet.h"

void affobj()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
SDL_Surface *obj;
SDL_Rect pos_obj;
screen=SDL_SetVideoMode(1300,700,32,SDL_HWSURFACE);
pos_obj.x=100;
pos_obj.y=0;
obj=IMG_Load("obj.png");
SDL_BlitSurface(obj, NULL, screen, &pos_obj);
SDL_Flip(screen);
SDL_FreeSurface(obj);
}
