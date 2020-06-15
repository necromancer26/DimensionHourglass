#include "header.h"
#include "menu.h"
#include"ennemieya.h"
#include "rotozoom.h"
#include "enig.h"
#include "chrono.h"
#include<SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sousmenu.h"

void game()
{
	int choix;
	menus(&choix);
	TTF_Init();
	TTF_Font *police = NULL; 
	SDL_Surface *ecran=NULL,*texte = NULL;
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
	{
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }
ecran = SDL_SetVideoMode(1200,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	printf("clear");
	//LES DECLARATIONS DE VARIABLES
	Kay kay;
	ESH helico;
	Background backgrd;
	ennemieya E;//
	engpc pc;
	ennemi en;
    Camera cam;
	int run =1,running=1,alea=1;;
	char imageee[30]="";
	char temps[30] = ""; 
	int ques=0;
	int pos_souris;
	enigmeyacyn eycn;
	SDL_Rect positionchrono,bg;
 positionchrono.x=200;
  positionchrono.y=0;
	SDL_Event event;
    SDL_Color color;
SDL_Color couleurBlanche = {255, 255, 255}; //couleur
	int n=0,nbClickDroite=2,nbClickGauche=2,dist,continuer=1,collision,scroll=0,sol,r,d,i,hp;//
	int randennemy,frameennemy,helianim,lightanim;
	int frame,aclrt,maxj,loopj,projectl,maxp,computer,enig,souris;
	int noennemi=1;
	int answer=2;
	unsigned int decceleration=1;
float dt;
int tempsActuel = 0, tempsPrecedent = 0, compteur = 0,fps=0,fpm=0,fph=0; //calcul fps
	srand((unsigned) time(NULL));
	hp=kay.hp;
	//LES INITIALISATIONS
	//
	backgrd.background=NULL;
	backgrd.backmask=NULL;
	kay.imghp=NULL;
	kay.hp=3;
	enig=1;



helianim=0;
aclrt=1;
decceleration=1;

backgrd.backmask=IMG_Load("gamebgm500.jpg");
//backgrd.background=IMG_Load("gamebgm500.jpg");
backgrd.background=IMG_Load("gamebg500.jpg");
kay.imghp=IMG_Load("sprite/hp.png");

init_cam(&(cam.pos_cam));
init_background(backgrd.background,backgrd.backmask,ecran,&bg);


police = TTF_OpenFont("arial.ttf", 25); //chargement type du police
texte = TTF_RenderText_Blended(police, temps, couleurBlanche); // affichage du police*
tempsActuel = SDL_GetTicks();
sprintf(temps, "Temps : %d", compteur);

pc.pospc.x=1000;
pc.pospc.y=1000;
pc.imgpc=IMG_Load("ES/pc.png");

initeneya(&E);//tache eya
initen(&en);

initkay(&kay,&choix);//fct fatma
init_hp(kay.imghp,ecran,&(kay.poshp));
pos_souris=kay.poskay.x;
initES(&helico);

SDL_EnableKeyRepeat(10, 10);
//DEBUT DE LA BOUCLE DU JEU
while (continuer) 
{
animationES(/*&light,*/&helico/*,&lightanim*/,&helianim);//animation es
animateEnnemi(&E);//
updateEnnemiState(&E,E.posennemi.x-kay.poskay.x);//
moveEnnemi(&E,&kay);
frame++;
if(frame==4)
frame=0;
if(cam.pos_cam.x<=10)
cam.pos_cam.x=0;
	frameennemy++;
	if(frameennemy==7)
	frameennemy=0;
//pos_souris=kay.poskay.x;
    //SDL_WaitEvent(&event);
	while(SDL_PollEvent(&event))
	{
    switch(event.type) 
    {
    	case SDL_QUIT: 
    		continuer = 0;
    	    break;
		case SDL_MOUSEBUTTONDOWN:
		souris=1;
		pos_souris = event.button.x - kay.poskay.w / 2;
		break;
    	case SDL_KEYDOWN:
		    switch(event.key.keysym.sym)
    		{
				case SDLK_ESCAPE:
				continuer=sous_menus(kay,cam);
				break;
				case SDLK_RIGHT:
				d=1;
                nbClickDroite++;
                if(nbClickDroite%2==1)
                {
                n=1;
                }else
				{
                n=0;
                }
				deplacerkay(&kay,&cam,&d,&scroll,&backgrd,&collision);

				
                break;
				case SDLK_LEFT:
				d=2;
                nbClickGauche++;
                if(nbClickGauche%2==1)
                n=1;
                else
                n=0;
				
				deplacerkay(&kay,&cam,&d,&scroll,&backgrd,&collision);
				
				break;
						
				case SDLK_UP:
				d=3;

				printf("%d",collision);
				deplacerkay(&kay,&cam,&d,&scroll,&backgrd,&collision);
				break;
				case SDLK_DOWN:
				d=4;

				deplacerkay(&kay,&cam,&d,&scroll,&backgrd,&collision);
				break;

				case SDLK_r:
				//kay.posinit=kay.poskay.y;
				kay.saut = 1;
    			break;
				case SDLK_d://decceleration
				maxj=1;
				d=1;
				if (decceleration<=2)
				decceleration=3;
				if ((aclrt<100)&&(maxj==1)&&(aclrt>5))
				{
				decceleration++;
				aclrt--;
				}
				else if(aclrt<=5)
				aclrt=aclrt;
				acceleration(&kay,&cam,&aclrt,&maxj,&scroll,&decceleration);
				collision=Test_Collision(backgrd.backmask,kay.posrkay,&d);
				break;

				case SDLK_a://acceleration
				maxj=0;
				d=1;
				if (decceleration<=2)
				decceleration=3;
				if((aclrt<100)&&(maxj==0))
				{
				aclrt++;
				decceleration--;
				}
				else if(aclrt==99)
				{
				aclrt=aclrt;
				}

				acceleration(&kay,&cam,&aclrt,&maxj,&scroll,&decceleration);
				collision=Test_Collision(backgrd.backmask,kay.posrkay,&d);
				break;
                case SDLK_SPACE:
                E.state=running_away;
                n=2;
                
                break;

         }   
	}
	}
if(souris==1)
{
deplacerSouris(&kay, pos_souris);
}
enig=Collision_Bounding_Box_Enigme(&kay,&pc);
noennemi=Collision_Bounding_Box(&kay,&en);
saut(&kay);
cascollisionBG(&kay,&cam,&scroll,&d,&collision);
if(enig==0)
{
	SDL_EnableKeyRepeat(0, 0);
	enigme();
	enig=1;
	ecran = SDL_SetVideoMode(1200,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	SDL_EnableKeyRepeat(10, 10);
	continuer=0;
}

if ((scroll==1)&&(en.posennemi.x>=10)&&(kay.posrkay.x<3500))
en.posennemi.x-=5;
else if((en.posennemi.x<10)&&(kay.posrkay.x<3500))
en.posennemi.x=2000;
if(en.posennemi.x==2000)
en.posennemi.y=(rand()%100)+600;



if((noennemi==0)&&(kay.poskay.x>100))
{
 generate_afficher ( ecran  , imageee ,&eycn,&alea) ;
      sol=solution_e (imageee,&ques);	
		r=resolution (&running,&run);
			answer=afficher_resultat(ecran,sol,r,&eycn,ques) ;
if(answer==1&&kay.hp<=3)
{
	if(kay.hp==3)
	kay.hp=3;
	else
	kay.hp++;
}

else
	kay.hp-=1;
	noennemi=1;
	en.posennemi.x=2000;	
}



displaybackground(ecran,backgrd.backmask,backgrd.background,&(backgrd.posbg),&(cam.pos_cam));
	displayhp(&continuer,&kay,ecran);
SDL_BlitSurface(helico.imges[helianim],NULL,ecran,&(helico.poses));

	SDL_BlitSurface(en.imgennemi[frameennemy],NULL,ecran,&(en.posennemi));
	SDL_BlitSurface(E.Ennemi[E.inum],NULL,ecran,&(E.posennemi));
	//printf("%d\n",kay.posrkay.y);

	printf("%d\n",kay.posrkay.x);

	if (d==1)
	SDL_BlitSurface(kay.imgkayd1[frame],NULL,ecran,&(kay.poskay));
	else
	SDL_BlitSurface(kay.imgkayd2[frame],NULL,ecran,&(kay.poskay));
	if (kay.posrkay.x>=4000)
	{
	pc.pospc.x=400;
	pc.pospc.y=640;
	SDL_BlitSurface(pc.imgpc,NULL,ecran,&pc.pospc);
	}
	        tempsActuel = SDL_GetTicks();
          dt=tempsActuel - tempsPrecedent;
         
      if (1000== 1000) 
        {
          compteur += 1000; 
          fps=compteur/1000;
           
               
             if (fps>59)
                 { fpm=(fps/60);
                 
                   
                   if(fpm>59)
                      fph=(fpm/60);
                  
                  
                 }
}              
                      
    sprintf(temps,"Temps: %d :%d :%d",fph,fpm,fps-(60*fpm));
          
     texte = TTF_RenderText_Blended(police, temps, couleurBlanche);



            tempsPrecedent = tempsActuel; 
            SDL_BlitSurface(texte, NULL, ecran, &positionchrono); 
       SDL_SetColorKey(texte,SDL_SRCCOLORKEY,SDL_MapRGB(texte->format,0,0,0));  
	

	SDL_Flip(ecran);
SDL_Delay(5);
}

SDL_FreeSurface(ecran);
	SDL_FreeSurface(kay.imghp);
    SDL_FreeSurface(backgrd.backmask);
    SDL_FreeSurface(backgrd.background);

		SDL_FreeSurface(kay.imgkayd1[0]);
		SDL_FreeSurface(kay.imgkayd2[0]);


    SDL_Quit();
    return ;
}
