#include<SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "animation.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void displaymenu(int *nbmenu,menu *m,SDL_Surface *ecran,int *cas)
{
	if (*nbmenu==0)
	{
		if (*cas==1)
		{
			m->play=IMG_Load("menu/PlayS.png");
			m->settings=IMG_Load("menu/setting.png");
			m->credits=IMG_Load("menu/credit.png");
			m->quit=IMG_Load("menu/quit.png");

		}
		if (*cas==2)
		{
			m->play=IMG_Load("menu/play.png");
			m->settings=IMG_Load("menu/SettingsS.png");
			m->credits=IMG_Load("menu/credit.png");
			m->quit=IMG_Load("menu/quit.png");
		}
		
if (*cas==3)
{
			m->play=IMG_Load("menu/play.png");
			m->settings=IMG_Load("menu/setting.png");
			m->credits=IMG_Load("menu/CeditS.png");
			m->quit=IMG_Load("menu/quit.png");

}
if (*cas==4)
{
			m->play=IMG_Load("menu/play.png");
			m->settings=IMG_Load("menu/setting.png");
			m->credits=IMG_Load("menu/credit.png");
			m->quit=IMG_Load("menu/QuitS.png");
}
			SDL_BlitSurface(m->menu, NULL, ecran, &(m->pmenu));
    		SDL_BlitSurface(m->play, NULL,ecran,&(m->pplay));
			SDL_BlitSurface(m->settings, NULL,ecran,&(m->psettings));
			SDL_BlitSurface(m->credits, NULL,ecran,&(m->pcredits));
    		SDL_BlitSurface(m->quit, NULL,ecran,&(m->pquit));
	}
	if (*nbmenu==1)
	{
		if (*cas==1)
		{
						m->newgame=IMG_Load("menu/NewgS.png");
						m->savedgame=IMG_Load("menu/Saved.png");	

		}
		if (*cas==2)
		{
						m->newgame=IMG_Load("menu/NewG.png");
						m->savedgame=IMG_Load("menu/SavedS.png");
		}
    	SDL_BlitSurface(m->menu, NULL, ecran, &(m->pmenu));
    	SDL_BlitSurface(m->newgame, NULL,ecran,&(m->pnewgame));
    	SDL_BlitSurface(m->savedgame, NULL,ecran,&(m->psavedgame));
		
	}
	if (*nbmenu==11)
	{
		if (*cas==1)
		{
						m->onep=IMG_Load("menu/OnePS.png");
						m->multp=IMG_Load("menu/Mp.png");	
		}
		if (*cas==2)
		{
				m->onep=IMG_Load("menu/OneP.png");
				m->multp=IMG_Load("menu/MpS.png");
		}
		
		
    	SDL_BlitSurface(m->menu, NULL, ecran, &(m->pmenu));
    	SDL_BlitSurface(m->onep, NULL,ecran,&(m->ponep));
    	SDL_BlitSurface(m->multp, NULL,ecran,&(m->pmultp));
		
	}
	if (*nbmenu==111)
	{
		if (*cas==1)
		{
				m->charact1=IMG_Load("menu/P1S.png");
				m->charact2=IMG_Load("menu/P2.png");
		}
		if (*cas==2)
		{
				m->charact1=IMG_Load("menu/P1.png");
				m->charact2=IMG_Load("menu/P2S.png");
		}
		
		
    	SDL_BlitSurface(m->menu, NULL, ecran, &(m->pmenu));
    	SDL_BlitSurface(m->charact1, NULL,ecran,&(m->pcharact1));
    	SDL_BlitSurface(m->charact2, NULL,ecran,&(m->pcharact2));

	}
	if (*nbmenu==2)
	{
		if (*cas==2)
		{
			m->sound=IMG_Load("menu/soundmax.png");
			m->mute=IMG_Load("menu/mute.png");
			m->up=IMG_Load("menu/return.png");
		}
		if (*cas==1)
		{
			m->sound=IMG_Load("menu/soundmax.png");
			m->mute=IMG_Load("menu/mute.png");
			m->up=IMG_Load("menu/returnS.png");
		}
		
		
		
    	SDL_BlitSurface(m->menu, NULL, ecran, &(m->pmenu));
	   	SDL_BlitSurface(m->sound, NULL,ecran,&(m->psound));
		SDL_BlitSurface(m->mute, NULL,ecran,&(m->pmute));
    	SDL_BlitSurface(m->up, NULL,ecran,&(m->pup));

		
	}
	
	
	
}
/*--------------------------------------------------*/
void initmenu(menu *m)
{
	m->menu=IMG_Load("menu/BG.png");
	m->play=IMG_Load("menu/play.png");

	m->settings=IMG_Load("menu/setting.png");

	m->credits=IMG_Load("menu/credit.png");

	m->quit=IMG_Load("menu/quit.png");

	m->newgame=IMG_Load("menu/NewG.png");
	m->savedgame=IMG_Load("menu/Saved.png");

	m->onep=IMG_Load("menu/OneP.png");

	m->multp=IMG_Load("menu/Mp.png");

	m->charact1=IMG_Load("menu/P1.png");

	m->charact2=IMG_Load("menu/P2.png");

	m->resume=IMG_Load("menu/ResumeS.png");

	m->sound=IMG_Load("menu/soundmax.png");
	m->mute=IMG_Load("menu/mute.png");

	m->up=IMG_Load("menu/up.png");


	m->pmenu.x=0;
	m->pmenu.y=0;	

	m->pplay.x=50;
	m->pplay.y=100;
	
	m->psettings.x=m->pplay.x+100;
	m->psettings.y=m->pplay.y+150;
	
	m->pcredits.x=m->psettings.x+100;
	m->pcredits.y=m->psettings.y+150;
	
	m->pquit.x=m->pcredits.x+100;
	m->pquit.y=m->pcredits.y+150;


	m->pnewgame.x=250;
	m->pnewgame.y=100;
	m->psavedgame.x=250;
	m->psavedgame.y=400;


	m->ponep.x=250;
	m->ponep.y=100;
	m->pmultp.x=250;
	m->pmultp.y=400;


	m->pcharact1.x=100;
	m->pcharact1.y=200;
	m->pcharact2.x=400;
	m->pcharact2.y=400;


	m->presume.x=5;
	m->presume.y=100;
	m->psound.x=200;
	m->psound.y=250;
	m->pmute.x=200;
	m->pmute.y=350;
	m->pup.x=30;
	m->pup.y=400;
	
	
}
/*--------------------------------------------------*/ 
/*--------------------------------------------------*/
/*--------------------------------------------------*/

