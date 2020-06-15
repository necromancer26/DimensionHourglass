#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"ennemieya.h"
void initeneya(ennemieya *E)
{
E->posennemi.x=800;
E->posennemi.y=640;
E->Ennemi[0]=IMG_Load("sprite/2.png");
E->Ennemi[1]=IMG_Load("sprite/2.png");
E->Ennemi[2]=IMG_Load("sprite/7.png");
E->Ennemi[3]=IMG_Load("sprite/2.png");
E->Ennemi[4]=IMG_Load("sprite/2.png");
E->Ennemi[5]=IMG_Load("sprite/2.png");
E->Ennemi[6]=IMG_Load("sprite/2.png");
E->state=waiting;
E->ixmin=700;
E->ixmax=900;
E->d=0; 
}
void animateEnnemi(ennemieya* E)
{ 
if((*E).state==waiting)         
 {                                 
       
        (*E).inum=0;       //inum de l image 
}

    if((*E).state==following)
{

     (*E).inum=1;
        
}
    if((*E).state==running_away)               
        (*E).inum=2;
    else if((*E).state==attacking)
         
{if((*E).inum<2)(*E).inum++;
        if((*E).inum<6) (*E).inum++;}
}



void moveEnnemi(ennemieya* E,Kay *kay)  //pos heya lposition mta3 ljoueur
{
    if(((*E).state==following)||((*E).state==attacking))
    {
        if((*E).posennemi.x<kay->poskay.x+135)
            (*E).posennemi.x+=4;
        else if((*E).posennemi.x>kay->poskay.x+145)
            (*E).posennemi.x-=4;
    }
    if((*E).state==waiting)
    {
        if((*E).d==0)
        {
            if((*E).posennemi.x<(*E).ixmax)
                (*E).posennemi.x+=5;
            else (*E).d=1;
        }
        else if((*E).d==1)
        {
            if((*E).posennemi.x>(*E).ixmin)
                (*E).posennemi.x-=5;
            else (*E).d=0;
        }
    }
    if((*E).state==running_away)
        (*E).posennemi.x+=10;
}


void updateEnnemiState (ennemieya* E, int dist) //f dist 7otE.posennemi.posjoueur.x
{ 
if ((*E).state!=running_away)
   { if (dist<600)
{
      

    if(dist>300)

            (*E).state=following;

    else if(dist>100)
            (*E).state=attacking;
}
else 
{
(*E).state=waiting;
}
}

}