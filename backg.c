#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
#include "backg.h"
#include <SDL/SDL_ttf.h>
void initbackground(backg *b ){
int t;
b->gamebackglvl1=IMG_Load("ress/1min.png");
b->backgr.x=0;
b->backgr.y=0;
b->backgr.w=1300;
b->backgr.h=705;
}

void affichebackground(SDL_Surface* screen, backg *b){
SDL_BlitSurface(b->gamebackglvl1,NULL,screen,&b->backgr);
} 
void freesurfaces(backg *b){
SDL_FreeSurface(b->gamebackglvl1);
}
