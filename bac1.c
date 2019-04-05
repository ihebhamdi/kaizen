#include "bac1.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
void charger_Background(Background *B)
{
	
	B->backgroundImg = IMG_Load("/home/makki/oo/baaac.png");
	
	
}


void initBackground(Background *B)
{
	B->back_Pos.x=0;
	B->back_Pos.y=0;
	B->back_Pos.w=700;
	B->back_Pos.h=700;
B->camera.x=0;
B->camera.y=0;
B->camera.w=1800;
B->camera.h=900;
}

void blitBackground(Background *B,SDL_Surface *screen)
{


}

void freeBackground(Background *B)
{
	SDL_FreeSurface(B->backgroundImg);
}




void scrol(Background *B, SDL_Surface *screen, SDL_Event * event ){
switch(event->type)
{
case SDL_KEYDOWN:
 if(event->key.keysym.sym==SDLK_RIGHT){

B->camera.x+=10;}
 if(event->key.keysym.sym==SDLK_LEFT){
if(B->camera.x!=0){
B->camera.x-=10;}}
}
SDL_BlitSurface(B->backgroundImg,&B->camera,screen,NULL);
SDL_Flip(screen);
}
