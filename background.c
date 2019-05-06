#include "background.h"




void init_background(Background *back)
{
   back->position.x=0;
   back->position.y=0;

}
void charge_background(int scene,Background *back)
{
	
    	
	back->background= IMG_Load("baaac.png");
	//back->backgroundCollision= IMG_Load("../img/Game_Map_3collision.png");
	
	
    
}
void affiche_background(Background *back,SDL_Rect *pos,SDL_Surface *ecran,SDL_Rect* camm )
{
  	SDL_BlitSurface(back->background,camm, ecran, pos);	
}
void free_background(Background *back)
{
	if(back->background!=NULL)
       { SDL_FreeSurface(back->background);}
	if(back->backgroundCollision!=NULL)
       { SDL_FreeSurface(back->backgroundCollision);}
    	
}
