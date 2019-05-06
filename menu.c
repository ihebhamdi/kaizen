#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "menufct.h"




int main(void) {
	int running = 0;
	int settingsLOOP = 0;
	int playLOOP = 0;
	int PreMenu1LOOP = 1;
	int PreMenu2LOOP = 1;
	int gameloop1 = 1;
	int ControlesLOOP = 0;
	int State = 4;
	int ETAT ;
	int frame3 = 0;
	const int SCREEN_HEIGHT = 720;
	const int SCREEN_WIDTH = 1240;



	inside_rectStruct inrect;
	init_inrect(&inrect);

	FPS FPS_Reg;
	init_FPSr(&FPS_Reg);


	SDL_Event event;
//	Settings And Main Menu Buttons
	SDL_Surface *Screen = NULL;
	SDL_Surface *BackGround = NULL;
	SDL_Surface *Title = NULL;
	SDL_Surface *NewGame = NULL;
	SDL_Surface *Settings = NULL;
	SDL_Surface *Exit = NULL;
	SDL_Surface *NewGameHL = NULL;
	SDL_Surface *SettingsHL = NULL;
	SDL_Surface *ExitHL = NULL;
	SDL_Surface *Volume = NULL;
	SDL_Surface *VolumeHL = NULL;
	SDL_Surface *VolHigh = NULL;
	SDL_Surface *VolHighHL = NULL;
	SDL_Surface *VolLow = NULL;
	SDL_Surface *VolLowHL = NULL;

//	Premenu Animation  1 and 2 and 3
	/*SDL_Surface *PreMenu1[15];
	SDL_Surface *PreMenu2[15];
	SDL_Surface *PreMenu3 ;
	SDL_Rect clip3[20];*/



// Rects for The mouse Option
	SDL_Rect NewGame_rect = {480, 110, 145, 300};
	SDL_Rect Settings_rect = {480, 280, 145, 300};
	SDL_Rect Exit_rect = {480, 485, 145, 300};

//Levels
	/*SDL_Surface *Level0_1 = NULL;
	Level0_1 = IMG_Load("menukaizen.png");*/


// Music Loading
	Mix_Music *Intro = NULL;
	if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
		return 0;
	}
	Intro = Mix_LoadMUS("intro.wav");

	Mix_PlayMusic( Intro, -1 );

	SDL_Init(SDL_INIT_VIDEO);
	const SDL_VideoInfo *pinfo = SDL_GetVideoInfo();
	int bpp = pinfo->vfmt->BitsPerPixel;



	//MENU BUTTONS
	BackGround = IMG_Load("menukaizen.png");
	NewGame = IMG_Load("p.png");
	Settings = IMG_Load("s.png");
	Exit = IMG_Load("q.png");
	NewGameHL = IMG_Load("p1.png");
	SettingsHL = IMG_Load("s1.png");
	ExitHL = IMG_Load("q1.png");

	//PRE MENU PICTURES ANIMATION
	/*PreMenu1[0] = IMG_Load("MENUart/Premenu/1MENU065.png");
	PreMenu1[1] = IMG_Load("MENUart/Premenu/2MENU065.png");
	PreMenu1[2] = IMG_Load("MENUart/Premenu/3MENU065.png");
	PreMenu1[3] = IMG_Load("MENUart/Premenu/4MENU065.png");
	PreMenu1[4] = IMG_Load("MENUart/Premenu/5MENU065.png");
	PreMenu1[5] = IMG_Load("MENUart/Premenu/6MENU065.png");
	PreMenu1[6] = IMG_Load("MENUart/Premenu/7MENU065.png");
	PreMenu1[7] = IMG_Load("MENUart/Premenu/8MENU065.png");
	PreMenu1[8] = IMG_Load("MENUart/Premenu/9MENU065.png");
	PreMenu1[9] = IMG_Load("MENUart/Premenu/10MENU065.png");
	PreMenu1[10] = IMG_Load("MENUart/Premenu/11MENU065.png");
	PreMenu1[11] = IMG_Load("MENUart/Premenu/12MENU065.png");
	PreMenu1[12] = IMG_Load("MENUart/Premenu/13MENU065.png");
	PreMenu1[13] = IMG_Load("MENUart/Premenu/14MENU065.png");
	PreMenu1[14] = IMG_Load("MENUart/Premenu/15MENU065.png");

	PreMenu2[0] = IMG_Load("MENUart/Premenu/16MENU065.png");
	PreMenu2[1] = IMG_Load("MENUart/Premenu/17MENU065.png");
	PreMenu2[2] = IMG_Load("MENUart/Premenu/18MENU065.png");
	PreMenu2[3] = IMG_Load("MENUart/Premenu/19MENU065.png");
	PreMenu2[4] = IMG_Load("MENUart/Premenu/20MENU065.png");
	PreMenu2[5] = IMG_Load("MENUart/Premenu/21MENU065.png");
	PreMenu2[6] = IMG_Load("MENUart/Premenu/22MENU065.png");
	PreMenu2[7] = IMG_Load("MENUart/Premenu/23MENU065.png");
	PreMenu2[8] = IMG_Load("MENUart/Premenu/24MENU065.png");
	PreMenu2[9] = IMG_Load("MENUart/Premenu/25MENU065.png");
	PreMenu2[10] = IMG_Load("MENUart/Premenu/26MENU065.png");
	PreMenu2[11] = IMG_Load("MENUart/Premenu/27MENU065.png");
	PreMenu2[12] = IMG_Load("MENUart/Premenu/28MENU065.png");
	PreMenu2[13] = IMG_Load("MENUart/Premenu/29MENU065.png");
	PreMenu2[14] = IMG_Load("MENUart/Premenu/30MENU065.png");*/


	/*PreMenu3 = IMG_Load(".png");
	if (PreMenu3 == NULL)
		printf("PST u \n");*/

	SDL_Rect Pos_Any_Button = {(SCREEN_WIDTH / 2) - 390, (SCREEN_HEIGHT / 2) + 100, 215 , 693};

	// Setting up the Scree
	Screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, bpp, SDL_HWSURFACE | SDL_DOUBLEBUF );
	SDL_WM_SetCaption("KAIZEN", NULL);


	//play_animation(PreMenu1, 14, 10, Screen);


	//set_rects(clip3);					//ANY KEY ANIM RECT
	/*while (gameloop1) {					//Game Loop 1 is the big loop
		while (PreMenu1LOOP) 			//Events
		{

			SDL_Flip(Screen);
			SDL_BlitSurface(PreMenu3, &clip3[frame3], Screen, &Pos_Any_Button);
			SDL_Flip(Screen);
			SDL_Delay(15);
			frame3++;
			if (frame3 == 20)
				frame3 = 0;


			while (SDL_PollEvent(&event))
			{
				switch (event.type) {
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					PreMenu2LOOP = 1; PreMenu1LOOP = 0;
					break;

				}
			}
		}*/

		while (PreMenu2LOOP)
		{
			//play_animation(PreMenu2, 14, 20, Screen);
			running = 1; PreMenu2LOOP = 0;
		}

		while (running) {					//game loop
			//FPS Regulation
			FPS_Reg.now = SDL_GetTicks();
			FPS_Reg.dt = FPS_Reg.now - FPS_Reg.ex ;
			if (FPS_Reg.dt > FPS_Reg.p_fps)
			{

				//Surface Blitting aka Menu Init
				SDL_BlitSurface(BackGround, NULL, Screen, NULL);
				SDL_BlitSurface(NewGame, NULL, Screen, NULL);
				SDL_BlitSurface(Settings, NULL, Screen, NULL);
				SDL_BlitSurface(Exit, NULL, Screen, NULL);

				// Highlights
				if ((State == 3) || (inrect.N == 1))
					SDL_BlitSurface(NewGameHL, NULL, Screen, NULL);


				if ((State == 2 ) || (inrect.S == 1))
					SDL_BlitSurface(SettingsHL, NULL, Screen, NULL);


				if ((State == 1) || (inrect.E == 1))
					SDL_BlitSurface(ExitHL, NULL, Screen, NULL);


				SDL_PollEvent(&event);

				switch (event.type) {
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_DOWN)

					{
						if (State <= 0) {
							State = 4;
						}
						State--;
						SDL_Delay(100);
					}
					if (event.key.keysym.sym == SDLK_UP)

					{
						if (State >= 4) {
							State = 0;
						}
						State++;
						SDL_Delay(100);
					}
					if (event.key.keysym.sym == SDLK_RETURN)

					{	if (State == 1)//Quit
						{
							//Mix_PlayChannel( -1, woosh, 0 );
							running = 0;
						}
						if (State == 2)//Settings
						{
							//Mix_PlayChannel( -1, woosh, 0 );
							settingsLOOP = 1;
							running = 0;
						}
						if (State == 3)//Play
						{
							//Mix_PlayChannel( -1, woosh, 0 );
							playLOOP = 1;
							running = 0;
						}
					}
				}//Switch

				//	SDL_FillRect(BackGround, &NewGame_rect, SDL_MapRGB(BackGround->format, 255, 255, 255)); TEST RECT
	
				FPS_Reg.ex = FPS_Reg.now;
			
			}
			else {
				SDL_Delay(FPS_Reg.p_fps - FPS_Reg.dt);}



	
	SDL_Flip(Screen);
