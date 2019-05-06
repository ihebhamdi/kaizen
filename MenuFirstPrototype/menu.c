#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

int update_menu()
{
	int mise_ajr=0,mise_sets=0;
	int menuu=1;
	SDL_Event event={0};
while (menuu)
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
menuu = 0;
break ; 
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_UP)
{
//update
	mise_ajr=1;
if(event.key.keysym.sym==SDLK_UP)
{
//update
mise_ajr=2;
}
}
else if(event.key.keysym.sym==SDLK_DOWN)
{
//update
mise_ajr=3;
}

break;
}
if(event.key.keysym.sym==SDLK_KP_ENTER)
{if (mise_ajr==3)
menuu=0;
}
if(event.key.keysym.sym==SDLK_KP_ENTER)
{if (mise_ajr==2)
{
mise_sets=4;
mise_ajr=mise_sets;
}
break;
}
}
return mise_ajr;
}
void initialiser(menu *m, settings *set)
{

m->imagefond=IMG_Load("menukaizen.png");
(m->positiondufond).x=50;
(m->positiondufond).y=0;
(m->positiondufond).w=(m->imagefond)->w;
(m->positiondufond).h=(m->imagefond)->h;

m->bouttonp=IMG_Load("p.png");
(m->positionbouttonp).x=90;
(m->positionbouttonp).y=0;
(m->positionbouttonp).w=(m->bouttonp)->w;
(m->positionbouttonp).h=(m->bouttonp)->h;

m->bouttons=IMG_Load("s.png");
(m->positionbouttons).x=90;
(m->positionbouttons).y=0;
(m->positionbouttons).w=(m->bouttons)->w;
(m->positionbouttons).h=(m->bouttons)->h;

m->bouttonq=IMG_Load("q.png");
(m->positionbouttonq).x=90;
(m->positionbouttonq).y=0;
(m->positionbouttonq).w=(m->bouttonq)->w;
(m->positionbouttonq).h=(m->bouttonq)->h;

set->bouttonsound=IMG_Load("sound.png");
(set->positionbsound).x=90;
(set->positionbsound).y=0;
(set->positionbsound).w=(set->bouttonsound)->w;
(set->positionbsound).h=(set->bouttonsound)->h;

set->bouttonbrightness=IMG_Load("brightness.png");
(set->positionbbrightness).x=90;
(set->positionbbrightness).y=0;
(set->positionbbrightness).w=(set->bouttonbrightness)->w;
(set->positionbbrightness).h=(set->bouttonbrightness)->h;

set->bouttoncredtis=IMG_Load("credits.png");
(set->positionbcredtis).x=90;
(set->positionbcredtis).y=0;
(set->positionbcredtis).w=(set->bouttoncredtis)->w;
(set->positionbcredtis).h=(set->bouttoncredtis)->h;

}
void affichage(menu *m, settings *set)
{
Mix_Music *Intro = NULL;
	if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
		//return 0;
	}
	Intro = Mix_LoadMUS("intro.wav");

	Mix_PlayMusic( Intro, -1 );
SDL_Event event={0};
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);


SDL_Flip(ecran);
pause();

SDL_FreeSurface(m->bouttonp);
SDL_FreeSurface(m->bouttons);
SDL_FreeSurface(m->bouttonq);
SDL_FreeSurface(m->imagefond);
Mix_FreeMusic( Intro );
Mix_CloseAudio();

int chngaff;
chngaff=update_menu();

if(chngaff==1)
{
//update
m->bouttonp=IMG_Load("p1.png");
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);
SDL_Flip(ecran);
SDL_FreeSurface(m->bouttonp);
SDL_FreeSurface(m->bouttons);
SDL_FreeSurface(m->bouttonq);
SDL_FreeSurface(m->imagefond);
}
else if(chngaff==2)
{
//update
m->bouttons=IMG_Load("s1.png");
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);
SDL_Flip(ecran);
SDL_FreeSurface(m->bouttonp);
SDL_FreeSurface(m->bouttons);
SDL_FreeSurface(m->bouttonq);
SDL_FreeSurface(m->imagefond);
}
else if(chngaff==3)
{
//update
m->bouttonq=IMG_Load("q1.png");
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(m->bouttonp,&m->positiondufond,ecran,&m->positionbouttonp);
SDL_BlitSurface(m->bouttons,&m->positiondufond,ecran,&m->positionbouttons);
SDL_BlitSurface(m->bouttonq,&m->positiondufond,ecran,&m->positionbouttonq);
SDL_Flip(ecran);
SDL_FreeSurface(m->bouttonp);
SDL_FreeSurface(m->bouttons);
SDL_FreeSurface(m->bouttonq);
SDL_FreeSurface(m->imagefond);
}

if(event.key.keysym.sym==SDLK_KP_ENTER)
{if (chngaff==3)
{
SDL_QUIT;
}
if(event.key.keysym.sym==SDLK_KP_ENTER)
{if (chngaff==2)
{
SDL_BlitSurface(m->imagefond,NULL,ecran,&m->positiondufond);
SDL_BlitSurface(set->bouttonsound,&m->positiondufond,ecran,&set->positionbsound);
SDL_BlitSurface(set->bouttonbrightness,&m->positiondufond,ecran,&set->positionbbrightness);
SDL_BlitSurface(set->bouttoncredtis,&m->positiondufond,ecran,&set->positionbcredtis);
SDL_Flip(ecran);
SDL_FreeSurface(set->bouttoncredtis);
SDL_FreeSurface(set->bouttonbrightness);
SDL_FreeSurface(set->bouttonsound);
}
}
}


}
void pause()
{
int continuer = 1;
SDL_Event event;
while (continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
}
}
}
