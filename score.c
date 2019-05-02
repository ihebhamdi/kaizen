#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


void charger_vie_score1 (score *sv) //score
{
sv->imagee[0]=IMG_Load("home/makki/Bureau/kaizen/viiie.jpg");}
/*sv->image1[1]=IMG_Load("");
sv->image1[2]=IMG_Load("");
sv->image1[3]=IMG_Load("");
sv->image1[4]=IMG_Load("");
sv->image1[5]=IMG_Load("");
}*/


void init_score_vie (score *sv)
{
sv->score_pos.x=5;
sv->score_pos.y=0;
}


void afficherscore (score *sv,SDL_Surface *screen) //blit score
{
SDL_BlitSurface(sv->imagee[0],NULL,screen,&sv->score_pos);}
/*SDL_BlitSurface(sv->image1[1],NULL,screen,SV->score_pos);
SDL_BlitSurface(sv->image1[2],NULL,screen,SV->score_pos);
SDL_BlitSurface(sv->image1[3],NULL,screen,SV->score_pos);
SDL_BlitSurface(sv->image1[4],NULL,screen,SV->score_pos);
SDL_BlitSurface(sv->image1[5],NULL,screen,SV->score_pos);*/

void freescorevie1 (score *sv)
{
SDL_FreeSurface(sv->imagee[0]);
/*SDL_FreeSurface(sv->image[0]);
SDL_FreeSurface(sv->image[0]);
SDL_FreeSurface(sv->image[0]);
SDL_FreeSurface(sv->image[0]);
SDL_FreeSurface(sv->image[0]);*/
}