pause();
SDL_FreeSurface(BackGround);
	SDL_FreeSurface(NewGame);
	SDL_FreeSurface(Settings);
	SDL_FreeSurface(Exit);
	SDL_FreeSurface(NewGameHL);
	SDL_FreeSurface(SettingsHL);
	SDL_FreeSurface(ExitHL);
		}
Mix_FreeMusic( Intro );
Mix_CloseAudio();
SDL_QUIT;
}
//gameloop					

//SETTINGS BUTTONS


		/*Volume = IMG_Load("MENUart/Settings_pngs/Volume.png");
		VolumeHL = IMG_Load("MENUart/Settings_pngs/VolumeHL.png");

		VolHigh = IMG_Load("MENUart/Settings_pngs/High.png");
		VolHighHL = IMG_Load("MENUart/Settings_pngs/HighHL.png");


		VolMed = IMG_Load("MENUart/Settings_pngs/Med.png");
		VolMedHL = IMG_Load("MENUart/Settings_pngs/MedHL.png");

		VolLow = IMG_Load("MENUart/Settings_pngs/Low.png");
		VolLowHL = IMG_Load("MENUart/Settings_pngs/LowHL.png");


		SDL_Flip(Screen);
		ETAT = 7;

		while (settingsLOOP != 0) {
			SDL_BlitSurface(BackGround, NULL, Screen, NULL);

			if (ETAT == 3)
				SDL_BlitSurface(VolumeHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(Volume, NULL, Screen , NULL);

			if (ETAT == 2)
				SDL_BlitSurface(VolLowHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(VolLow, NULL, Screen , NULL);

			if (ETAT == 1)
				SDL_BlitSurface(VolHighHL, NULL, Screen , NULL);
			else
				SDL_BlitSurface(VolHigh, NULL, Screen , NULL);


			SDL_PollEvent(&event);

			switch (event.type) {
			case SDL_QUIT:
				settingsLOOP = 0;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_RETURN) {

					if (ETAT == 3)
						Mix_VolumeMusic(20);
					if (ETAT == 2)
						Mix_VolumeMusic(70);
					if (ETAT == 1)
						Mix_VolumeMusic(128);
				}
			}
			SDL_Flip(Screen);
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