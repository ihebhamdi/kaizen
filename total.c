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
    #define height 1200
    #define width 700
void jeu(SDL_Surface *screen)
{
int lvl=0;
int continuer=1;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(height, width, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
SDL_Event event;
SDL_Surface* bg=NULL;
bg=IMG_Load("enigme/start.PNG");
while (continuer==1)
{SDL_BlitSurface(bg,NULL,screen,NULL); 
 SDL_PollEvent(&event);
 switch(event.type)
 {
  case SDL_QUIT:
   continuer = 0;
  break;
case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

 				case SDLK_ESCAPE:
		    		continuer=0 ;
					break ;
                              case SDLK_p:
		    		lvl=1 ;
					break ;

           }
break ;
}


if(lvl==1){
lvl=lvl1(screen);
}
if(lvl==2)
{
lvl=lvl2(screen);
}
if(lvl==3)
{
lvl=lvl3(screen);
}
SDL_Flip (screen);
}
SDL_Quit();

}
