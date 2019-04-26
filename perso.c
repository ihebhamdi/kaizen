#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
#include "backg.h"
#include <SDL/SDL_ttf.h>
#include "perso.h"

void initperso(perso *c ){
int t;
c->person=IMG_Load("ress/detective.png");
c->rect.x=100;
c->rect.y=100;
c->rect.w=200;
c->rect.h=200;
}

void afficheperso(SDL_Surface* screen, perso *c){
SDL_BlitSurface(c->person,NULL,screen,&c->rect);
} 

int deplacement(perso* c)
{
SDL_PollEvent(&c->event);
switch(c->event.type)
{case SDL_QUIT:
{
return 0;
  }
break;
case SDL_KEYDOWN:
 if(c->event.key.keysym.sym==SDLK_RIGHT)
  {
c->rect.x++;
  }
if(c->event.key.keysym.sym==SDLK_LEFT)
  {
c->rect.x--;
  }
break;
}
}

