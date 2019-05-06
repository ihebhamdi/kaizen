#include"game.h"

void Game_Select_Scene(int* sc)
{
(*sc)++;
}

void Game_Load_Scene(Game* G)
{ 
fprintf(stderr,"chargement de la scene \n");
charge_background(G->sc,&(G->back1));
charge_background(G->sc,&(G->back2));

}

void Game_DisplayGame(Game* G,SDL_Surface *ecran)
{
SDL_Rect pos1={0,0};
SDL_Rect pos2={405,0};
SDL_Rect posr1;
SDL_Rect posr2;
G->cam1.camera.w=395;
G->cam1.camera.h=600;
G->cam2.camera.w=395;
G->cam2.camera.h=600;
poscamera(&(G->cam1),G->p1.position ,395,600);
poscamera(&(G->cam2),G->p2.position ,395,600);

SDL_Rect posrD;

posrD.x=(G->d.pos.x)-(G->cam1.camera.x);
posrD.y=(G->d.pos.y)-(G->cam1.camera.y);


affiche_background(&(G->back1),&pos1,ecran,&(G->cam1.camera));
affiche_background(&(G->back2),&pos2,ecran,&(G->cam2.camera));
posr1.x=(G->p1.position.x)-(G->cam1.camera.x);
posr1.y=(G->p1.position.y)-(G->cam1.camera.y);
posr2.x=(G->p2.position.x)-(G->cam2.camera.x)+400;
posr2.y=(G->p2.position.y)-(G->cam2.camera.y);
if (posr1.x>=345)
{posr1.x=345;}
if (posr1.x<=0)
{posr1.x=0;}
if (posr1.y>=550)
{posr1.y=550;}
if (posr1.y<=0)
if (posr2.x>=550)
{posr2.x=550;}
if (posr2.x<=405)
{posr2.x=405;}
if (posr2.y>=550)
{posr2.y=550;}
if (posr2.y<=0)
{posr2.y=0;}
displayprince(&(G->p1),&posr1,ecran);
displayprince(&(G->p2),&posr2,ecran);

//display coins
//affichercoin (ecran,2,G->c1);


//updatedragon(&(G->d) ,ecran, G->p1.position);
//blit(&(G->d),&posrD,ecran);

//int coll=0;
//deplacer_dragon( &(G->d) ,ecran,G->p1.position); 




 SDL_Flip(ecran);   
}

void Game_Init_Scene(Game* G)
{ SDL_Rect pos1={0,0};
SDL_Rect pos2={400,0};
SDL_Rect pos[2]={{200,0},{300,300}};


G->sc=0;
G->GameOver=0;
init_background(&(G->back1));
init_background(&(G->back2));
initprince(&(G->p1), &pos1);
initprince(&(G->p2),&pos2);


inittableaucoin(G->c1,2,pos);
initEnnemi(&(G->d));
}


void Game_PlayGame(Game* G,SDL_Surface *ecran)
{
int key[322]={0};
Game_DisplayGame(G,ecran);
while(G->GameOver==0)
     {  
        Game_Input(key) ;
        Game_UpdateGame(G, key);
      Game_DisplayGame(G,ecran);
SDL_Delay(16);
      }
}




void Game_NewGame(Game* G,SDL_Surface *ecran)
{

printf ("init secene");
Game_Init_Scene(G);
do
{
printf ("Select secene");
Game_Select_Scene(&(G->sc));

printf ("load scene");
Game_Load_Scene(G);

printf ("play");
Game_PlayGame(G,ecran);
}
while (G->GameOver==0);
Game_FreeGame(G);
}



void Game_FreeGame(Game* G)
{ //int i;
fprintf(stderr,"free game \n");
free_background(&(G->back1));
free_background(&(G->back2));
freeprince(&(G->p1));
freeprince(&(G->p2));
//free coins
freecoin(G->c1,2);

//libere (&(G->d));


}

void Game_Input(int key[])
{
   SDL_Event event;
      SDL_EnableKeyRepeat(5,5);

	SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_KEYDOWN:
			key[event.key.keysym.sym]=1;
			break;
		case SDL_KEYUP:
			key[event.key.keysym.sym]=0;
			break;
		default:
			break;
		}
	
}


void Game_UpdateGame(Game* G,int key[])
{ int test=0,CC;

int Res;

   G->p1.moving=0;
G->p2.moving=0;
G->p2.direction=0;
G->p1.direction=0;
   
if (key[SDLK_UP]==1)
     { 
        G->p1.moving=1;
         G->p1.direction=1;
	fprintf(stderr," UP \n");
       marcheavant(&(G->p1));
      }
else if (key[SDLK_DOWN]==1)
     { 
       G->p1.moving=1;
       G->p1.direction=2;
       fprintf(stderr," DOWN \n");
       marcheariere(&(G->p1));
      }
else if (key[SDLK_RIGHT]==1)
     { 
        G->p1.moving=1;
         G->p1.direction=3;
        fprintf(stderr," right \n");
        marchedroite(&(G->p1));
      }
else if (key[SDLK_LEFT]==1)
     { 
          G->p1.moving=1;
           G->p1.direction=4;
         fprintf(stderr," left \n");
         marchegauche(&(G->p1));
      }
else if (key[SDLK_z]==1)
     {   
         G->p2.moving=1;
          G->p2.direction=1;
         fprintf(stderr," UP \n");
         marcheavant(&(G->p2));
      }
else if (key[SDLK_q]==1)
     { 
       G->p2.moving=1;
        G->p2.direction=4;
       fprintf(stderr,"left \n");
       marchegauche(&(G->p2));
      }
else if (key[SDLK_d]==1)
       
     { 
        G->p2.moving=1;
       G->p2.direction=3;
       fprintf(stderr," right \n");
      marchedroite(&(G->p2));
          
      }
else if (key[SDLK_s]==1)
     { 
          G->p2.moving=1;
          G->p2.direction=2;
         fprintf(stderr," down \n");
         marcheariere(&(G->p2));  
      }



//CC=testcollision(G->p1.position,G->c1,2);

/*// CC=CollisionCoin
 for(i=0;i<2;i++){  
        if (G->c1[i].etat==1)
       { // Update scene
            SDL_FreeSurface(G->c1[i].image);
          // update temps + score
       }
}*/
/*
//poscamera(&cam,G->p1.position,width,height);
//test=Test_Enigma(temps t,score s);
   if (test==0)
      {
         //afficher_GO afficher Menu
       }
   else 
       { // Enigme(....)
          if (Res ==1)
            {
              // sceneOver(....)
            }
           else { 
                 //(afficher_GO afficher Menu
                }
          }*/
}


