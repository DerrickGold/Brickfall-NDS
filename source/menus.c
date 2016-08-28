#include <PA9.h> 

#include "header.h"
#include "gamemenus.h"
#include "multiplayertest.h"
#include "gameeffects.h"
#include "loading.h"
#include "gameplay.h"

void pausemenu(){


	PA_SetBrightness(0, -10);//change screen brightness


  			
  PA_16cText(1,104,72,255,192,"Paused",1,3, 900);

  PA_16cText(1,16,96,255,192,"Up,Down: changes background \n\n Select: changes music (MP3's)\n\n A+B+X+Y: Quit back to menu",1,2, 900);
    

    
  switch(player.speed){
      case 1:
          sprintf(showscore,"Score:%d ",player.score/5);  // String to transform
          PA_16cText(1,62,15,255,192,showscore,1,4, 900);
           
        break;

        case 2:
          sprintf(showscore,"Score:%d ",player.score/4);  // String to transform
          PA_16cText(1,62,15,255,192,showscore,1,4, 900);
           
        break;
	
        case 3:
          sprintf(showscore,"Score:%d ",player.score/3);  // String to transform
          PA_16cText(1,62,15,255,192,showscore,1,4, 900);
            
        break;

        case 4:
          sprintf(showscore,"Score:%d ",player.score/2);  // String to transform
          PA_16cText(1,62,15,255,192,showscore,1,4, 900);
            
        break;
        
    }
 

  if(enablemusic==0){
    PA_StopMod();    
    PA_PlayMod(gamepause); //play pause music
  }
  gamedata.startgame=-2;//change state to pause menu
	

  while(gamedata.startgame==-2){    
      PA_SetSoundVol(127);

  
      if(Pad.Held.A && Pad.Held.B && Pad.Held.X && Pad.Held.Y){
      
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
        PA_WaitForVBL();PA_WaitForVBL();
        transitionoutinvert();
        PA_WaitForVBL();PA_WaitForVBL();
        if(item.screen==1)PA_SwitchScreens();
        clearscreen(1);
        clearscreen(0);
        item.screen=0;
        PA_SwitchScreens();
        loadmenu();
      }
      
      //switch songs while listening  to mp3
     switch(enablemusic){
     	case 0:
				gamedata.pausetimer++;
				if(gamedata.pausetimer>=900){
					PA_PlayMod(gamepause); 
					gamedata.pausetimer=0;
			}
			break;
      case 1:
          if(Pad.Newpress.Select){
            stopmp3();
            mp3load();
          }
          if(PA_SoundChannelIsBusy(0)==FALSE)mp3load();//load new song when there is nothing playing
      break;
      

     }
     
			
			
			
			//change backgrounds when up or down is pressed
			if(Pad.Newpress.Up){
				clearscreen(1);
				clearscreen(0);

				random.oldbg++;
				intrand=1;              
        bgload(); 
        PA_WaitForVBL();PA_WaitForVBL();//prevents mp3 stuttering
        PA_WaitForVBL();PA_WaitForVBL();
        PA_WaitForVBL();PA_WaitForVBL();
        PA_WaitForVBL();PA_WaitForVBL();
        platformload(); 
        PA_ParallaxScrollY(0, gamedata.scrolly);                    
        pausemenu();    
      }
      else if(Pad.Newpress.Down){
      	clearscreen(1);
				clearscreen(0);
				random.oldbg--;
				intrand=1;
				bgload();  
				PA_WaitForVBL();PA_WaitForVBL();
				PA_WaitForVBL();PA_WaitForVBL();
        PA_WaitForVBL();PA_WaitForVBL();
        PA_WaitForVBL();PA_WaitForVBL();         				                  
        platformload();
        PA_ParallaxScrollY(0, gamedata.scrolly);
        pausemenu();
      
      }
      
      //debug testing of platforms
     /* 
     if(Pad.Newpress.B){     
        PA_DeleteBg(0,2);
        PA_DeleteBg(0,1);
        PA_DeleteBg(0,0);
				random.oldplat--;
				intrand=1;      
        platformload();         
        PA_ParallaxScrollY(0, gamedata.scrolly);  
           
      }
      if(Pad.Newpress.X){     
        PA_DeleteBg(0,2);
        PA_DeleteBg(0,1);
        PA_DeleteBg(0,0);
				random.oldplat++;
				intrand=1;      
        platformload();         
        PA_ParallaxScrollY(0, gamedata.scrolly);  
           
      }
			*/
			//return to game
			if(Pad.Newpress.Start||Pad.Newpress.L||Pad.Newpress.R ){
        if(item.screen!=1) PA_SwitchScreens();
             
        PA_DeleteBg(1,2);
        PA_DeleteBg(1,0);
        
        intrand=3;
        bgload();
        intrand=0;
        
        
        
       // PA_EasyBgLoad(1,2,scorebg);	 
				//PA_Init16cBg(1,1);  
				            
        
        if(enablemusic==0)musicload();
        PA_WaitForVBL();
				PA_SetBrightness(0,0);
				
				
				PA_WaitForVBL(); PA_WaitForVBL(); 
				gamedata.startgame=1;
				game();
			} 
			
			PA_WaitForVBL(); 
	}    

}

