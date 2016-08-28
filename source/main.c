// Includes
#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"

#include "gameitems.h"
#include "gameplay.h"
#include "gameeffects.h"

#include "gfx/all_gfx.c"
#include <fat.h>
#include <sys/dir.h>



void PA_Shutdown()//shuts off DS
{
IPC->aux |= BIT(6); // libnds arm7 code: #define PM_POWER_DOWN BIT(6)
}


// Function: main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
	PA_InitText(1,0);
	PA_InitSound();
	PA_SetSoundVol(50);
	PA_InitWifi();
	PA_InitRand();
	
	if(!fatInitDefault()){
    PA_InitText(1,0);
    PA_OutputText(1,6,10,"Error Card not detected \n Check DLDI settings");
    PA_WaitFor(Pad.Newpress.Anykey || Stylus.Newpress);
    PA_Shutdown();
  }
  
  PA_OutputText(1,6,10,"Scanning For Folder...");
  fileLocator("/","brickfall",true,10, path);
  //DIR_ITER* dir = diropen("/brickfall/");

	if (fileLocator==FALSE){
    PA_InitText(1,0);
    PA_OutputText(1,6,10,"Error, Folder not found! \nPlease make sure the \n'brickfall' directory\nis on your \ncard.");
    PA_WaitFor(Pad.Newpress.Anykey || Stylus.Newpress);
    PA_Shutdown();
  }
  PA_ClearTextBg(1);
  
  irqSet(IRQ_HBLANK, HBL_function);
	irqEnable(IRQ_HBLANK);

	if (PA_InitMP3()){
		PA_OutputText(0, 1, 1, "Couldn't init the mp3 decoder");
		while (1)
			PA_WaitForVBL();
	}
	
	//sine bg vars
  sine.width = 0;
	sine.height = 0;
	item.xaxis=0;

 // PA_SRand (PA_RTC.Seconds);

	motionint();
	optiondefaults();
	menuvars();
	PA_WaitForVBL();PA_WaitForVBL();
	loadmenu();	
   	
	// Infinite loop to keep the program running
	while (1)
	{
	

		
    
		PA_WaitForVBL();
		
		
		
		
	}
	
	return 0;
} 



