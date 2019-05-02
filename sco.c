#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sco.h"




void charger_vie_score (scorevie *sv) //vie
{
sv->image[0]=IMG_Load ("/home/makki/Bureau/kaizen/viiie.jpg");
/*sv->image[1]=IMG_Load ("");
sv->image[2]=IMG_Load ("");
sv->image[3]=IMG_Load ("");*/


}

void init_score_vie (scorevie *sv)
{

sv->vie_pos.x=5;
sv->vie_pos.y=0;

}






void afficherscore(scorevie *sv,SDL_Surface *screen) //blit vie
{
SDL_BlitSurface(sv->image[0],NULL,screen,&sv->vie_pos);
/*SDL_BlitSurface(sv->image[1],NULL,screen,&sv->vie_pos);
SDL_BlitSurface(sv->image[2],NULL,screen,&sv->vie_pos);
SDL_BlitSurface(sv->image[3],NULL,screen,&sv->vie_pos);*/
SDL_Flip(screen);
}

void freescorevie(scorevie *sv) //liberer la surface
{
	SDL_FreeSurface(s
v->image[0]);
/*SDL_FreeSurface(sv->image[1]);
SDL_FreeSurface(sv->image[2]);
SDL_FreeSurface(sv->image[3]);*/
      
}

void fin_jeu (score *sv)
{ 
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
TTF_Font *fonttexte;
fonttexte=TTF_OpenFont("BrigestScript.ttf",30);
	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
	SDL_Rect pos_msg;
	SDL_Surface image;
	pos_msg.x = 0;
	pos_msg.y = 0;

if ((sv->image[3]==NULL)&&(sv->image[2]==NULL)&&(sv->image[1]==NULL))
{
	const char msg[]="GAME OVER";
	image = TTF_RenderText_Shaded(fonttexte, affsc,couleurtexte,couleur);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(image, NULL, screen, &pos_msg); /* Blit du texte */
SDL_Flip(screen);
SDL_FreeSurface(image);


