#include <PA9.h> 

#include "header.h"
#include "loading.h"
#include "gameitems.h"
#include "collision.h"

void createitems(){

  
	item.number=0;

	item.x=PA_Rand()%256-16;
	item.y=-16;

	PA_LoadSpritePal(0,8,(void*)itemspri_Pal);
	PA_CreateSprite(0,8,(void*)itemspri_Sprite,OBJ_SIZE_16X16,1,8,item.x,item.y);

	item.movement=TRUE;
}
	

		
void itemhandling(){
	//item handling

		if((item.movement==TRUE)&&(gamedata.startgame==1)){
		
      

			
			PA_SetSpriteXY(0,8,item.x,item.y);
			
			item.y+=1;//item fall speed
			
			//keeps the items from going off the sides of the screen
			if(item.xaxis==0)item.x+=2;
			else if(item.xaxis==1)item.x-=2;			
			if(item.x+16>256)item.xaxis=1;
			else if(item.x<0)item.xaxis=0;
			

      //collision of item and player
			if((item.x+16>=player.x)&&(item.x<=player.x+8)){

				if((item.y+16>player.y)&&(item.y<player.y+8)){
          int effectnum=PA_RandMinMax(1,6);//picks an item

					item.number=effectnum;	
				}
			}

			if(item.y>192){//if item box goes off the bottom of the screen
				PA_DeleteSprite(0,8);
				
				item.time=0;
				item.movement=FALSE;
			}

		}
		
		
    //items
		switch(item.number){
		
      case 6://up speed
        item.y=-20;
        item.time=0;
        
                     
        if(gamedata.startgame==1){
          item.timer++;
           gamedata.scrolly+=player.platspeed;
           checkcontrolls();
           CheckCollisions();

        }
        if(item.timer>=300){
          item.timer=0;
          item.movement=FALSE;

          
          item.number=0;
        }
      break;
		
      case 5://switch screens
        if(item.screen==0)item.screen=1;
        else if(item.screen==1)item.screen=0;
        item.y=-20;
        PA_DeleteSprite(0,8);
        
        item.time=0;		
        PA_SwitchScreens();
        int miliseconds;
        for(miliseconds=0;miliseconds<45;miliseconds++){
          
          PA_WaitForVBL(); 
        }   
        item.timer=0;
        item.movement=FALSE;
        item.number=0;
        
      break;
		
		
      case 4://load new platforms
        PA_DeleteSprite(0,8);
        item.time=0;
        PA_DeleteBg(0,2);
        PA_DeleteBg(0,1);
        PA_DeleteBg(0,0);				      
        platformload();         
        PA_ParallaxScrollY(0, gamedata.scrolly);
        item.number=0;
        item.movement=FALSE;
      break;

      case 3://reverse controlls
        item.y=-20;
        item.time=0;
			
        if(gamedata.startgame==1)item.timer++;
        if(item.timer>=350){
          item.timer=0;
          item.movement=FALSE;
          item.number=0;
        }
      break;
			
      case 2:// invisible platforms
        item.y=-20;
        item.time=0;
			
        if(gamedata.startgame==1)item.timer++;
        PA_EnableSpecialFx(0, SFX_ALPHA, SFX_BG2, SFX_BG3 );

        PA_SetSFXAlpha (0,15,15);  
        if(item.timer>=250){
          item.timer=0;
          item.movement=FALSE;
          PA_DisableSpecialFx(0); 
          item.number=0;
        }
      break;

      case 1://slo mo
        item.y=-20;
        item.time=0;
					
        item.slomo++;
        if(item.slomo>=150){
				
          item.time=0;
          item.slomo=0;
          item.movement=FALSE;
          item.number=0;
        }
			

        PA_WaitForVBL();PA_WaitForVBL();
			
      break;
		}//end of switch
}


	
