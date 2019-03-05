#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "menu.h"

char pause ;
int menu=1;
int now=0;
int ex=0;
int pfps=3;
int dt=0;
float pfpss=0;
SDL_Surface *ecran=NULL;
SDL_Surface *imagefond=NULL;
SDL_Surface *bouttonp = NULL;
SDL_Surface *bouttons = NULL;
SDL_Surface *bouttonq = NULL;
SDL_Event event={0};

SDL_Rect positiondufond ;
SDL_Rect positionbouttonp;
SDL_Rect positionbouttons;
SDL_Rect positionbouttonq;

void initialiser()
{

imagefond=IMG_Load("menukaizen.png");
positiondufond.x=50;
positiondufond.y=0;
positiondufond.w=imagefond->w;
positiondufond.h=imagefond->h;

bouttonp=IMG_Load("p.png");
positionbouttonp.x=90;
positionbouttonp.y=0;
positionbouttonp.w=bouttonp->w;
positionbouttonp.h=bouttonp->h;

bouttons=IMG_Load("s.png");
positionbouttons.x=90;
positionbouttons.y=0;
positionbouttons.w=bouttons->w;
positionbouttons.h=bouttons->h;

bouttonq=IMG_Load("q.png");
positionbouttonq.x=90;
positionbouttonq.y=0;
positionbouttonq.w=bouttonq->w;
positionbouttonq.h=bouttonq->h;

}
void affichage()
{
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
while(menu)
{


now=SDL_GetTicks();
dt=now-ex;
if(dt>=pfps)
{


SDL_PollEvent(&event);
switch(event.type)
{case SDL_QUIT:
{
    menu=0;
  }
break;
case SDL_MOUSEMOTION:
if(74<event.motion.x&&event.motion.x<304)
{if(448<event.motion.y&&event.motion.y<506)
{
//update
SDL_BlitSurface(imagefond,NULL,ecran,&positiondufond);
SDL_BlitSurface(bouttonp,&positiondufond,ecran,&positionbouttonp);
SDL_BlitSurface(bouttons,&positiondufond,ecran,&positionbouttons);
SDL_BlitSurface(bouttonq,&positiondufond,ecran,&positionbouttonq);
}
else if(518<event.motion.y&&event.motion.y<574)
{
//update
SDL_BlitSurface(imagefond,NULL,ecran,&positiondufond);
SDL_BlitSurface(bouttonp,&positiondufond,ecran,&positionbouttonp);
SDL_BlitSurface(bouttons,&positiondufond,ecran,&positionbouttons);
SDL_BlitSurface(bouttonq,&positiondufond,ecran,&positionbouttonq);

}
else if(596<event.motion.y&&event.motion.y<652)
{
//update
SDL_BlitSurface(imagefond,NULL,ecran,&positiondufond);
SDL_BlitSurface(bouttonp,&positiondufond,ecran,&positionbouttonp);
SDL_BlitSurface(bouttons,&positiondufond,ecran,&positionbouttons);
SDL_BlitSurface(bouttonq,&positiondufond,ecran,&positionbouttonq);

}}
else {
//update
SDL_BlitSurface(imagefond,NULL,ecran,&positiondufond);
SDL_BlitSurface(bouttonp,&positiondufond,ecran,&positionbouttonp);
SDL_BlitSurface(bouttons,&positiondufond,ecran,&positionbouttons);
SDL_BlitSurface(bouttonq,&positiondufond,ecran,&positionbouttonq);

}
  
break;
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
		{if(74<event.button.x&&event.button.x<304)
{if(596<event.motion.y&&event.motion.y<652)
{
menu=0;
}
}
}
break;
}
SDL_Flip(ecran);
ex=now;
}
else 
 SDL_Delay(pfps-dt);
}
}
void update()
{
SDL_Flip(ecran);
SDL_FreeSurface(bouttonp);
SDL_FreeSurface(bouttons);
SDL_FreeSurface(bouttonq);
SDL_FreeSurface(imagefond);
pause=getchar();
}


