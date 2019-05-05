#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"
    #define TEMPS       30 
    #define height 1200
    #define width 700
int lvl2 (SDL_Surface *screen)
{int vie=3;
TTF_Font *police=NULL;
SDL_Surface  *win,*lose;
char menu[20];
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(height, width, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
SDL_Event ev;
enigme e[15];
int tryagain=0;
int continuer =1;
int indice=0;
int lvl=2,pl;
int result=5 ;
int etat=1;
SDL_bool fullscreen;
int curseur=0 ;
initialiser_enigme (e);
lose=IMG_Load("enigme/tryagain.PNG");
win=IMG_Load("enigme/lvl3.PNG");
SDL_EnableKeyRepeat(10,10);
indice=generatin_aleatoire(indice,lvl);
while (continuer)
{
 SDL_WaitEvent(&ev);
 switch(ev.type)
 {
  case SDL_QUIT:
   continuer = 0;
  break;
case SDL_KEYDOWN :
switch (ev.key.keysym.sym)
{
case SDLK_ESCAPE :
continuer =0 ;
break;
case SDLK_a:
curseur=1;
break;
case SDLK_b:
curseur=2;
break;
case SDLK_c:
curseur=3;
break;
}
break ;
}
if(etat == 1)
{
if (curseur == 0)
{

SDL_BlitSurface(e[indice].enigme,NULL,screen,NULL);
}
else {
result=enigmequiz(e[indice].quiz,curseur );

if (result==0)
{
SDL_BlitSurface(win,NULL,screen,NULL);
lvl=3;
continuer=0;
}
else if(result==1)
{
SDL_BlitSurface(lose,NULL,screen,NULL);
result=5;
etat=1;
curseur=0;
indice=generatin_aleatoire(indice,lvl);
}
}
}
SDL_Flip(screen);
}
SDL_FreeSurface(win);
SDL_FreeSurface(lose);
SDL_Quit();
return lvl;
}

