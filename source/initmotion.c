#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"
#include "gameeffects.h"


//loads motion splash screens
void motionint(){

  startmenu=TRUE;

	PA_SetBrightness(0, -31);
	PA_SetBrightness(1, -31);
	//PA_LoadGif (1, (void *)motion);
	//PA_LoadGif (0, (void *)fdbottom);
	PA_EasyBgLoad(1, 2,motion);
	PA_EasyBgLoad(0, 2,fdbottom);
	PA_WaitForVBL();
	PA_SetBrightness(0, 0);
	PA_SetBrightness(1, 0);
	transitionin();
	PA_WaitFor((Pad.Newpress.Anykey)||(Stylus.Newpress));
	PA_WaitForVBL();
	transitionoutinvert();
	
	//button x & y position
 x=70; y=50;
 x2=70; y2=90;
 x3=70; y3=130;

}






