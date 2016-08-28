#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"



void submitscore(){
 
   gamedata.startgame=5;
  
  char gamekey[20];

  
  char set1[]="a";
  int set2=1;
  char set3[]="c";
  int set4=2+2;
  char set5[]="l";
  
  char set6[]="e";
  int set7=5+2;
  char set8[]="g";
  int set9=3+3;
  char set10[]="sv";
  int set11=4+8;
  char set12[]="tw";
  
  sprintf(gamekey,"%s%d%s%d%s%s%d%s%d%s%d%s",set1,set2,set3,set4,set5,set6,set7,set8,set9,set10,set11,set12);	
  


  PA_EnableSpecialFx(0, SFX_ALPHA, SFX_BG2, SFX_BG3 );
  PA_SetSFXAlpha (0,11,5); 

  char *levelname = malloc(10);
  

  int score=0;
  bool transfer=FALSE;
  
  int scrollbgx;
	
  for(scrollbgx=0;scrollbgx<255;scrollbgx+=6){
       PA_EasyBgScrollXY(0,2,scrollbgx,0);
       PA_WaitForVBL();
  }
   
  
	PA_OutputText(0,0,2,"Would you like to submit your score online?\n\n L: Yes    R: No");
	
	
		switch(player.speed){
        case 1: score=player.score/5;break;
        case 2: score=player.score/4;break;
        case 3: score=player.score/3;break;
        case 4: score=player.score/2;break;
    }
	while(gamedata.startgame==5){
	
	if(Pad.Newpress.L){
	
    PA_WaitForVBL();PA_WaitForVBL();
   
   PA_ClearTextBg(0);
   
    PA_OutputText(0,0,2,"Transfering Data...");
    sprintf(levelname, "Speed_%d", player.speed);	
    
    
    PA_WaitForVBL();PA_WaitForVBL();			
		   transfer = PA_SubmitScore((void*)showscore, 	//the string the response will be copied to
												gamekey,   	//your game key
												(char*)PA_UserInfo.Name, //player name (NO SPACES - use _ instead)
												score,  		//the players score
												levelname,  		//the name of the level (NO SPACES - use _ instead)
												0			//the response type = 0 : top 10 + position; = 1 : just the position number of the score.
											);
			
			
      PA_ClearTextBg(0);
      if(transfer==TRUE){
       
        PA_SetTextCol(0, 0, 0, 0);
        PA_OutputText(0,2,7,showscore);
        PA_OutputText(0,0,2,"%c0Touch or press any button to \n continue");
      		   			   
		   	PA_WaitFor(Pad.Newpress.Anykey||Stylus.Newpress);
          PA_ClearTextBg(0);
		   
		   				for(scrollbgx=255;scrollbgx>0;scrollbgx-=6){
                PA_EasyBgScrollXY(0,2,scrollbgx,0);
                PA_WaitForVBL();
              }
         PA_DisableSpecialFx(0);
         PA_DeleteBg(0,2);
         PA_DeleteBg(0,1);
         PA_DeleteBg(0,0);
         
			PA_LoadSpritePal(0,0,(void*)retry1_Pal);
			PA_LoadSpritePal(0,1,(void*)retry2_Pal);

			
			PA_LoadSpritePal(0,2,(void*)menu1_Pal);
			PA_LoadSpritePal(0,3,(void*)menu2_Pal);
			
			PA_LoadSpritePal(0,4,(void*)arrowh_Pal);
			
			PA_LoadSpritePal(0,5,(void*)wifi1_Pal);
			PA_LoadSpritePal(0,6,(void*)wifi2_Pal);

			

			PA_CreateSprite(0,1,(void*)retry1_Sprite,OBJ_SIZE_64X32,1,0,70, 50);
			PA_CreateSprite(0,2,(void*)retry2_Sprite,OBJ_SIZE_64X32,1,1,134, 50);

			PA_CreateSprite(0,3,(void*)menu1_Sprite,OBJ_SIZE_64X32,1,2,70, 90);
			PA_CreateSprite(0,4,(void*)menu2_Sprite,OBJ_SIZE_64X32,1,3,134,90);

			PA_CreateSprite(0,6,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,4,54, 58);
			PA_CreateSprite(0,7,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,4,197, 58);
			PA_SetSpriteHflip(0, 7, 1);
			
			PA_CreateSprite(0,8,(void*)wifi1_Sprite,OBJ_SIZE_64X32,1,5,70, 130);
			PA_CreateSprite(0,9,(void*)wifi2_Sprite,OBJ_SIZE_64X32,1,6,134,130);
			
			gamedata.arrowy=58;
		
      gamedata.startgame=3;  
             
		   	
		 	}  
		 	if(!transfer)	PA_OutputText(0,0,2,"Your score was not transmitted succesfully. \n\n Please try again \n L: Yes    R: No ");
		 		
		}
	
	if(Pad.Newpress.R){
      		   
      		   	PA_ClearTextBg(0);
		   				for(scrollbgx=260;scrollbgx>0;scrollbgx-=6){
                PA_EasyBgScrollXY(0,2,scrollbgx,0);
                PA_WaitForVBL();
              }
         PA_DisableSpecialFx(0);
        
         PA_DeleteBg(0,2);
         PA_DeleteBg(0,1);
         
      PA_LoadSpritePal(0,0,(void*)retry1_Pal);
			PA_LoadSpritePal(0,1,(void*)retry2_Pal);

			
			PA_LoadSpritePal(0,2,(void*)menu1_Pal);
			PA_LoadSpritePal(0,3,(void*)menu2_Pal);
			
			PA_LoadSpritePal(0,4,(void*)arrowh_Pal);
			
			PA_LoadSpritePal(0,5,(void*)wifi1_Pal);
			PA_LoadSpritePal(0,6,(void*)wifi2_Pal);

			

			PA_CreateSprite(0,1,(void*)retry1_Sprite,OBJ_SIZE_64X32,1,0,70, 50);
			PA_CreateSprite(0,2,(void*)retry2_Sprite,OBJ_SIZE_64X32,1,1,134, 50);

			PA_CreateSprite(0,3,(void*)menu1_Sprite,OBJ_SIZE_64X32,1,2,70, 90);
			PA_CreateSprite(0,4,(void*)menu2_Sprite,OBJ_SIZE_64X32,1,3,134,90);

			PA_CreateSprite(0,6,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,4,54, 58);
			PA_CreateSprite(0,7,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,4,197, 58);
			PA_SetSpriteHflip(0, 7, 1);
			
			PA_CreateSprite(0,8,(void*)wifi1_Sprite,OBJ_SIZE_64X32,1,5,70, 130);
			PA_CreateSprite(0,9,(void*)wifi2_Sprite,OBJ_SIZE_64X32,1,6,134,130);
			
			gamedata.arrowy=58;
      gamedata.startgame=3;   

       
	}
      
      
  }
    
}

