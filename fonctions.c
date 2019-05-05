#include "fonctions.h"
#include<stdio.h> 
#include<SDL/SDL.h> 
#include<SDL/SDL_image.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

void initialiser_enigme (enigme e[])
{
//TTF_Init();
//police=TTF_OpenFont("fonts-japanese-gothic.ttf",30);
int i;


for (i=1;i<15;i++)
{
char menu[20];
sprintf(menu,"enigme/%d.png",i);
e[i].enigme=IMG_Load(menu); 
e[i].etat=0;
e[i].posenigme.x=100;
e[i].posenigme.y=100;
}
e[1].quiz=1;
e[2].quiz=2;
e[3].quiz=1;
e[4].quiz=1;
e[5].quiz=3;
e[6].quiz=1;
e[7].quiz=1;
e[8].quiz=1;
e[9].quiz=2;
e[10].quiz=1;
e[11].quiz=3;
e[12].quiz=1;
e[13].quiz=1;
e[14].quiz=1;
}

int SDL_SetWindowFullscreen(SDL_Surface* screen , SDL_bool fullscreen)
{
if(SDL_SetWindowFullscreen(screen , SDL_TRUE) <0)
{
        printf("Erreur lors du passage en mode plein ecran : %s",SDL_GetError());
        return EXIT_FAILURE;
}
}
int enigmequiz(int quiz, int curseur )
{
if (curseur==0)
{
return 5;
}
if (curseur==quiz)
{
return 0;
printf("vrai");
}
else
{ 
return 1;
printf("faux");
}
}
int generatin_aleatoire(int nbalea,int lvl)


{


srand(time(NULL));

if(lvl==1)
{
nbalea=1+rand()%5;
}
if(lvl==2)
{
nbalea=6+rand()%5;
}
if(lvl==3)
{
nbalea=11+rand()%5;
}
return nbalea;


}

void afficher_enigme (enigme e[],int lvl,int indice,SDL_Surface *screen)
{
SDL_BlitSurface(e[indice].enigme,NULL,screen,NULL);
}