void loadmenu(){
  gamedata.startgame=2;
	PA_SetBrightness(0, -31);
	PA_SetBrightness(1, -31);
	title();
	PA_WaitForVBL();
	PA_SetBrightness(0, 0);
	PA_SetBrightness(1, 0);
	transitionin();
	PA_WaitForVBL();PA_WaitForVBL();
	menu();
}

void menuvars(){
	//menu settings
	volume=124;
	 gamedata.startarrowmov=0;
	 gamedata.arrowy=78;
}

void resetbuttons(){
  int done=0;
  bool reset=TRUE;
  while(reset==TRUE){
  
  		//start game sprite
		PA_SetSpriteXY(0, 2, x, y);
		PA_SetSpriteXY(0, 3, x+64, y);

    //tutorial sprites
		PA_SetSpriteXY(0, 9, x2, y2);
		PA_SetSpriteXY(0, 10, x2+64,y2);

    //option sprite
		PA_SetSpriteXY(0, 4, x3, y3);
		PA_SetSpriteXY(0, 5, x3+64, y3);
		
    done++;
  
    if(x!=70)x+=8;   
    if(x2!=70)x2+=8;
    if(x3!=70) x3+=8;
    
    if(y!=50) y+=8; 
    if(y2!=90)y2+=8;   
    if(y3!=130)y3+=8;
    
    
     if(done>40)reset=FALSE;
    
    PA_WaitForVBL();
  }
 
}
  
    

