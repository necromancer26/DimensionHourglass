#ifndef MENU_INCLUDED
#define MENU_INCLUDED
#include "header.h"
#include "ennemieya.h"
#include<SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/*------------------------------------------------------------------*/
/*------------------------LES STRUCTURES----------------------------*/
typedef struct Menu
{
	SDL_Surface *menu;//
	SDL_Surface *play;//
	SDL_Surface *settings;//
	SDL_Surface *credits;//
	SDL_Surface *quit;//
	SDL_Surface *newgame;//
	SDL_Surface *savedgame;
	SDL_Surface *onep;
	SDL_Surface *multp;
	SDL_Surface *charact1;
	SDL_Surface *charact2;
	SDL_Surface *resume;
	SDL_Surface *sound;
	SDL_Surface *mute;
	SDL_Surface *up;
	SDL_Rect pmenu;
	SDL_Rect pplay;
	SDL_Rect psettings;
	SDL_Rect pcredits;
	SDL_Rect pquit;
	SDL_Rect pnewgame;
	SDL_Rect psavedgame;
	SDL_Rect ponep;
	SDL_Rect pmultp;
	SDL_Rect pcharact1;
	SDL_Rect pcharact2;
	SDL_Rect presume;
	SDL_Rect psound;
	SDL_Rect pup;
	SDL_Rect pmute;


}menu;

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*-------------------------LES PROTOTYPES-----------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
void initmenu(menu *m);
void displaymenu(int *nbmenu,menu *m,SDL_Surface *ecran,int *cas);
void menus(int *choix);

#endif
