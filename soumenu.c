#include<SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "sousmenu.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void displaysousmenu(int *nbmenu,SousM *SM,SDL_Surface *ecran,int *cas)
{
	if (*nbmenu==0)
	{
		if (*cas==1)
		{
    	SDL_BlitSurface(SM->menu, NULL, ecran, &(SM->pmenu));
    	SDL_BlitSurface(SM->resume, NULL,ecran,&(SM->presume));
    	SDL_BlitSurface(SM->save, NULL,ecran,&(SM->psave));
    	SDL_BlitSurface(SM->settings, NULL,ecran,&(SM->psettings));
    	SDL_BlitSurface(SM->quit, NULL,ecran,&(SM->pquit));
			
		}
		if (*cas==2)
		{
    	SDL_BlitSurface(SM->menu, NULL, ecran, &(SM->pmenu));
    	SDL_BlitSurface(SM->resume, NULL,ecran,&(SM->presume));
    	SDL_BlitSurface(SM->save, NULL,ecran,&(SM->psave));
    	SDL_BlitSurface(SM->settings, NULL,ecran,&(SM->psettings));
    	SDL_BlitSurface(SM->quit, NULL,ecran,&(SM->pquit));
		}
		if (*cas==3)
		{
    	SDL_BlitSurface(SM->menu, NULL, ecran, &(SM->pmenu));
    	SDL_BlitSurface(SM->resume, NULL,ecran,&(SM->presume));
    	SDL_BlitSurface(SM->save, NULL,ecran,&(SM->psave));
    	SDL_BlitSurface(SM->settings, NULL,ecran,&(SM->psettings));
    	SDL_BlitSurface(SM->quit, NULL,ecran,&(SM->pquit));
		}
		if (*cas==4)
		{
    	SDL_BlitSurface(SM->menu, NULL, ecran, &(SM->pmenu));
    	SDL_BlitSurface(SM->resume, NULL,ecran,&(SM->presume));
    	SDL_BlitSurface(SM->save, NULL,ecran,&(SM->psave));
    	SDL_BlitSurface(SM->settings, NULL,ecran,&(SM->psettings));
    	SDL_BlitSurface(SM->quit, NULL,ecran,&(SM->pquit));
		}
		
	}
	
	
	
}
/*--------------------------------------------------*/
void initsousmenu(SousM *SM)
{
	SM->menu=IMG_Load("menu/BG.png");
	SM->resume=IMG_Load("menu/resume.png");
	SM->save=IMG_Load("menu/save.png");
	SM->settings=IMG_Load("menu/setting.png");
	SM->quit=IMG_Load("menu/quit.png");


	SM->pmenu.x=0;
	SM->pmenu.y=0;
	SM->presume.x=200;
	SM->presume.y=100;
	SM->psave.x=200;
	SM->psave.y=SM->presume.y+150;
	SM->psettings.x=200;
	SM->psettings.y=SM->psave.y+150;
	SM->pquit.x=200;
	SM->pquit.y=SM->psettings.y+150;
	
}
/*--------------------------------------------------*/ 
/*--------------------------------------------------*/
/*--------------------------------------------------*/
int sous_menus(Kay kay,Camera cam)
{
	int jeux;
	SousM SM;
	SDL_Surface *ecran=NULL,*texte=NULL;
	   TTF_Init();

	TTF_Font *police = NULL;
	SDL_Color couleurNoire = {105, 10, 30}, couleurBlanche = {255, 255, 255};
	char softwave[300] = ""; 
    SDL_Event event; /* La variable contenant l'événement */
	Mix_Music *music;
    Mix_Chunk *son;
	SDL_Surface *rain[1];
	SDL_Rect prain;
	int anim=0;
	int i,mvupdown=0;
	int nbmenu=0; // variable pour le changement de l'affichage du menu
	int continuer = 1;
	int v=50;
	int cas;
	prain.x=0;
	prain.y=0;
	//rain[0]=IMG_Load("menu/rain1.png");
	//rain[1]=IMG_Load("menu/rain2.png");


int alea=1;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Init(SDL_INIT_VIDEO);
	if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
	    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    	}
    TTF_Init();
    if(TTF_Init() == -1)
    {
    	fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    	exit(EXIT_FAILURE);
    }
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
    	printf("%s\n",Mix_GetError() );
    }
	/*-------------------------------------------------*/  
	initsousmenu(&SM);
	music = Mix_LoadMUS("music.mp3");
    son = Mix_LoadWAV("beep.wav");
    Mix_PlayMusic(music,-1);
	ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
	/*-------------------------------------------------*/

	SDL_BlitSurface(SM.menu, NULL, ecran, &(SM.pmenu));
    //SDL_BlitSurface(texte, NULL, ecran, &(m.pcredits)); /* Blit du texte */
	SDL_BlitSurface(SM.resume, NULL,ecran,&(SM.presume));
    SDL_BlitSurface(SM.save, NULL,ecran,&(SM.psave));
    SDL_BlitSurface(SM.settings, NULL,ecran,&(SM.psettings));
    SDL_BlitSurface(SM.quit, NULL,ecran,&(SM.pquit));
	SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
    SDL_Flip(ecran);
	/*-------------------------------------------------*/
    while (continuer) 
    {
        SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
    	switch(event.type) 
    	{
    		case SDL_QUIT: 
    			continuer = 0;
    			break;
			case SDL_KEYDOWN:
    			switch (event.key.keysym.sym)
    			{
                	case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
    					continuer = 0;
    					break;
    				/*case SDLK_f:
    					ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_FULLSCREEN);
						break;*/
					case SDLK_UP:
						mvupdown--;
						if (mvupdown==-1)
						mvupdown=3;
						if (mvupdown==0)
						{
						SM.resume=IMG_Load("menu/ResumeS.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/quit.png");
						cas=1;
						}
						if (mvupdown==1)
						{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/SaveS.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/quit.png");
						cas=2;
						}
						if (mvupdown==2)
						{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/SettingsS.png");
						SM.quit=IMG_Load("menu/quit.png");
						cas=3;
						}
						if (mvupdown==3)
						{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/QuitS.png");
						cas=4;
						}
						
						break;
					case SDLK_DOWN:
						mvupdown++;
						if(mvupdown==4)
						mvupdown=0;
						if (mvupdown==0)
						{
						SM.resume=IMG_Load("menu/ResumeS.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/quit.png");
						cas=1;
						}
						if (mvupdown==1)
						{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/SaveS.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/quit.png");
						cas=2;
						}
						if (mvupdown==2)
						{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/SettingsS.png");
						SM.quit=IMG_Load("menu/quit.png");
						cas=3;
						}
						if (mvupdown==3)
						{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/QuitS.png");
						cas=4;
						}

					
						break;
				}
    		case SDL_MOUSEMOTION:
			/*----------------------Menu 1----------------*/
			if ((event.motion.x>SM.presume.x)&&(event.motion.x<SM.presume.x+SM.presume.w)&&(event.motion.y>SM.presume.y)&&(event.motion.y<SM.presume.y+SM.presume.h)&&(!nbmenu))
    				{
						SM.resume=IMG_Load("menu/ResumeS.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/quit.png");
						
						cas=1;
    				}
			if ((event.motion.x>SM.psave.x)&&(event.motion.x<SM.psave.x+SM.psave.w)&&(event.motion.y>SM.psave.y)&&(event.motion.y<SM.psave.y+SM.psave.h)&&(!nbmenu))
    				{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/SaveS.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/quit.png");
						
						cas=2;
    				}
			if ((event.motion.x>SM.psettings.x)&&(event.motion.x<SM.psettings.x+SM.psettings.w)&&(event.motion.y>SM.psettings.y)&&(event.motion.y<SM.psettings.y+SM.psettings.h)&&(!nbmenu))
    				{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/SettingsS.png");
						SM.quit=IMG_Load("menu/quit.png");
						
						cas=3;
    				}
			if ((event.motion.x>SM.pquit.x)&&(event.motion.x<SM.pquit.x+SM.pquit.w)&&(event.motion.y>SM.pquit.y)&&(event.motion.y<SM.pquit.y+SM.pquit.h)&&(!nbmenu))
    				{
						SM.resume=IMG_Load("menu/resume.png");
						SM.save=IMG_Load("menu/save.png");
						SM.settings=IMG_Load("menu/setting.png");
						SM.quit=IMG_Load("menu/QuitS.png");
						
						cas=4;
    				}
			

    		break;
    		case SDL_MOUSEBUTTONDOWN :
			/*----------------------Menu 1----------------*/
			if ((event.motion.x>SM.presume.x)&&(event.motion.x<SM.presume.x+SM.presume.w)&&(event.motion.y>SM.presume.y)&&(event.motion.y<SM.presume.y+SM.presume.h)&&(!nbmenu))
    				{
						Mix_PlayChannel(2, son, 0);
    				}
			if ((event.motion.x>SM.psave.x)&&(event.motion.x<SM.psave.x+SM.psave.w)&&(event.motion.y>SM.psave.y)&&(event.motion.y<SM.psave.y+SM.psave.h)&&(!nbmenu))
    				{
						Mix_PlayChannel(2, son, 0);
						    FILE * f = fopen("savedgame", "wb" ) ;
   							fwrite( &cam.pos_cam, sizeof(SDL_Rect), 1, f ) ;
    						fwrite( &kay.hp, sizeof(int), 1, f ) ;
    						fwrite( &kay.posrkay, sizeof(SDL_Rect), 1, f ) ;
							fwrite( &kay.poskay, sizeof(SDL_Rect), 1, f ) ;
    						fclose(f);
						    TTF_CloseFont(police);
							SDL_FreeSurface(texte);
							SDL_FreeSurface(SM.menu);

							SDL_FreeSurface (SM.resume);//
							SDL_FreeSurface (SM.settings);//
							SDL_FreeSurface (SM.quit);//
							SDL_FreeSurface (SM.save);//
						return 1;

    				}
			if ((event.motion.x>SM.psettings.x)&&(event.motion.x<SM.psettings.x+SM.psettings.w)&&(event.motion.y>SM.psettings.y)&&(event.motion.y<SM.psettings.y+SM.psettings.h)&&(!nbmenu))
    				{
						Mix_PlayChannel(2, son, 0);
						
						cas=3;
    				}
			if ((event.motion.x>SM.pquit.x)&&(event.motion.x<SM.pquit.x+SM.pquit.w)&&(event.motion.y>SM.pquit.y)&&(event.motion.y<SM.pquit.y+SM.pquit.h)&&(!nbmenu))
    				{
						Mix_PlayChannel(2, son, 0);
						
						cas=4;
    				}
				break;
    		case SDL_MOUSEBUTTONUP:
			if ((event.motion.x>SM.presume.x)&&(event.motion.x<SM.presume.x+SM.presume.w)&&(event.motion.y>SM.presume.y)&&(event.motion.y<SM.presume.y+SM.presume.h)&&(!nbmenu))
    				{
				nbmenu=1;
				cas=1;
    				}
			if ((event.motion.x>SM.psave.x)&&(event.motion.x<SM.psave.x+SM.psave.w)&&(event.motion.y>SM.psave.y)&&(event.motion.y<SM.psave.y+SM.psave.h)&&(!nbmenu))
    				{
				nbmenu=2;
				cas=2;
    				}
			if ((event.motion.x>SM.psettings.x)&&(event.motion.x<SM.psettings.x+SM.psettings.w)&&(event.motion.y>SM.psettings.y)&&(event.motion.y<SM.psettings.y+SM.psettings.h)&&(!nbmenu))
    				{
				nbmenu=3;
    				}
			if ((event.motion.x>SM.pquit.x)&&(event.motion.x<SM.pquit.x+SM.pquit.w)&&(event.motion.y>SM.pquit.y)&&(event.motion.y<SM.pquit.y+SM.pquit.h)&&(!nbmenu))
    				{
				nbmenu=4;
				continuer=0;
    				}
			break;			
			
		}
		displaysousmenu(&nbmenu,&SM,ecran,&cas);

		SDL_Flip(ecran);
}
    TTF_CloseFont(police);
	SDL_FreeSurface(texte);
	SDL_FreeSurface(SM.menu);

	SDL_FreeSurface (SM.resume);//
	SDL_FreeSurface (SM.settings);//
	SDL_FreeSurface (SM.quit);//
	SDL_FreeSurface (SM.save);//
	


    return continuer;
}
				/*
										//police = TTF_OpenFont("Road_Rage.ttf", 32);
						//sprintf(softwave, "les createurs de ce jeux sont l'equipe de Softwave Games 1A1");
						//texte = TTF_RenderText_Blended(police,softwave, couleurNoire);
				if((event.motion.y>posplay.y)&&(event.motion.y<posplay.y+posplay.h)&&(temp==0))
				{	
						Mix_VolumeChunk(son,0);
						Mix_VolumeMusic(0);
				}*/
