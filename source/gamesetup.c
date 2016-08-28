
#include <PA9.h> 

#include "header.h"
#include "loading.h"
#include "gameplay.h"
#include "gameeffects.h"

void gamespeed(){
  PA_Init16cBg (0,0);
 
	player.speed=2;

  startmenu=FALSE;
	startspeed=TRUE;

	
	PA_16cText(0,30, 60,180, 162,"Please select a speed. \n\n The speed relects how fast the platforms move, the higher the speed, the faster.\n\nPlease pick a character, tap the icon to choose.",1,2,300);

	PA_LoadSpritePal(0,2,(void*)speedspri_Pal);
	PA_CreateSprite(0,4,(void*)speedspri_Sprite,OBJ_SIZE_32X32,1,2,200,72);

	PA_LoadSpritePal(0,3,(void*)arrow_Pal);
	PA_CreateSprite(0,5,(void*)arrow_Sprite,OBJ_SIZE_16X16,1,3,200,56);
	PA_CreateSprite(0,6,(void*)arrow_Sprite,OBJ_SIZE_16X16,1,3,200,90);
	
	PA_LoadSpritePal(0,10,(void*)arrowh_Pal);

	PA_LoadSpritePal(0,4,(void*)go1_Pal);
	PA_LoadSpritePal(0,5,(void*)go2_Pal);
	
	PA_CreateSprite(0,7,(void*)go1_Sprite,OBJ_SIZE_64X32,1,4,70,160);
	PA_CreateSprite(0,8,(void*)go2_Sprite,OBJ_SIZE_64X32,1,5,134,160);

	PA_CreateSprite(0,9,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,10,54, 168);
	PA_CreateSprite(0,10,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,10,197,168);
	PA_SetSpriteHflip(0, 9, 1); 
	
	

	
  loadsprite();

	PA_SetSpriteRotEnable(0,12,0);
	PA_SetSpriteDblsize (0,12,1);
	PA_SetRotsetNoAngle(0,0,128,128);


	PA_SetSpriteVflip(0,6,1);
	PA_WaitForVBL();PA_WaitForVBL();
	
	
	
	while(startspeed==TRUE){
		
		//speed up
		if ((Pad.Newpress.Up||Pad.Newpress.X)||((Stylus.Newpress)&&(PA_SpriteTouched(5)))){
		PA_WaitForVBL();PA_WaitForVBL();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			player.speed++;
		}
		//speed down
		else if ((Pad.Newpress.Down||Pad.Newpress.B)||((Stylus.Newpress)&&(PA_SpriteTouched(6)))){
		PA_WaitForVBL();PA_WaitForVBL();
			PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			player.speed--;
		}
		if (player.speed==0)player.speed++;
		else if (player.speed==5)player.speed--;//add one more to 4 to enable speed 4
		
		PA_SetSpriteAnim (0,4,player.speed-1);
	
    //start game
		if((Pad.Newpress.A)||(Pad.Newpress.Left||Pad.Newpress.Start)||(PA_SpriteTouched(7)||PA_SpriteTouched(8))){
      PA_WaitForVBL();PA_WaitForVBL();
      PA_StopSound(15);
			PA_PlaySimpleSound(15,button);
			clearspritesys();
			PA_DeleteBg(0,0);
			PA_DeleteBg(0,1);
			PA_WaitForVBL();
			transitionoutinvert();
			clearscreen(1);
			clearscreen(0);
			PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
			PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
			startspeed=FALSE;
			resetgame();		
		}
		//character selecter
	else if((Stylus.Newpress)&&(PA_SpriteTouchedEx(12,16,16))){
       PA_StopSound(15);
       PA_PlaySimpleSound(15,button);
       player.skin++;
       if(player.skin == 9)player.skin=0;
       PA_SetSpriteAnim(0,12,player.skin);
       PA_WaitForVBL();	
    }
    
		PA_WaitForVBL();
	}
}

void resetgame(){

  gamedata.startgame=0;
	PA_DisableSpecialFx(0);
	startspeed=FALSE;
	startmenu=FALSE;
	
	player.score=0;
	gamedata.scrolly=0;
	player.y=50;
	player.x=120;
	item.time=0;
	item.slomo=0;
	item.screen=0;
	
	
	//defines the speed of the platforms 
	switch(player.speed){
    case 1: player.platspeed=1; break;
    case 2: player.platspeed=1; break;
    case 3: player.platspeed=2; break;
    case 4: player.platspeed=3; break;
  }

  
  
  
  
	PA_SetBrightness(0, -31);
	PA_SetBrightness(1, -31);
	clearscreen(1);
	clearscreen(0);
	clearspritesys();
	
  PA_EasyBgLoad(1,2,scorebg);
  
  loadsprite();
  intrand=0;
	bgload();
	
  PA_WaitForVBL();PA_WaitForVBL();//prevents background corruption
  PA_WaitForVBL();PA_WaitForVBL();
  PA_WaitForVBL();PA_WaitForVBL();
  PA_WaitForVBL();PA_WaitForVBL();	
  
	platformload();
	

	PA_SetBrightness(1, 0);
	PA_SetBrightness(0, 0);
	transitionin();

	
	
  PA_StopMod();
	volume=127;
	
  if(enablemusic==0)musicload();
	else mp3load();

	
	gamedata.startgame=1;
	game();

}








