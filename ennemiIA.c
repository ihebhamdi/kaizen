#include"ennemiAI.h"
void initEnnemi(ennemi*e)
{
	e->pos.x = 7000;
	e->pos.y = 100;
	e->pos.w = WIDTH;
	e->pos.h = HEIGHT;
	
e->etat=0;


e->image[0]= IMG_Load("G5.png");
e->image[1]= IMG_Load("G4.png");
e->image[2] =IMG_Load("G3.png");
e->image[3]= IMG_Load("G5.png");
e->image[4]= IMG_Load("G3.png");

e->image[5]= IMG_Load("D4.png");
e->image[6] =IMG_Load("D5.png");
e->image[7]= IMG_Load("D3.png");
e->image[8]= IMG_Load("D4.png");
e->image[9]= IMG_Load("attaque.png");

}

void iADirection( SDL_Rect *ennemiPosition, SDL_Rect personnagePosition,ennemi*e)

{
    if (ennemiPosition->x < personnagePosition.x)
    {
         ennemiPosition->x= ennemiPosition->x+5;
	if(e->imag>=8||e->imag<=5)
	{e->imag=5;}e->imag++;
    }
    else if (ennemiPosition->x > personnagePosition.x){
if(e->imag>=3){e->imag=0;}e->imag++;
         ennemiPosition->x-=5;}

}

void deplacer_ennemi( ennemi*e ,SDL_Surface*ecran, SDL_Rect pos,int *collision)
{
int nombreRand =0  ;
SDL_Rect  diff  ;
int a=0 ;
diff.x= e->pos.x -pos.x  ;
diff.y=0;
a=abs(diff.x) ;
srand(time(NULL)); 
nombreRand=(rand() % 2) ;

if(abs(diff.x)>=(WIDTH/2)+25)
{

e->pos.x=0;

}

if ( a>50 )
{

    switch (nombreRand){
case 1:

if(e->imag>=4||e->imag<=0){e->imag=0;}e->imag++;

                       e->pos.x-=10;

            
      break ;
case 0 :if(e->imag>=8||e->imag<=5){e->imag=5;}e->imag++;

                    e->pos.x+=10;

              
      break ;

}
else 

{
iADirection( &e->pos, pos,e);
(*collision)=Collision( e->pos,pos);
if ((*collision)==1){
e->imag=9;
}
}
}



void blit(ennemi*e,SDL_Rect *pos, SDL_Surface* ecran)
{
	SDL_BlitSurface(e->image[e->imag],NULL, ecran, pos);
}


int Collision( SDL_Rect box1,SDL_Rect box2)
{

   if((box2.x >= box1.x + box1.w)      || (box2.x+ box2.w <= box1.x) || (box2.y >= box1.y + box1.h) || (box2.y + box2.h <= box1.y)) 

          return 0;

   else

          return 1;

}










