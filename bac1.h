#ifndef BACKGROUND_H_
#define BACKGROUND_H_



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>




struct Background{
	SDL_Surface* backgroundImg;
	SDL_Rect back_Pos;
SDL_Rect camera;
};
typedef struct Background Background;


void charger_Background(Background *B);
void initBackground(Background *B);
void freeBackground(Background *B);
void blitBackground(Background *B,SDL_Surface* screen);
void scrol(Background *B, SDL_Surface *screen, SDL_Event * event );



#endif
