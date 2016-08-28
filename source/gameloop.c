#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"
#include "loading.h"
#include "gameplay.h"
#include "gameitems.h"
#include "gameeffects.h"
#include "collision.h"




void game(){


  	

	while(gamedata.startgame==1){	
	
    
	
		if(enablemusic==1){
      if(soundsystem->state == STOPPED)PA_ResumeMP3(); 
      
    }//mp3 streaming while loading fat
    //else sine.add+=4; sine.add&= 511;//sine bg movement
    
    gamedata.scrolly+=player.platspeed;
    
    
    //scroll the platforms     
    
    		
		PA_SetSpriteXY(0,0,player.x,player.y);// sets the players x & y position
    PA_ParallaxScrollY(0, gamedata.scrolly);
    
    switch(player.speed){
		
    case 1:
    
      if(gamedata.startgame!=-2){
        sprintf(showscore,"Score:%d ",player.score/5);  // String to transform		
        PA_16cText(1,62,85,255,192,showscore,1,4, 900);//print score on top screen
      }	

     //||((gamedata.scrolly>=1121)&&(player.y>=115)))
      //if platform reaches the end
			if(gamedata.scrolly>=1246){
				PA_DeleteBg(0,2);		//delete the platform	
				PA_DeleteBg(0,1);
				PA_DeleteBg(0,0);
				
				gamedata.scrolly=100;//change the scroll position back       
				platformload();//load platform
				if(PA_SoundChannelIsBusy(0)==FALSE) mp3load();//if mp3 enabled and there is no music, load a new mp3
				      
 				if(enablemusic==0){//if mod timer reaches the end
            if(PA_SoundChannelIsBusy(0)==FALSE && PA_SoundChannelIsBusy(1)==FALSE && PA_SoundChannelIsBusy(2)==FALSE)musicload();
						
        }   
			}
			
			
			
      break;
		
	

      case 2:

        if(gamedata.startgame!=-2){
          sprintf(showscore,"Score:%d ",player.score/4);  // String to transform
          PA_16cText(1,62,85,255,192,showscore,1,4, 900);//print score on top screen
        }
           
        //||((gamedata.scrolly>=975)&&(player.y>=115)))
        //if platform reaches the end
        if(gamedata.scrolly>=1100){
				PA_DeleteBg(0,2);//delete the platform
				PA_DeleteBg(0,1);
				PA_DeleteBg(0,0);
				
				gamedata.scrolly=95;//change the scroll position back
				platformload();//load platform
				
				if(enablemusic==0){//if mod timer reaches the end
            if(PA_SoundChannelIsBusy(0)==FALSE && PA_SoundChannelIsBusy(1)==FALSE && PA_SoundChannelIsBusy(2)==FALSE)musicload();
						
        }   
					
			} 
      break;     			
   
      

      case 3:
	
        if(gamedata.startgame!=-2){
          sprintf(showscore,"Score:%d ",player.score/3);  // String to transform
          PA_16cText(1,62,85,255,192,showscore,1,4, 900);//print score on top screen
        }
			

        //||((gamedata.scrolly>=1525)&&(player.y>=115)))
        //if platform reaches the end
        if(gamedata.scrolly>=1650){
				PA_DeleteBg(0,2);//delete the platform
				PA_DeleteBg(0,1);
				PA_DeleteBg(0,0);

         
				gamedata.scrolly=150;//change the scroll position back
				platformload();//load platform
     
        if(enablemusic==0){//if mod timer reaches the end
            if(PA_SoundChannelIsBusy(0)==FALSE && PA_SoundChannelIsBusy(1)==FALSE && PA_SoundChannelIsBusy(2)==FALSE)musicload();
						
        }   
			}	
      break;		
		

      case 4:
		 
        if(gamedata.startgame!=-2){ 
          sprintf(showscore,"Score:%d ",player.score/2);  // String to transform
          PA_16cText(1,62,85,170,170,showscore,1,4, 900);//print score on top screen
        }

     
        //||((gamedata.scrolly>=1725)&&(player.y>=115)))
        //if platform reaches the end
        if(gamedata.scrolly>=1850){
				PA_DeleteBg(0,2);//delete the platform
				PA_DeleteBg(0,1);
				PA_DeleteBg(0,0);
				
       	gamedata.scrolly=100;//change the scroll position back
				platformload();//load platform
				
				if(enablemusic==0){//if mod timer reaches the end
            if(PA_SoundChannelIsBusy(0)==FALSE && PA_SoundChannelIsBusy(1)==FALSE && PA_SoundChannelIsBusy(2)==FALSE)musicload();
						
        }        
			}	
			
      break;
		
      
		
		}
    
   // PA_ParallaxScrollY(0, gamedata.scrolly);
    
    
  

    //if player dies
		if(player.y<=0){
      //reset item variables
			item.time=0;
			item.number=0;
			item.movement=FALSE;
			//stop music
			if(enablemusic==0)PA_StopMod();
			else stopmp3();
        			
			//clear the screen
			clearspritesys();
			PA_DeleteBg(0,2);
			PA_WaitForVBL();
			transitionoutinvert();
			PA_WaitForVBL();PA_WaitForVBL();
			if(item.screen==1)PA_SwitchScreens();
			clearscreen(1);
			clearscreen(0);
			item.screen=0;
			gamedata.startgame=-1;//gameover screen
			gameover();
						
		}
		

		//item counter---------------------
		//decides when an item should appear
		if(enableitems==1){
			if(item.movement==FALSE){
			
				item.x=PA_Rand()%256-16;
				item.y=-16;

				int timecheck=PA_RandMinMax(250,900);

				if(item.time<timecheck)item.time++;
				else if(item.time>=timecheck)createitems();
			}
		}

		//----------------------------------
		
		
		
		
				//pause button		
		if(Pad.Newpress.Start||Pad.Newpress.L||Pad.Newpress.R){
		
        if(enablemusic==0)PA_StopMod();
        PA_WaitForVBL();PA_WaitForVBL(); 
        if(item.screen!=1)PA_SwitchScreens();
        PA_16cErase (1);
			 
        PA_DeleteBg(1,2);
        PA_DeleteBg(1,1);
         
        intrand=2;
        bgload();
        intrand=0;
        PA_WaitForVBL(); PA_WaitForVBL();  
        pausemenu();
		}
			
    checkcontrolls();//checks the controls, if pressed do action
    
    player.score++;//add to score
  
    
    if(enableitems==1){
      itemhandling();
      
      if(item.number!=2){
       
        CheckCollisions();
      }
    }
    else CheckCollisions();
    
    PA_CheckLid();
    PA_WaitForVBL();
    refreshscore();
 }   
     
}


			
void gameover(){//game over screen

	gamedata.startarrowmov=1;//first state of the arrows	
	
	//clears backgrounds
	clearscreen(1);
	clearscreen(0);

  //deletes the sprites used
	PA_DeleteSprite (0,0);
	PA_DeleteSprite (0,1);
	PA_DeleteSprite (0,8);

	//transition to the gameover screens
	PA_SetBrightness(1, -31);
	PA_SetBrightness(0, -31);
	PA_Init16cBg(1, 1);
	PA_EasyBgLoad(1, 2, youlose);
	PA_SetBgColor (0,PA_RGB(5, 6, 17)); 
	PA_PlayMod(gamedone); 
	PA_WaitForVBL();
	PA_SetBrightness(1, 0);
	PA_SetBrightness(0, 0);
	transitionin();
	PA_WaitForVBL();

	//show score
	switch(player.speed){
    case 1:
      sprintf(showscore,"%d ",player.score/5);  // String to transform
      PA_16cText(1,150,147,255,192,showscore,1,4, 900);
      break;

    case 2:
      sprintf(showscore,"%d ",player.score/4);  // String to transform
      PA_16cText(1,150,147,255,192,showscore,1,4, 900);
      break;
	

    case 3:
      sprintf(showscore,"%d ",player.score/3);  // String to transform
      PA_16cText(1,150,147,255,192,showscore,1,4, 900);
      break;

    case 4:
      sprintf(showscore,"%d ",player.score/2);  // String to transform
      PA_16cText(1,150,147,255,192,showscore,1,4, 900);
      break;
  }
	PA_WaitForVBL();
	
  //load sprites for gameover screen
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
			
	gamedata.arrowy=58;//arrow positions
	gamedata.startgame=3;//change state to game over
	
	
	while(gamedata.startgame==3){
	
      if(Pad.Newpress.Up||Pad.Newpress.X)gamedata.startarrowmov-=1;
      else if(Pad.Newpress.Down||Pad.Newpress.B)gamedata.startarrowmov+=1;
      if(gamedata.startarrowmov>=4)gamedata.startarrowmov=3;
      else if(gamedata.startarrowmov<=0)gamedata.startarrowmov=1;

			PA_SetSpriteY(0,6,gamedata.arrowy);
			PA_SetSpriteY(0,7,gamedata.arrowy);
			
			//retry----------------------------------------------

			if((((PA_SpriteTouched(1)||PA_SpriteTouched(2))))&&(gamedata.arrowy!=58))gamedata.startarrowmov=1;

			if((gamedata.startarrowmov==1)&&(gamedata.arrowy!=58)){
          if(gamedata.arrowy>58)gamedata.arrowy-=4;
          if(gamedata.arrowy<58)gamedata.arrowy+=4;
      }

			if(((PA_SpriteTouched(1)||PA_SpriteTouched(2))||(Pad.Newpress.A)||(Pad.Newpress.Left)||(Pad.Newpress.Start))&&(gamedata.arrowy==58)){
				PA_PlaySimpleSound(15,button);
				clearspritesys();
				PA_WaitForVBL();
				PA_WaitForVBL();
				transitionoutinvert();
			
				resetgame();
				
			}
			
			//back to menu---------------------------------------------------------------
		

			if((((PA_SpriteTouched(3)||PA_SpriteTouched(4))))&&(gamedata.arrowy!=98))gamedata.startarrowmov=2;

			if((gamedata.startarrowmov==2)&&(gamedata.arrowy!=98)){
					if(gamedata.arrowy>98)gamedata.arrowy-=4;
          if(gamedata.arrowy<98)gamedata.arrowy+=4;
      }

			if(((PA_SpriteTouched(3)||PA_SpriteTouched(4))||(Pad.Newpress.A)||(Pad.Newpress.Left)||(Pad.Newpress.Start))&&(gamedata.arrowy==98)){
				PA_PlaySimpleSound(15,button);
				clearspritesys();
				PA_WaitForVBL();
				PA_WaitForVBL();
				transitionoutinvert();
				clearscreen(1);
				clearscreen(0);
				
				
				loadmenu();
			}
			
			//wifi menu-------------------------------------------------------------

      if((((PA_SpriteTouched(8)||PA_SpriteTouched(9))))&&(gamedata.arrowy!=138))gamedata.startarrowmov=3;

			if((gamedata.startarrowmov==3)&&(gamedata.arrowy!=138)){
				if(gamedata.arrowy>138)gamedata.arrowy-=4;
        if(gamedata.arrowy<138)gamedata.arrowy+=4;
      }

			if(((PA_SpriteTouched(8)||PA_SpriteTouched(9))||(Pad.Newpress.A)||(Pad.Newpress.Left)||(Pad.Newpress.Start))&&(gamedata.arrowy==138)){ 
        PA_PlaySimpleSound(15,button);
        clearspritesys();
        PA_EasyBgLoad(0, 2,optionbg);
        
        PA_InitText(0,0);
        
       
        submitscore();
      }
      
      PA_WaitForVBL();
      
  }
	
}


