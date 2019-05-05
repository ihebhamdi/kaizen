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
int lvl1 (SDL_Surface *screen)
{int recu=0,vie=3;
TTF_Font *police=NULL;
SDL_Surface *fond,*win,*lose,*bplay;
char menu[20];
SDL_Surface *pactuel=NULL;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(height, width, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
SDL_Event ev;
int obtenue=0 ;
enigme e[15];
char tryagain=0;
int continuer =1;
int lvl=1;
int result=5 ;
int etat=1,indice=0;
SDL_bool fullscreen;
int curseur=0 ;
initialiser_enigme (e);
bplay= IMG_Load ("enigme/start.png");
lose=IMG_Load("enigme/tryagain.PNG");
win=IMG_Load("enigme/bravo.PNG");
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
break ;
case SDLK_a:
curseur=1;
break;
case SDLK_b:
curseur=2;
break;
case SDLK_c:
curseur=3;
break;
case SDLK_r:
tryagain=1;
break;
}
break ;
}
if(etat == 1)
{
if (curseur == 0)
{

afficher_enigme (e,lvl,indice,screen);
}
else {
result=enigmequiz(e[indice].quiz,curseur );
printf(" curseur= %d",curseur);
printf(" result= %d",result);

if (result==0)
{
SDL_BlitSurface(win,NULL,screen,NULL);

lvl=2;
continuer=0;
}
else if(result==1)
{
SDL_BlitSurface(lose,NULL,screen,NULL);
indice=generatin_aleatoire(indice,lvl);
result=5;
etat=1;
curseur=0;

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