void menu(){

  startmenu=TRUE;
	
	PA_LoadSpritePal(0,0,(void*)start1_Pal);
	PA_LoadSpritePal(0,1,(void*)start2_Pal);

	PA_LoadSpritePal(0,2,(void*)op1_Pal);
	PA_LoadSpritePal(0,3,(void*)op2_Pal);

	PA_LoadSpritePal(0,4,(void*)arrowh_Pal);
	
	
	PA_LoadSpritePal(0,6,(void*)tut1_Pal);
	PA_LoadSpritePal(0,7,(void*)tut2_Pal);
	
	player.y=30;
	player.x=124;
	

	PA_CreateSprite(0,2,(void*)start1_Sprite,OBJ_SIZE_64X32,1,0,x, y);
	PA_CreateSprite(0,3,(void*)start2_Sprite,OBJ_SIZE_64X32,1,1,x+64, y);
	
	PA_CreateSprite(0,9,(void*)tut1_Sprite,OBJ_SIZE_64X32,1,6,x2, y2);
	PA_CreateSprite(0,10,(void*)tut2_Sprite,OBJ_SIZE_64X32,1,7,x2+64, y2);

	PA_CreateSprite(0,4,(void*)op1_Sprite,OBJ_SIZE_64X32,1,2,x3, y3);
	PA_CreateSprite(0,5,(void*)op2_Sprite,OBJ_SIZE_64X32,1,3,x3+64, y3);
	
	

	PA_CreateSprite(0,6,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,4,54, 58);
	PA_CreateSprite(0,7,(void*)arrowh_Sprite,OBJ_SIZE_16X16,1,4,197, 58);
	PA_SetSpriteHflip(0, 7, 1); 

	PA_SetSoundVol(127); 

	PA_InitAllSpriteDraw(); 
	
	gamedata.startarrowmov=2;

	gamedata.arrowy=58;
	int menumove=0;
	
  resetbuttons();


	PA_WaitForVBL();PA_WaitForVBL();

	while(startmenu==TRUE){


		PA_SetSpriteY(0,6,gamedata.arrowy);
		PA_SetSpriteY(0,7,gamedata.arrowy);
		
		//start game sprite
		PA_SetSpriteXY(0, 2, x, y);
		PA_SetSpriteXY(0, 3, x+64, y);

    //tutorial sprites
		PA_SetSpriteXY(0, 9, x2, y2);
		PA_SetSpriteXY(0, 10, x2+64, y2);

    //option sprite
		PA_SetSpriteXY(0, 4, x3, y3);
		PA_SetSpriteXY(0, 5, x3+64, y3);

    
    
		if(Pad.Newpress.Up||Pad.Newpress.X)gamedata.startarrowmov-=1;
		else if(Pad.Newpress.Down||Pad.Newpress.B)gamedata.startarrowmov+=1;
		if(gamedata.startarrowmov==5)gamedata.startarrowmov=4;
		else if(gamedata.startarrowmov==1)gamedata.startarrowmov=2;


		
  //start game
		if(((PA_SpriteTouched(2)||PA_SpriteTouched(3)))&&(gamedata.arrowy!=58))gamedata.startarrowmov=2;

		if((gamedata.startarrowmov==2)&&(gamedata.arrowy!=58)){
			if(gamedata.arrowy>58)gamedata.arrowy-=4;
			else if(gamedata.arrowy<58)gamedata.arrowy+=4;
		}

		if(((PA_SpriteTouched(2)||PA_SpriteTouched(3))||(Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start))&&(gamedata.arrowy==58)){
			PA_PlaySimpleSound(15,button);
			gamedata.startarrowmov=-2;
			gamedata.arrowy=-20;
			menumove=1;			
		}
		//tutorial
		if(((PA_SpriteTouched(9)||PA_SpriteTouched(10)))&&(gamedata.arrowy!=98))gamedata.startarrowmov=3;

		if((gamedata.startarrowmov==3)&&(gamedata.arrowy!=98)){
			if(gamedata.arrowy>98)gamedata.arrowy-=4;
			else if(gamedata.arrowy<98)gamedata.arrowy+=4;
		}

		if(((PA_SpriteTouched(9)||PA_SpriteTouched(10))||(Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start))&&(gamedata.arrowy==98)){
			PA_PlaySimpleSound(15,button);
			clearspritesys();
			PA_WaitForVBL();
			PA_DeleteBg(0,1);
			PA_WaitForVBL();
			transitionoutinvert();
			PA_WaitForVBL();PA_WaitForVBL();
			clearscreen(1);
			clearscreen(0);
			tutorial();
			
		}
//options
		if(((PA_SpriteTouched(4)||PA_SpriteTouched(5)))&&(gamedata.arrowy!=138))gamedata.startarrowmov=4;

		if((gamedata.startarrowmov==4)&&(gamedata.arrowy!=138)){
			if(gamedata.arrowy>138)gamedata.arrowy-=4;
			else if(gamedata.arrowy<138)gamedata.arrowy+=4;
		}

		if(((PA_SpriteTouched(4)||PA_SpriteTouched(5))||(Pad.Newpress.A||Pad.Newpress.Left||Pad.Newpress.Start))&&(gamedata.arrowy==138)){
			PA_PlaySimpleSound(15,button);
		 PA_DeleteSprite(0,6);
			PA_DeleteSprite(0,7);
			menumove=3;
			
		}
		
		
//multiplayer
/*
if(Pad.Newpress.Select){
  PA_PlaySimpleSound(15,button);
	gamedata.startarrowmov=-2;
	gamedata.arrowy=-20;
	menumove=4;		
  	
}	
*/	
		
//button movements

    //start game--------------------------
    if(menumove==1){
      gamedata.startarrowmov=-2;
			gamedata.arrowy=-20;
    
    //move sprites to positions
      //start game
      if(x>12){
        x-=8;
        //x2-=8;
      }
      if(y>20){
       // y2-=8;
        y-=8;
      }

      x2-=8;//x4-=8;//tutorial 
      x3-=8;//x6-=8;//option

    

      if((x2+135<=0)&&(x3+135<=0)){  
 
        int scrollbgx;
	
        for(scrollbgx=0;scrollbgx<255;scrollbgx+=6){
          PA_EasyBgScrollXY(0,1,scrollbgx,0);
          PA_WaitForVBL();
        }
        menumove=0;
        //resetgame();
        gamespeed();
     }
   }
    
    //options---------------------------------
    if(menumove==3){
    //option
      if(x3>12){
        x3-=8;
        //x6-=8;
      }
      if(y3>20){
        y3-=8;
        //y6-=8;
      }
      
      x-=8;//x2-=8;//start game 
      x2-=8;//x4-=8;//tutorial
     if((x+135<=0)&&(x2+135<=0)){ 
      menumove=0;
      options();
     }
    }
    
    
    //multiplayer-----------------------
    if(menumove==4){
      gamedata.startarrowmov=-2;
			gamedata.arrowy=-20;
    
    //move sprites to positions
      //start game
      if(x>12){
        x-=8;
        //x2-=8;
      }
      if(y>20){
       // y2-=8;
        y-=8;
      }

      x2-=8;//x4-=8;//tutorial 
      x3-=8;//x6-=8;//option

 

      if((x2+135<=0)&&(x3+135<=0)){
    
   
        int scrollbgx;
	
        for(scrollbgx=0;scrollbgx<255;scrollbgx+=6){
          PA_EasyBgScrollXY(0,1,scrollbgx,0);
          PA_WaitForVBL();
        }
      menumove=0;
      
      multimenu();
      }
    }



		PA_WaitForVBL();
		
	}
}


