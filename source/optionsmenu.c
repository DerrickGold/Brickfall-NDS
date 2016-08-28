#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"
#include "gameeffects.h"


void options(){

  PA_Init16cBg (0,0);
  PA_InitText(1,0);
	startmenu=FALSE;
	player.options=TRUE;
	
	//PA_SetBgPalCol(0, 255, PA_RGB(31, 31, 31));


	s16 scrollbgx;
	
	for(scrollbgx=0;scrollbgx<255;scrollbgx+=6){
				PA_EasyBgScrollXY(0,1,scrollbgx,0);
				PA_WaitForVBL();
	}

	

	PA_16cText(0,30, 25, 255, 192,"\n\n Brightness: \n\n Use Mp3: \n\n Items: \n\n Motion:",1,4,100);
	

	PA_LoadSpritePal(0,0,(void*)menu1_Pal);
	PA_LoadSpritePal(0,1,(void*)menu2_Pal);

	PA_CreateSprite(0,0,(void*)menu1_Sprite,OBJ_SIZE_64X32,1,0,64, 160);
	PA_CreateSprite(0,1,(void*)menu2_Sprite,OBJ_SIZE_64X32,1,1,128,160);

	PA_LoadSpritePal(0,4,(void*)lights_Pal);
	PA_CreateSprite(0,6,(void*)lights_Sprite,OBJ_SIZE_32X16,1,4,165,55);
	PA_SetSpriteAnim (0,6,lightframe);

	PA_LoadSpritePal(0,5,(void*)music_Pal);
	PA_CreateSprite(0,7,(void*)music_Sprite,OBJ_SIZE_32X16,1,5,165,85);
	PA_SetSpriteAnim (0,7,enablemusic);

	PA_CreateSprite(0,8,(void*)music_Sprite,OBJ_SIZE_32X16,1,5,165,115);
	PA_SetSpriteAnim (0,8,enableitems);

	PA_CreateSprite(0,9,(void*)music_Sprite,OBJ_SIZE_32X16,1,5,165,145);
	
	PA_SetSpriteAnim (0,9,intmotion);

	PA_LoadSpritePal(0,6,(void*)arrowh_Pal);
	PA_CreateSprite(0,10,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,6,200,55);
	PA_SetSpriteHflip(0, 10, 1);
	

	gamedata.arrowy=55; 
	gamedata.startarrowmove=1;
	PA_WaitForVBL();PA_WaitForVBL();

	while(player.options==TRUE){
	
  
		if((Pad.Newpress.Up)||(Pad.Newpress.X))gamedata.startarrowmove-=1;
		else if((Pad.Newpress.Down)||(Pad.Newpress.B))gamedata.startarrowmove+=1;
		if(gamedata.startarrowmove<=0)gamedata.startarrowmove=1;
		else if(gamedata.startarrowmove>=6)gamedata.startarrowmove=5;

		PA_SetSpriteY(0,10,gamedata.arrowy);


		//back to menu
		if((gamedata.startarrowmove==5)&&(gamedata.arrowy!=160))gamedata.arrowy+=3;
		if((PA_SpriteTouched(0)||PA_SpriteTouched(1))&&(gamedata.arrowy!=160))gamedata.startarrowmove=5;
		if( (((Stylus.Newpress) &&((PA_SpriteTouched(0))||(PA_SpriteTouched(1))))||(Pad.Newpress.A)||(Pad.Newpress.Left||Pad.Newpress.Start))&&(gamedata.arrowy==160)){
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			
			PA_16cErase (0);
			
			PA_DeleteSprite(0,0);PA_DeleteSprite(0,1);PA_DeleteSprite(0,6);PA_DeleteSprite(0,7);PA_DeleteSprite(0,8);PA_DeleteSprite(0,9);PA_DeleteSprite(0,10);
			
			PA_WaitForVBL();
			
			for(scrollbgx=260;scrollbgx>0;scrollbgx-=6){
				PA_EasyBgScrollXY(0,1,scrollbgx,0);
				PA_WaitForVBL();
			}
			PA_DeleteBg(0,0);
			
			
			menu();
			player.options=FALSE;
			
		}
		

		//light brightness
		if((gamedata.startarrowmove==1)&&(gamedata.arrowy!=55))gamedata.arrowy-=3;
		if((PA_SpriteTouched(6) && Stylus.Newpress)&&(gamedata.arrowy!=55))gamedata.startarrowmove=1;
		if( (((Stylus.Newpress)&&(PA_SpriteTouched(6)))||Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start)&&(gamedata.arrowy==55)){
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			lightframe++;
			if(lightframe==5)lightframe=1;
			PA_SetDSLBrightness(lightframe-1);
			PA_SetSpriteAnim (0,6,lightframe);

			
		
			PA_WaitForVBL();
		}
		

		//mp3
		if((PA_SpriteTouched(7) && Stylus.Newpress)&&(gamedata.arrowy!=85))gamedata.startarrowmove=2;
		if((gamedata.startarrowmove==2)&&(gamedata.arrowy!=85)){
			if(gamedata.arrowy>85)gamedata.arrowy-=3;
			else if(gamedata.arrowy<85)gamedata.arrowy+=3;
		}	
		
		if( (((Stylus.Newpress)&&(PA_SpriteTouched(7)))||Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start)&&(gamedata.arrowy==85)){
      PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			
      char modname[20];
      sprintf(modname,"%s/mp3/song1.mp3",path);	
      FILE* modFile = fopen (modname, "rb"); 
		
      if(modFile){
        enablemusic++;
        if(enablemusic==2)enablemusic=0;
        PA_SetSpriteAnim (0,7,enablemusic);
			
        PA_WaitForVBL();
      }
		}

		//items
		if((PA_SpriteTouched(8) && Stylus.Newpress)&&(gamedata.arrowy!=115))gamedata.startarrowmove=3;
		if((gamedata.startarrowmove==3)&&(gamedata.arrowy!=115)){
			if(gamedata.arrowy>115)gamedata.arrowy-=3;
			else if(gamedata.arrowy<115)gamedata.arrowy+=3;
		}
		if( (((Stylus.Newpress)&&(PA_SpriteTouched(8)))||Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start)&&(gamedata.arrowy==115)){
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			enableitems++;
			if(enableitems==2)enableitems=0;
			PA_SetSpriteAnim (0,8,enableitems);


			PA_WaitForVBL();
		}

		//motion
		if((PA_SpriteTouched(9) && Stylus.Newpress)&&(gamedata.arrowy!=145))gamedata.startarrowmove=4;
		if((gamedata.startarrowmove==4)&&(gamedata.arrowy!=145)){
			if(gamedata.arrowy>145)gamedata.arrowy-=4;
			else if(gamedata.arrowy<145)gamedata.arrowy+=3;
		}
		if( (((Stylus.Newpress)&&(PA_SpriteTouched(9)))||Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start)&&(gamedata.arrowy==145)){
			PA_MotionInit();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			if(PA_CheckDSMotion()){
				intmotion++;
				if(intmotion==0)player.controls=FALSE;
				else if(intmotion==1){
					
					player.controls=TRUE;
				}	
		
			}

			else if(intmotion==2){
				player.controls=FALSE;
				intmotion=0;
			}
			PA_SetSpriteAnim (0,9,intmotion);


			PA_WaitForVBL();
		}



		PA_WaitForVBL();
	}

 
}

void optiondefaults(){
		//option defaults
	lightframe=1;
	enablemusic=0;
	enableitems=1;
	intmotion=0;
	//--------------
}


