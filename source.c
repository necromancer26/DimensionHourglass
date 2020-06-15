#include "header.h"
#include "rotozoom.h"
/*--------------------------------------------------------------------*/
/*-----------------------AFFICHAGE ET HP------------------------------*/
/*--------------------------------------------------------------------*/
void displaybackground(SDL_Surface *fecran,SDL_Surface *fbackmask,SDL_Surface *fbackgm,SDL_Rect *fbg,SDL_Rect *fpos_cam)
{
        SDL_BlitSurface(fbackmask, fpos_cam,fecran,fbg);
        SDL_BlitSurface(fbackgm, fpos_cam,fecran,fbg);
        //SDL_BlitSurface(fkayimg, NULL,fecran,fposkay);
		SDL_Flip(fecran);
}
void displayhp(int *continuer,Kay *kay ,SDL_Surface *fecran)
{
	SDL_Rect fposheart2,fposheart3;
	fposheart2=kay->poshp;
	fposheart3=kay->poshp;
	fposheart2.x+=50;
	fposheart3.x+=100;
	if (kay->hp==3)
	{	
		SDL_BlitSurface(kay->imghp,NULL,fecran,&(kay->poshp));
		SDL_BlitSurface(kay->imghp,NULL,fecran,&fposheart2);
		SDL_BlitSurface(kay->imghp,NULL,fecran,&fposheart3);
	}
	if (kay->hp==2)
	{
		SDL_BlitSurface(kay->imghp,NULL,fecran,&(kay->poshp));
		SDL_BlitSurface(kay->imghp,NULL,fecran,&fposheart2);
		
	}
	if (kay->hp==1)
	{
		SDL_BlitSurface(kay->imghp,NULL,fecran,&(kay->poshp));
	}
	if (!kay->hp)
	{
		rotozoom();
		*continuer=0;
	}
	SDL_Flip(fecran);
}

void animationES(ESH *helico,int *helianim)
{
if((helico->poses.x>1)&&(helico->poses.x<=900)&&(*helianim==0))
	{
	helico->poses.x-=2;
	if(helico->poses.x<=20)
	*helianim=1;
	}
if ((helico->poses.x>1)&&(helico->poses.x<=900)&&(*helianim==1))
	{
	helico->poses.x+=2;
	if(helico->poses.x>=899)
	*helianim=0;
	}
}


/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*-------------------------DEPLACEMENT--------------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
void deplacerkay(Kay *kay,Camera *cam,int *d,int *scroll,Background *backgrd,int *collision)
{
	switch (*d)
	{
	case 1://droite
					if ((kay->poskay.x >100)&&(kay->posrkay.x< 5057-1100))
					{
						*scroll=1;
							
						kay->posrkay.x+=5;
						cam->pos_cam.x=kay->posrkay.x-(100);
						kay->poskay.x=kay->poskay.x;	

					}
					else if((kay->poskay.x <=100)||(kay->posrkay.x>=5057-1100))
					{	
						kay->posrkay.x+=5;
						kay->poskay.x+=5;
						
					}
					
	*collision=Test_Collision(backgrd->backmask,kay->posrkay,d);

				
		break;
		return;
	case 2://gauche
				//collision=0;
			if((kay->posrkay.x>100)||(kay->posrkay.x<5057-1100))
				{
				kay->posrkay.x-=5;
				cam->pos_cam.x=kay->posrkay.x-(100);
				kay->poskay.x=kay->poskay.x;
				}
			else if((kay->poskay.x <=100)||(kay->posrkay.x>=5057-1100))
			{
						kay->posrkay.x-=5;
						kay->poskay.x-=5;
						cam->pos_cam.x=kay->posrkay.x;
			}
				*collision=Test_Collision(backgrd->backmask,kay->posrkay,d);

				
	
		break;
		return;	
	case 3://haut
				kay->poskay.y-=5;
				kay->posrkay.y=kay->poskay.y;
				//kay->posrkay.y-=5;
				*collision=Test_Collision(backgrd->backmask,kay->posrkay,d);
		break;
		return;
	case 4://bas
				kay->poskay.y+=5;
				kay->posrkay.y=kay->poskay.y;
				*collision=Test_Collision(backgrd->backmask,kay->posrkay,d);
	return;
		break;

	}
	
	*collision=Test_Collision(backgrd->backmask,kay->posrkay,d);
}
/************************jump***********************************/
void acceleration(Kay *kay,Camera *cam,int *aclrt,int *maxj,int *scroll,int *decceleration)
{
	if (*scroll==0)
	{
	if(*maxj==0)
	{
	kay->poskay.x+=1*((*aclrt)/(*decceleration));
	kay->posrkay.x+=1*((*aclrt)/(*decceleration));
	}

	if(*maxj==1)
	{
	kay->poskay.x+=1*((*aclrt)/(*decceleration));
	kay->posrkay.x+=1*((*aclrt)/(*decceleration));
	}
	}
	if (*scroll==1)
	{
	if(*maxj==0)
	{
	kay->posrkay.x+=1*((*aclrt)/(*decceleration));
	cam->pos_cam.x+=1*((*aclrt)/(*decceleration));
	}

	if(*maxj==1)
	{
	kay->posrkay.x+=1*((*aclrt)/(*decceleration));
	cam->pos_cam.x+=1*((*aclrt)/(*decceleration));
	}
	}
	

}

//saut
void saut(Kay *kay)
{
	if(kay->saut == 1)
	{
		//kay->poskay.y += 1;
		if(kay->hauteurAtteint == 0)
		{
			kay->poskay.y -= 4;
		}
		else
		{
			kay->poskay.y += 4;
		}
		if(kay->posinit - kay->poskay.y > kay->hauteur)
		{
			kay->hauteurAtteint = 1;
		}
		if(kay->hauteurAtteint == 1 && kay->posinit - kay->poskay.y <= 0)
		{
			kay->hauteurAtteint = 0;
			kay->saut = 0;
		}
	}
		
}
/*------------*/