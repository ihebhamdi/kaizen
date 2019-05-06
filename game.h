#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


#include <SDL/SDL.h>
#include "background.h"
#include "prince.h"

#include"camera.h"
#include"ennemi.h"
 
typedef struct game
{
prince p1;
prince p2;

//coin c2[10];
int sc;
Background back1;
Background back2;
Camera cam1,cam2;
int coll;
//int score;
//int time;
ennemi e;
int GameOver;
}Game;
//Camera cam;

void Game_Init_Scene(Game* G);
void Game_NewGame(Game* G,SDL_Surface *ecran);
void Game_Load_Scene(Game* G);
void Game_FreeGame(Game* G);
void Game_DisplayGame(Game* G,SDL_Surface *ecran);
void Game_PlayGame(Game* G,SDL_Surface *ecran);
void Game_Input(int key[]);
void Game_Select_Scene(int * sc);
void Game_UpdateGame(Game* G,int key[]);

#endif
