
#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "enigme.h"
#include<math.h>
#include<time.h>


int somme(int i)
{
	int s=i;
	if (i!=0)
	{
	while(i>0)
	{
		i--;
		s=s+i;
	}
}
	else
	{
		s=0;
	}
	return s;
}

int factorielle(int nb)
{
	int facto = 1;
	if (nb != 0)
	{
		facto= nb;
		do {
			nb = nb - 1;
			facto= facto * nb;
		}
		while (nb > 1);
	}
	else
	{
		facto= 1;
	}
	return facto;
}

void affichage(int val)
{
	SDL_Surface *question;
	SDL_Surface *re1;
	SDL_Surface *re2;
	SDL_Rect posquestion;
	SDL_Rect posrep1;
	SDL_Rect posrep2;
	SDL_Init(SDL_INIT_VIDEO);	
	TTF_Init();
	TTF_Font *fonttexte;
	fonttexte=TTF_OpenFont("BrigestScript.ttf",30);
	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
	SDL_Surface *screen;
	screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

char answp[50];
srand(time(NULL));
val=0;
val = rand()%2;

        // val = 1 : enigme polynome | val = 0 :enigme facto
	posquestion.x=150;
	posquestion.y=0;
	posrep1.x=100;
	posrep1.y=150;
	posrep2.x=400;
	posrep2.y=150;

	if(val == 1)
{
	int idkwtf;
	int a;
	srand(time(NULL));
	a = rand()%20;
	idkwtf=somme(a);

	if(a== 0)
{
	char q_s[100];
sprintf(q_s,"LA SOMME DE SUITE DE  0 VERS %d ",a);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
question=TTF_RenderText_Shaded(fonttexte,q_s,couleurtexte,couleur);
		re1=TTF_RenderText_Shaded(fonttexte,"0",couleurtexte,couleur);
		re2=TTF_RenderText_Shaded(fonttexte,"-1",couleurtexte,couleur);
				/* Blit du texte */
SDL_BlitSurface(question, NULL,screen,&posquestion); 
	SDL_BlitSurface(re1, NULL,screen,&posrep1); 
	SDL_BlitSurface(re2, NULL,screen,&posrep2); 
SDL_Flip(screen);
pause();
TTF_CloseFont(fonttexte);
	TTF_Quit(); 
SDL_FreeSurface(question);
SDL_FreeSurface(re1);  
SDL_FreeSurface(re2); 
SDL_Quit ();

}
else if(a>0)
{
	SDL_Surface *re11;
	SDL_Surface *re22;
int v=0;
srand(time(NULL));
v =rand()%10;
char sum[100];
char aws[100];
char q_s[100];
sprintf(q_s,"LA SOMME DE SUITE DE 0 VERS %d ",a);
sprintf(sum,"%d",idkwtf);
sprintf(aws,"%d",v);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
question=TTF_RenderText_Shaded(fonttexte,q_s,couleurtexte,couleur);
        re11=TTF_RenderText_Shaded(fonttexte,sum,couleurtexte,couleur);
        re22=TTF_RenderText_Shaded(fonttexte,aws,couleurtexte,couleur);
        posrep1.x+=250;
        posrep2.x-=300;
                /* Blit du texte */
SDL_BlitSurface(question, NULL,screen,&posquestion);
    SDL_BlitSurface(re11, NULL,screen,&posrep1);
    SDL_BlitSurface(re22, NULL,screen,&posrep2);
SDL_Flip(screen);
pause();
TTF_CloseFont(fonttexte);
    TTF_Quit();
SDL_FreeSurface(question);
SDL_FreeSurface(re11); 
SDL_FreeSurface(re22);
SDL_Quit ();

}

}


	else if(val == 0)
{ 
	int nb,n;
	nb=rand()%10;
	n=factorielle(nb);
	if((n == 0)||(n == 1))
{
char q_f[100];
sprintf(q_f,"calculer factoriel %d ! = ?",nb ); //
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
question=TTF_RenderText_Shaded(fonttexte,q_f,couleurtexte,couleur);//
		re1=TTF_RenderText_Shaded(fonttexte,"A--0",couleurtexte,couleur);//
		re2=TTF_RenderText_Shaded(fonttexte,"B--1",couleurtexte,couleur);//
				  
SDL_BlitSurface(question, NULL,screen,&posquestion); 
	SDL_BlitSurface(re1, NULL,screen,&posrep1); 
	SDL_BlitSurface(re2, NULL,screen,&posrep2);
SDL_Flip(screen);
pause();
TTF_CloseFont(fonttexte);
	TTF_Quit();
SDL_FreeSurface(question);
SDL_FreeSurface(re1);
SDL_FreeSurface(re2);
SDL_Quit ();
}
	 if(n > 1)


{
char answf[50];
char wrongans[50]; 
srand(time(NULL));
int varalea=0;
varalea =rand()%100;
char q_f[100];
sprintf(q_f,"calculer factoriel %d ! = ?",nb);
sprintf(answf,"%d",n);
	sprintf(wrongans,"%d",varalea);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
question=TTF_RenderText_Shaded(fonttexte,q_f,couleurtexte,couleur);//
		re1=TTF_RenderText_Shaded(fonttexte,answf,couleurtexte,couleur);//
		re2=TTF_RenderText_Shaded(fonttexte,wrongans,couleurtexte,couleur);//
				 
SDL_BlitSurface(question, NULL,screen,&posquestion); 
	SDL_BlitSurface(re1, NULL,screen,&posrep1); 
	SDL_BlitSurface(re2, NULL,screen,&posrep2);
SDL_Flip(screen);
pause();
TTF_CloseFont(fonttexte);
	TTF_Quit();
SDL_FreeSurface(question);
SDL_FreeSurface(re1);
SDL_FreeSurface(re2);
SDL_Quit ();
}
}
}
/************************************************************************/
void resolu()
{
    SDL_Surface *GG;
    SDL_Surface *NAHA;
    SDL_Rect rzlt;

    SDL_Init(SDL_INIT_VIDEO);   
    TTF_Init();
    TTF_Font *fonttexte;
    fonttexte=TTF_OpenFont("BrigestScript.ttf",30);
    SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
        rzlt.x=0;
    rzlt.y=0;
    rzlt.h=705;
    rzlt.w=1300;

GG=TTF_RenderText_Shaded(fonttexte,"NICE",couleurtexte,couleur);
NAHA=TTF_RenderText_Shaded(fonttexte,"PICK WISELY NEXT CHANCE U GET",couleurtexte,couleur);
    int reponse=-1;
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
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
{
if(100<event.button.x&&event.button.x<200)
{if(250<event.button.y&&event.button.y<350)
{
reponse=1;
}
}
if(355<event.button.x&&event.button.x<455)
{if(250<event.button.y&&event.button.y<350)
{
reponse=0;
}
}
}
break;
}
}
if(val == 0)
{

if(reponse==0){
    SDL_BlitSurface(GG, NULL,screen,&rzlt);
}
if(reponse==1){
    SDL_BlitSurface(NAHA, NULL,screen,&rzlt);
}
}
if(val == 1){

if(reponse==0){
    SDL_BlitSurface(NAHA, NULL,screen,&rzlt);
}
if(reponse==1){
    SDL_BlitSurface(GG, NULL,screen,&rzlt);
}
}
SDL_Flip(screen);
pause();
TTF_CloseFont(fonttexte);
    TTF_Quit();
SDL_FreeSurface(GG);
SDL_FreeSurface(NAHA);
SDL_Quit();
}
/******************************************************************************/
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

