int collision_trigo(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE)
{
cercle C1,C2;
int d ;
C1.x=posP.x+P->w/2;
C1.y=posP.y+P->h/2;

C2.x=posE.x+E->w/2;
C2.y=posE.y+E->h/2;


C1.rayon=P->h/2;
C2.rayon=E->h/2;


d =sqrt((C1.x-C2.x)*(C1.x-C2.x) + (C1.y-C2.y)*(C1.y-C2.y));
   if (d > (C1.rayon + C2.rayon))

      return 0;

   else

      return 1;
}
typdef struct cercle //Pour collision Trigo
{
	int x,y ; 
	float rayon ; 
	
}cercle ; 
int col_trigo(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE); //1 = vrai si touche
