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
int lvl3 (SDL_Surface *screen)
{int vie=3;
TTF_Font *police=NULL;
SDL_Surface  *win,*lose;
char menu[20];
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(height, width, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
SDL_Event ev;
enigme e[15];
int playagain=0;
int continuer =1;
int indice=0;
int lvl=3,pl;
int result=5 ;
int etat=1;
SDL_bool fullscreen;
int curseur=0 ;
SDL_Surface* bg=NULL;
bg=IMG_Load("enigme/start.PNG");
lose=IMG_Load("enigme/gameover.PNG");
win=IMG_Load("enigme/goodjob.PNG");
initialiser_enigme (e);
SDL_EnableKeyRepeat(10,10);
indice=generatin_aleatoire(indice,lvl);
while (continuer)
{
 SDL_PollEvent(&ev);
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
case SDLK_p:
playagain=1;
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
if(playagain==1)
{
jeu(screen);
}
}
else if(result==1)
{
SDL_BlitSurface(lose,NULL,screen,NULL);
if(playagain==1)
{
jeu(screen);
}

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

