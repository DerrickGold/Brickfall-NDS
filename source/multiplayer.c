#include <PA9.h> 

#include "header.h"
#include "multiplayertest.h"


void multimenu(){

  PA_Init16cBg (0,0);
	startmenu=FALSE;
	bool startmulti=TRUE;
	
	s8 number=2;
	
	
	PA_16cText(0,30, 30, 255, 192,"\n\n\n # of players: \n\n\n\n Speed:",1,4,100);
	
	//players sprites
	PA_LoadSpritePal(0,2,(void*)speedspri_Pal);
	PA_CreateSprite(0,4,(void*)speedspri_Sprite,OBJ_SIZE_32X32,1,2,200,72);

	PA_LoadSpritePal(0,3,(void*)arrow_Pal);
	PA_CreateSprite(0,5,(void*)arrow_Sprite,OBJ_SIZE_16X16,1,3,200,56);
	PA_CreateSprite(0,6,(void*)arrow_Sprite,OBJ_SIZE_16X16,1,3,200,90);
	PA_SetSpriteVflip(0,6,1);
	
	
	//go sprite
	PA_LoadSpritePal(0,4,(void*)go1_Pal);
	PA_LoadSpritePal(0,5,(void*)go2_Pal);
	
	PA_CreateSprite(0,7,(void*)go1_Sprite,OBJ_SIZE_64X32,1,4,70,160);
	PA_CreateSprite(0,8,(void*)go2_Sprite,OBJ_SIZE_64X32,1,5,134,160);
	
	//speed
	PA_CreateSprite(0,9,(void*)speedspri_Sprite,OBJ_SIZE_32X32,1,2,200,125);
	
  PA_CreateSprite(0,10,(void*)arrow_Sprite,OBJ_SIZE_16X16,1,3,200,110);
	PA_CreateSprite(0,11,(void*)arrow_Sprite,OBJ_SIZE_16X16,1,3,200,143);
	PA_SetSpriteVflip(0,11,1);
	
	while(startmulti==TRUE){
	
	  //players--------------------------------------------
		//player up
		if ((Stylus.Newpress)&&(PA_SpriteTouched(5))){
      PA_WaitForVBL();PA_WaitForVBL();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			number++;
		}
		//player down
		else if ((Stylus.Newpress)&&(PA_SpriteTouched(6))){
      PA_WaitForVBL();PA_WaitForVBL();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			number--;
		}
		if (number==1)number++;
		else if (number==5)number--;//add one more to 4 to enable speed 4
		
		PA_SetSpriteAnim (0,4,number-1);
	
	
	
    //speeds--------------------------------------------
		//speed up
		if ((Stylus.Newpress)&&(PA_SpriteTouched(10))){
      PA_WaitForVBL();PA_WaitForVBL();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			player.speed++;
		}
		//speed down
		else if ((Stylus.Newpress)&&(PA_SpriteTouched(11))){
      PA_WaitForVBL();PA_WaitForVBL();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			player.speed--;
		}
		if (player.speed==0)player.speed++;
		else if (player.speed==5)player.speed--;//add one more to 4 to enable speed 4
		
		PA_SetSpriteAnim (0,9,player.speed-1);
		
		//go button--------------------------------------
    if((Stylus.Newpress)&&(PA_SpriteTouched(7)||PA_SpriteTouched(8))){
       PA_WaitForVBL();PA_WaitForVBL();
       PA_StopSound(15);
       PA_PlaySimpleSound(15,button);
       PA_Init16cBg (0,0);
       int i;
       for(i=5;i<12;i++)PA_DeleteSprite(0,i);
    }
	
	
    PA_WaitForVBL();
	}
	
}

//void nameentrymenu()

