#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include"camera.h"
#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct Background
    {
  
        SDL_Surface *background;
        SDL_Surface *backgroundCollision;
	SDL_Rect position;
   } Background;
#define MAX_X 4000
#define MAX_Y 4000
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
//void background_Collision(prince *entity);
void init_background(Background *back);
void charge_background(int scene,Background *background);
void affiche_background(Background *back,SDL_Rect *pos,SDL_Surface *ecran,SDL_Rect* camm );
void free_background(Background *back);
Background back;
#endif





