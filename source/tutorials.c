#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"
#include "gameeffects.h"


void tutorial(){

  startmenu=FALSE;
	PA_SetBrightness(0, -31);
	PA_SetBrightness(1, -31);
	
 	PA_EasyBgLoad(1, 2,tuttopsc);
	PA_EasyBgLoad(0, 2,tutbotsc);
	
	PA_WaitForVBL();
	PA_SetBrightness(0, 0);
	PA_SetBrightness(1, 0);
	transitionin();
	PA_WaitFor((Pad.Newpress.Anykey)||(Stylus.Newpress));
	PA_WaitForVBL();
	
	PA_EasyBgLoad(1, 2,creditstop);
	PA_EasyBgLoad(0, 2,credits);
	
	PA_WaitFor((Pad.Newpress.Anykey)||(Stylus.Newpress));
	PA_WaitForVBL();
	transitionoutinvert();
	loadmenu();
}