void menus(int *choix)
{

	menu m;
	SDL_Surface *ecran=NULL,*texte=NULL;
	TTF_Font *police = NULL;
	SDL_Color couleurBlanche = {255, 255, 255};
	char softwave[200] = ""; 
    SDL_Event event; /* La variable contenant l'événement */
	Mix_Music *music;
    Mix_Chunk *son;
	int selection;
	int nbmenu=0,v=100; // variable pour le changement de l'affichage du menu
	int continuer = 1;
	int cas;
	SDL_Rect ptexte;
	ptexte.x=100;
	ptexte.y=200;
	//*jeux=0;


	SDL_Init(SDL_INIT_EVERYTHING);
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) // Démarrage de la SDL. Si erreur :
	    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    	}
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
    	printf("%s\n",Mix_GetError() );
    }
	/*-------------------------------------------------*/  
police = TTF_OpenFont("arial.ttf", 100);
	music = Mix_LoadMUS("music.mp3");
    son = Mix_LoadWAV("beep.wav");
    Mix_PlayMusic(music,-1);
	ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
	/*-------------------------------------------------*/
	initmenu(&m);
	SDL_BlitSurface(m.menu, NULL, ecran, &(m.pmenu));
    //SDL_BlitSurface(texte, NULL, ecran, &(m.pcredits)); /* Blit du texte */
	SDL_BlitSurface(m.play, NULL,ecran,&(m.pplay));
    SDL_BlitSurface(m.settings, NULL,ecran,&(m.psettings));
    SDL_BlitSurface(m.credits, NULL,ecran,&(m.pcredits));
    SDL_BlitSurface(m.quit, NULL,ecran,&(m.pquit));
	SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
    SDL_Flip(ecran);
		
	/*-------------------------------------------------*/
    while (continuer) 
    {
        //SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
    	while (SDL_PollEvent(&event))
		{
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
    				case SDLK_f:
    					ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_FULLSCREEN);
						break;
					case SDLK_e:
					ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
					break;
					case SDLK_DOWN:
					cas++;
					if(cas==5)
					cas=0;
					break;
					case SDLK_UP:
					cas--;
					if(cas==-1)
					cas=4;
					break;
				}
				break;
    		case SDL_MOUSEMOTION:
			/*----------------------Menu 1----------------*/
			if ((event.motion.x>m.pplay.x)&&(event.motion.x<m.pplay.x+m.pplay.w)&&(event.motion.y>m.pplay.y)&&(event.motion.y<m.pplay.y+m.pplay.h)&&(!nbmenu))
    				{

						
						cas=1;
    				}
			if ((event.motion.x>m.psettings.x)&&(event.motion.x<m.psettings.x+m.psettings.w)&&(event.motion.y>m.psettings.y)&&(event.motion.y<m.psettings.y+m.psettings.h)&&(!nbmenu))
    				{

						cas=2;
					}
			if ((event.motion.x>m.pcredits.x)&&(event.motion.x<m.pcredits.x+m.pcredits.w)&&(event.motion.y>m.pcredits.y)&&(event.motion.y<m.pcredits.y+m.pcredits.h)&&(!nbmenu))
    				{

						cas=3;
    				}
			if ((event.motion.x>m.pquit.x)&&(event.motion.x<m.pquit.x+m.pquit.w)&&(event.motion.y>m.pquit.y)&&(event.motion.y<m.pquit.y+m.pquit.h)&&(!nbmenu))
    				{

						cas=4;
					}
			/*----------------------Menu 11----------------*/

			if ((event.motion.x>m.pnewgame.x)&&(event.motion.x<m.pnewgame.x+m.pnewgame.w)&&(event.motion.y>m.pnewgame.y)&&(event.motion.y<m.pnewgame.y+m.pnewgame.h)&&(nbmenu==1))
			{
		
						cas=1;
			}
			if ((event.motion.x>m.psavedgame.x)&&(event.motion.x<m.psavedgame.x+m.psavedgame.w)&&(event.motion.y>m.psavedgame.y)&&(event.motion.y<m.psavedgame.y+m.psavedgame.h)&&(nbmenu==1))
			{			
	
					cas=2;
			}
			/*--------------------One p or multiP--------------*/
			if ((event.motion.x>m.ponep.x)&&(event.motion.x<m.ponep.x+m.ponep.w)&&(event.motion.y>m.ponep.y)&&(event.motion.y<m.ponep.y+m.ponep.h)&&(nbmenu==11))
			{

				
				cas=1;
			}
			if ((event.motion.x>m.pmultp.x)&&(event.motion.x<m.pmultp.x+m.pmultp.w)&&(event.motion.y>m.pmultp.y)&&(event.motion.y<m.pmultp.y+m.pmultp.h)&&(nbmenu==11))
			{

				cas=2;
			}
			/*--------------------charact 1  or charact 2--------------*/			
			if ((event.motion.x>m.pcharact1.x)&&(event.motion.x<m.pcharact1.x+m.pcharact1.w)&&(event.motion.y>m.pcharact1.y)&&(event.motion.y<m.pcharact1.y+m.pcharact1.h)&&(nbmenu==111))
			{

				
				cas=1;
			}
			if ((event.motion.x>m.pcharact2.x)&&(event.motion.x<m.pcharact2.x+m.pcharact2.w)&&(event.motion.y>m.pcharact2.y)&&(event.motion.y<m.pcharact2.y+m.pcharact2.h)&&(nbmenu==111))
			{

				
				cas=2;
			}
			if ((event.motion.x>m.pup.x)&&(event.motion.x<m.pup.x+m.pup.w)&&(event.motion.y>m.pup.y)&&(event.motion.y<m.pup.y+m.pup.h)&&(nbmenu==2))
			{
				cas=1;
			}
			

    		break;
    		case SDL_MOUSEBUTTONDOWN :
			if ((event.motion.x>m.pplay.x)&&(event.motion.x<m.pplay.x+m.pplay.w)&&(event.motion.y>m.pplay.y)&&(event.motion.y<m.pplay.y+m.pplay.h)&&(!nbmenu))
    				{	 
    					Mix_PlayChannel(2, son, 0);

    				}
			if ((event.motion.x>m.psettings.x)&&(event.motion.x<m.psettings.x+m.psettings.w)&&(event.motion.y>m.psettings.y)&&(event.motion.y<m.psettings.y+m.psettings.h)&&(!nbmenu))
    				{
    					Mix_PlayChannel(2, son, 0);

    				}
			if ((event.motion.x>m.pcredits.x)&&(event.motion.x<m.pcredits.x+m.pcredits.w)&&(event.motion.y>m.pcredits.y)&&(event.motion.y<m.pcredits.y+m.pcredits.h)&&(!nbmenu))
    				{
    					Mix_PlayChannel(2, son, 0);
					}
			if ((event.motion.x>m.pquit.x)&&(event.motion.x<m.pplay.x+m.pquit.w)&&(event.motion.y>m.pquit.y)&&(event.motion.y<m.pquit.y+m.pquit.h)&&(!nbmenu))
    				{
    					Mix_PlayChannel(2, son, 0);
					}
				//menu11
				if ((event.motion.x>m.pnewgame.x)&&(event.motion.x<m.pnewgame.x+m.pnewgame.w)&&(event.motion.y>m.pnewgame.y)&&(event.motion.y<m.pnewgame.y+m.pnewgame.h)&&(nbmenu==1))
				{
					Mix_PlayChannel(2, son, 0);
				}
				if ((event.motion.x>m.psavedgame.x)&&(event.motion.x<m.psavedgame.x+m.psavedgame.w)&&(event.motion.y>m.psavedgame.y)&&(event.motion.y<m.psavedgame.y+m.psavedgame.h)&&(nbmenu==1))
				{
					Mix_PlayChannel(2, son, 0);
				}
				//menu111
				if ((event.motion.x>m.ponep.x)&&(event.motion.x<m.ponep.x+m.ponep.w)&&(event.motion.y>m.ponep.y)&&(event.motion.y<m.ponep.y+m.ponep.h)&&(nbmenu==11))
				{
					Mix_PlayChannel(2, son, 0);
				}
				if ((event.motion.x>m.pcharact1.x)&&(event.motion.x<m.pcharact1.x+m.pcharact1.w)&&(event.motion.y>m.pcharact1.y)&&(event.motion.y<m.pcharact1.y+m.pcharact1.h)&&(nbmenu==111))
				{
					Mix_PlayChannel(2, son, 0);	
				}
				///menu112
				if ((event.motion.x>m.pcharact2.x)&&(event.motion.x<m.pcharact2.x+m.pcharact2.w)&&(event.motion.y>m.pcharact2.y)&&(event.motion.y<m.pcharact2.y+m.pcharact2.h)&&(nbmenu==111))
				{
					Mix_PlayChannel(2, son, 0);								
				}
				break;
    		case SDL_MOUSEBUTTONUP:
			if ((event.motion.x>m.pplay.x)&&(event.motion.x<m.pplay.x+m.pplay.w)&&(event.motion.y>m.pplay.y)&&(event.motion.y<m.pplay.y+m.pplay.h)&&(!nbmenu))
			{
				nbmenu=1;
				cas=1;
			}
			if ((event.motion.x>m.psettings.x)&&(event.motion.x<m.psettings.x+m.psettings.w)&&(event.motion.y>m.psettings.y)&&(event.motion.y<m.psettings.y+m.psettings.h)&&(!nbmenu))
			{
				nbmenu=2;
				cas=2;
			}
			if ((event.motion.x>m.pcredits.x)&&(event.motion.x<m.pcredits.x+m.pcredits.w)&&(event.motion.y>m.pcredits.y)&&(event.motion.y<m.pcredits.y+m.pcredits.h)&&(!nbmenu))
			{
				DimensionHourglass();
			}
			if ((event.motion.x>m.pquit.x)&&(event.motion.x<m.pquit.x+m.pquit.w)&&(event.motion.y>m.pquit.y)&&(event.motion.y<m.pquit.y+m.pquit.h)&&(!nbmenu))
			{
				continuer=0;
			}
			//menu11
			if ((event.motion.x>m.pnewgame.x)&&(event.motion.x<m.pnewgame.x+m.pnewgame.w)&&(event.motion.y>m.pnewgame.y)&&(event.motion.y<m.pnewgame.y+m.pnewgame.h)&&(nbmenu==1))
			{
				nbmenu=11;
				cas=1;
			}
			if ((event.motion.x>m.psavedgame.x)&&(event.motion.x<m.psavedgame.x+m.psavedgame.w)&&(event.motion.y>m.psavedgame.y)&&(event.motion.y<m.psavedgame.y+m.psavedgame.h)&&(nbmenu==1))
			{
				nbmenu=12;
				cas=1;
			}
			//menu111
			if ((event.motion.x>m.ponep.x)&&(event.motion.x<m.ponep.x+m.ponep.w)&&(event.motion.y>m.ponep.y)&&(event.motion.y<m.ponep.y+m.ponep.h)&&(nbmenu==11))
			{
				nbmenu=111;
				cas=1;
			}
			if ((event.motion.x>m.pcharact1.x)&&(event.motion.x<m.pcharact1.x+m.pcharact1.w)&&(event.motion.y>m.pcharact1.y)&&(event.motion.y<m.pcharact1.y+m.pcharact1.h)&&(nbmenu==111))
			{
				*choix=111;
				//game();
				continuer=0;
							
			}
			///menu112
			if ((event.motion.x>m.pcharact2.x)&&(event.motion.x<m.pcharact2.x+m.pcharact2.w)&&(event.motion.y>m.pcharact2.y)&&(event.motion.y<m.pcharact2.y+m.pcharact2.h)&&(nbmenu==111))
			{
				*choix=112;
				//game();
				continuer=0;
							
			}
			if ((event.motion.x>m.pup.x)&&(event.motion.x<m.pup.x+m.pup.w)&&(event.motion.y>m.pup.y)&&(event.motion.y<m.pup.y+m.pup.h)&&(nbmenu==2))
			{
				cas=1;
				nbmenu=0;
			}
			if ((event.motion.x>m.psound.x)&&(event.motion.x<m.psound.x+m.psound.w)&&(event.motion.y>m.psound.y)&&(event.motion.y<m.psound.y+m.psound.h)&&(nbmenu==2))
			{
				v+=10;
					Mix_VolumeChunk(son,v);
					Mix_VolumeMusic(v);
				
			}
			if ((event.motion.x>m.pmute.x)&&(event.motion.x<m.pmute.x+m.pmute.w)&&(event.motion.y>m.pmute.y)&&(event.motion.y<m.pmute.y+m.pmute.h)&&(nbmenu==2))
			{
				v-=10;
					Mix_VolumeChunk(son,v);
					Mix_VolumeMusic(v);
				
			}
			break;			
			
		}
		}
		displaymenu(&nbmenu,&m,ecran,&cas);
		SDL_Flip(ecran);
}
   /* TTF_CloseFont(police);
	SDL_FreeSurface(texte);
	SDL_FreeSurface(m.menu);

	SDL_FreeSurface (m.play);//
	SDL_FreeSurface (m.settings);//
	SDL_FreeSurface (m.credits);//
	SDL_FreeSurface (m.quit);//
	SDL_FreeSurface (m.newgame);//
	SDL_FreeSurface (m.savedgame);
	SDL_FreeSurface (m.onep);
	SDL_FreeSurface (m.multp);
	SDL_FreeSurface (m.charact1);
	SDL_FreeSurface (m.charact2);
	SDL_FreeSurface (m.resume);

	
	SDL_FreeSurface (m.up);

	SDL_FreeSurface (m.sound);
	SDL_FreeSurface(ecran);*/
	//SDL_FreeSurface(ecran);

return ;
}
				

