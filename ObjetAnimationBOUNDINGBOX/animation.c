#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"
//#include "bac1.h"

	/********** INITIALISATION DU PERSONNNAGE **************/

void init_player(Player *player )
{
(player->positionPlayer).x=0 ;
(player->positionPlayer).y=70;
}
	/************ CHARGERMENT IMAGE **************/
void chargement_image (Player *player)
{
           /***** RIGHT *******/
(player->update_player)=IMG_Load("m.png");

	   /*****  UP   *******/
(player->image1)=IMG_Load("s.png");
}
	/************ANIMATION*******************************/
void animer_player(Player *player)
{

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1300,700,32,SDL_HWSURFACE);
SDL_BlitSurface((player->image1), NULL, screen, &(player->positionPlayer));
SDL_Flip(screen);
SDL_FreeSurface(player->image1);
int continuer = 1;
SDL_Event event;
while (continuer)
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break ; 
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_UP)
{
player->react=1;
}
if(event.key.keysym.sym==SDLK_RIGHT)
{
player->react=0;	
}
}
break;
}
if(player->react==0){
	(player->update_player)=IMG_Load("m.png");
	SDL_BlitSurface((player->update_player), NULL, screen, &(player->positionPlayer));}
if(player->react==1){
	(player->update_player)=IMG_Load("s.png");
	SDL_BlitSurface((player->update_player), NULL, screen, &(player->positionPlayer));}
SDL_Flip(screen);
SDL_FreeSurface(player->update_player);
}
