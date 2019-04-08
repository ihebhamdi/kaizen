#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "menu.h"


void initialiser(menu *m, settings *set)
{

m->imagefond=IMG_Load("menukaizen.png");
(m->positiondufond).x=50;
(m->positiondufond).y=0;
(m->positiondufond).w=imagefond->w;
(m->positiondufond).h=imagefond->h;

m->bouttonp=IMG_Load("p.png");
(m->positionbouttonp).x=90;
(m->positionbouttonp).y=0;
(m->positionbouttonp).w=bouttonp->w;
(m->positionbouttonp).h=bouttonp->h;

m->bouttons=IMG_Load("s.png");
(m->positionbouttons).x=90;
(m->positionbouttons).y=0;
(m->positionbouttons).w=bouttons->w;
(m->positionbouttons).h=bouttons->h;

m->bouttonq=IMG_Load("q.png");
(m->positionbouttonq).x=90;
(m->positionbouttonq).y=0;
(m->positionbouttonq).w=bouttonq->w;
(m->positionbouttonq).h=bouttonq->h;

set->bouttonsound=IMG_Load("sound.png");
(m->positionbsound).x=90;
(m->positionbsound).y=0;
(m->positionbsound).w=bouttonsound->w;
(m->positionbsound).h=bouttonsound->h;

set->bouttonbrightness=IMG_Load("brightness.png");
(set->positionbbrightness).x=90;
(set->positionbbrightness).y=0;
(set->positionbbrightness).w=bouttonbrightness->w;
(set->positionbbrightness).h=bouttonbrightness->h;

set->bouttoncredtis=IMG_Load("credits.png");
(set->positionbcredtis).x=90;
(set->positionbcredtis).y=0;
(set->positionbcredtis).w=bouttoncredtis->w;
(set->positionbcredtis).h=bouttoncredtis->h;

}
void affichage(menu *m, settings *set)
{
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
while (menu)
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
menu = 0;
break ; 
case SDL_MOUSEMOTION:
if(74<event.motion.x&&event.motion.x<304)
{if(448<event.motion.y&&event.motion.y<506)
{
//update
m->bouttonp=IMG_Load("p1.png");
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);
}
else if(518<event.motion.y&&event.motion.y<574)
{
//update
m->bouttons=IMG_Load("s1.png");
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);

}
else if(596<event.motion.y&&event.motion.y<652)
{
//update
m->bouttonq=IMG_Load("q1.png");
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);

}}

  
break;
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
		{if(74<event.button.x&&event.button.x<304)
{if(596<event.motion.y&&event.motion.y<652)
{
menu=0;
}
if(596<event.motion.y&&event.motion.y<652)
{
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(set->bouttonsound,&m->positiondufond,ecran,&set->positionbsound);
SDL_BlitSurface(set->bouttonbrightness,&m->positiondufond,ecran,&set->positionbbrightness);
SDL_BlitSurface(set->bouttoncredits,&m->positiondufond,ecran,&set->positionbcredtis);
}
}
break;
}
SDL_Flip(ecran);
}
}
SDL_FreeSurface(set->bouttoncredits);
SDL_FreeSurface(set->bouttonbrightness);
SDL_FreeSurface(set->bouttonsound);
SDL_FreeSurface(m->bouttonp);
SDL_FreeSurface(m->bouttons);
SDL_FreeSurface(m->bouttonq);
SDL_FreeSurface(m->imagefond);
}


