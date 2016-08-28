#include <PA9.h> 

#include "header.h"
#include "gameeffects.h"


//transition effects

void transitionoutinvert(){
	PA_InitBgTrans(0);//initialize the screens
	PA_InitBgTrans(1);
	

	int transtype=0;
	transtype = PA_Rand()%5;//pick a random transition

	int i;
	for (i = 0; i <= TRANS_LENGTH; i++) { 
		PA_BgTransUpDown(0,transtype,1,i); 
		PA_BgTransUpDown(1,transtype,1,i); 
		PA_WaitForVBL(); 
	}
}


void transitionin(){

	PA_InitBgTrans(0);//initialize the screens
	PA_InitBgTrans(1);

	int transtype=0;
	transtype = PA_Rand()%5;//pick a random transition

	int i;

	for (i = TRANS_LENGTH; i >= 0; i--) { // Fade length...
		PA_BgTransUpDown(1,transtype,1, i);// same thing...
		PA_WaitForVBL(); // To slow down the fades, we wait a frame...
	}
	for (i = TRANS_LENGTH; i >= 0; i--) { // Fade length...
		PA_BgTransUpDown(0,transtype,1, i);// same thing...
		PA_WaitForVBL(); // To slow down the fades, we wait a frame...
	}

}	

//sine bg effect	
void HBL_function(void){

   s16 vcount = PA_GetVcount();
   vcount++;
   if(vcount >192) vcount = 0; 
   
    

  if((player.options==FALSE)||(enablemusic==0)||(startmenu==FALSE)||(gamedata.startgame==0)||(gamedata.startgame==1)||(gamedata.startgame==-2)){

      
      PA_DualEasyBgScrollX (3,(sine.x&511) + ((PA_Sin((vcount+sine.y)*sine.height+sine.add)*sine.width)>>sine.width));//both screens
      //PA_SetBgRot(0, 3,(sine.x&511) + ((PA_Sin((vcount+sine.y)*sine.height+sine.add)*sine.width)>>sine.width),0,0,0,0,256);

      

      
  }
  
} 




