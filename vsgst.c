#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "structsv.h"

void init(score *sv,vie *v)
{
	sv->pos_sc.x = 0;
	sv->pos_sc.y = 0;
	v->pos_vie.x = 255;
	v->pos_vie.y = 0;
}

void affichage(score *sv,point *ps,vie *v,point *p)
{
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();SDL_Surface *screen;
TTF_Font *fonttexte;
fonttexte=TTF_OpenFont("BrigestScript.ttf",30);
	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
screen = SDL_SetVideoMode(1300,700,32, SDL_HWSURFACE);
char show[10];
ps->n =200;
sprintf(show,"SCORE = %d",ps->n);
sv->image = TTF_RenderText_Shaded(fonttexte,show,couleurtexte,couleur);
char affvie[10];
p->nb =3;
sprintf(affvie,"VIE = %d",p->nb);
v->image_vie = TTF_RenderText_Shaded(fonttexte, affvie,couleurtexte,couleur);
//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  
        SDL_BlitSurface(sv->image, NULL, screen, &(sv->pos_sc)); 
        SDL_BlitSurface(v->image_vie, NULL, screen, &(v->pos_vie)); 

SDL_Flip(screen);


pause();
TTF_CloseFont(fonttexte);
    TTF_Quit();

    SDL_FreeSurface(sv->image);
SDL_FreeSurface(v->image_vie);
    SDL_Quit();
}

int gestion_vie_score(score *sv,point *ps,vie *v,point *p)
{
int c;int resolu;int gvs=0;//int a;a=ps->n;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();SDL_Surface *screen;
TTF_Font *fonttexte;
fonttexte=TTF_OpenFont("BrigestScript.ttf",30);
	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
screen = SDL_SetVideoMode(1300,700,32, SDL_HWSURFACE);
//c=Collision_Bounding_Box(rec1,position_obstacle);
//resolu= resolution_enigme(enigme *e);
c=1;
resolu=1;
 if (c!=0) //famma collision
{
p->nb--;  // vie ton9os
switch(resolu)
{
case 1: //jeweb aal quiz b s7i7
{
ps->n+=100;
char show[10];
sprintf(show,"SCORE = %d",ps->n);
sv->image = TTF_RenderText_Shaded(fonttexte,show,couleurtexte,couleur);
char affvie[10];
sprintf(affvie,"VIE = %d",p->nb);
v->image_vie = TTF_RenderText_Shaded(fonttexte, affvie,couleurtexte,couleur);
//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  
        SDL_BlitSurface(sv->image, NULL, screen, &(sv->pos_sc)); 
        SDL_BlitSurface(v->image_vie, NULL, screen, &(v->pos_vie));
SDL_Flip(screen);


pause();
TTF_CloseFont(fonttexte);
    TTF_Quit();

    SDL_FreeSurface(sv->image);
SDL_FreeSurface(v->image_vie); 

break;
} 
case 0: //jeweb aal quiz bl ghalet
{
ps->n-=50;
char show[10];
sprintf(show,"SCORE = %d",ps->n);
sv->image = TTF_RenderText_Shaded(fonttexte,show,couleurtexte,couleur);
char affvie[10];
sprintf(affvie,"VIE = %d",p->nb);
v->image_vie = TTF_RenderText_Shaded(fonttexte, affvie,couleurtexte,couleur);
//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  
        SDL_BlitSurface(sv->image, NULL, screen, &(sv->pos_sc)); 
        SDL_BlitSurface(v->image_vie, NULL, screen, &(v->pos_vie));
SDL_Flip(screen);


pause();
TTF_CloseFont(fonttexte);
    TTF_Quit();

    SDL_FreeSurface(sv->image);
SDL_FreeSurface(v->image_vie);  
break;
}
}

if ((ps->n)==0)
{p->nb--;}


if((p->n)==0)
{gvs++;}
}
}

/*void fin_jeu (point *p,point *ps)
{ 
SDL_Surface *screen;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();int endgame=0;int lvl=3;ps->n=250; //pour tester
TTF_Font *fonttexte;
fonttexte=TTF_OpenFont("BrigestScript.ttf",120);

	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
	SDL_Rect pos_msg;
	SDL_Surface *image;
SDL_Surface *imagee;
	pos_msg.x = 250;
	pos_msg.y = 250;
        SDL_Rect pos_msg1;
	pos_msg1.x = 300;
	pos_msg1.y = 300;

screen = SDL_SetVideoMode(1300,700,32, SDL_HWSURFACE);
endgame=gestion_vie_score(p,ps);
if (endgame==1)
{
char show[100];
char fj[20]= "GAME OVER :(";
sprintf(show,"%s",fj);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
image =TTF_RenderText_Shaded(fonttexte,show,couleurtexte,couleur);
SDL_BlitSurface(image, NULL, screen, &pos_msg);
SDL_Flip(screen);
pause();

	TTF_CloseFont(fonttexte);
	TTF_Quit();
	SDL_FreeSurface(image);
	SDL_Quit();

}  Blit du texte 
else if (lvl=3)
{if((ps->n>=200)&&(ps->n<=350))
{
char show1[100];

char f[20]= "VICTORY :)";
sprintf(show1,"%s",f);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
imagee =TTF_RenderText_Shaded(fonttexte,show1,couleurtexte,couleur);
SDL_BlitSurface(imagee, NULL, screen, &pos_msg1);
	
SDL_Flip(screen);
pause();

	
}
}

}*/
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
