#include <PA9.h> 

#include "header.h"

void clearscreen(bool screen){//deletes all backgrounds on selected screen

	u8 i;
	for(i=0;i<3;i++){
    PA_DeleteBg(screen,i);
  }
	PA_ResetBgSysScreen(screen);
	
}

void clearspritesys(){//deletes all sprites on bottom screen

  int i;
	for(i=-1;i<15;i++){
		PA_DeleteSprite (0,i);	
	}
	PA_ResetSpriteSys();
}

void refreshscore(){
	if(gamedata.startgame==1)PA_16cErase (1);
	//PA_Init16cBg(1, 1);

}

