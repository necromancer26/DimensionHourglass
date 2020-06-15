#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"

void init_enigme(enigmeyacyn * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
}
/*
 void generate_afficher (SDL_Surface * screen  , char image [],enigmeyacyn *e,int *alea)
{ //tache yascyine
	/*int test=*alea ;
	
if(*alea<3){

do{
 
 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
(*alea)++;

}while(*alea==2) ;
}else if (*alea<5 && *alea>2){

do{
 
 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
(*alea)++;

}while(*alea==4) ;}
else{

do{
 
 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
(*alea)++;

}while(*alea==6) ;}
}*/
 
 int solution_e (char image [],int *ques)
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.png")==0)
 	{
     solution =3 ;
 	(*ques)=1;}
 	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =2;
		(*ques)=2;

 	}
 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =1;
(*ques)=3;	
 	}
 	else 	if(strcmp(image,"4.png")==0)
 	{
 		solution =2;
(*ques)=4;	
 	}
 	else 	if(strcmp(image,"5.png")==0)
 	{
 		solution =2;
(*ques)=5;	
 	}
 	else 	if(strcmp(image,"6.png")==0)
 	{
 		solution =2;	
(*ques)=6;
 	}
 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
int doing=1;
while(doing){
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
doing=0;
			   break ;
			   case  SDLK_z :
			   r= 2;
doing=0;
			   break;
			   case SDLK_e: 
			   r=3 ;
doing=0;
			   break;
			    }
       break ;

                 
	}}
  return r ;
}
 
 int afficher_resultat (SDL_Surface * screen,int s,int r,enigmeyacyn *en,int ques)
 {SDL_Surface * image=NULL;
 switch(ques){
case 1:

image=IMG_Load("1e.png");
break;
case 2:

image=IMG_Load("2e.png");
break;
case 3:

image=IMG_Load("3e.png");
break;
case 4:

image=IMG_Load("4e.png");
break;
case 5:

image=IMG_Load("5e.png");
break;
case 6:

image=IMG_Load("6e.png");
break;

}
	SDL_BlitSurface(image, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	if (r==s)
 	{

	en->img=IMG_Load("00.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
return 1;
 		} 	
 	else
 	{
 		en->img=IMG_Load("11.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
return 0;
 	}
 }
 
