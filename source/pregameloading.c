#include <PA9.h> 

#include "header.h"
#include "loading.h"
#include "gameeffects.h"
#include <fat.h>
#include <sys/dir.h>




FILE* infile;




//loads sprite and sets skin
void loadsprite(){

  char pathbuf[20];
  
  if(startspeed==TRUE){
       player.y=134;
       player.x=200;
      
      PA_CreateSprite(0,12,(void*)cyan_Sprite,OBJ_SIZE_8X8,1,14,player.x, player.y);
      PA_LoadSpritePal(0,14,(void*)cyan_Pal);
      PA_SetSpriteAnim(0,12,player.skin);
   }
   else if(startspeed==FALSE){
        player.y=50;
        player.x=120;
            
       PA_CreateSprite(0,0,(void*)cyan_Sprite,OBJ_SIZE_8X8,1,0,player.x, player.y);
       PA_LoadSpritePal(0,0,(void*)cyan_Pal);
       PA_SetSpriteAnim(0,0,player.skin);
       
       
       sprintf(pathbuf,"%s/platforms",path);
       random.maxplatform=(countfiles(pathbuf)-4)/4;//counts platform files
       sprintf(pathbuf,"%s/bgs",path);
      // maxbg=(countfiles(pathbuf)-4)/4; tiles
          maxbg=(countfiles(pathbuf)); //gifs

       

   }																													
  


}

    
void platformload(){	//loads a random platform

  loadplatforms=1;
  
  
  while(loadplatforms==1){


		
    char platname[512];   
    level= PA_RandMinMax(0,random.maxplatform);
    
    if(level==random.oldplat)level= PA_RandMinMax(0,random.maxplatform+1);//if the platform pick was the same as last time, pick another one
    else if(level==random.oldplat)level= PA_RandMinMax(0,random.maxplatform+1);//does that twice
     
   switch(intrand){
    case 0:
      sprintf(platname,"%s/platforms/level%d_Info.bin",path,level);
      PA_WaitForVBL();PA_WaitForVBL();
    break;
  
    case 1:     
      sprintf(platname,"%s/platforms/level%d_Info.bin",path,random.oldplat);
      PA_WaitForVBL();PA_WaitForVBL();
    break;  
      
     }
    

    if(soundsystem->state == PLAYING){ 
     soundsystem->sendFIFO = false;
     PA_WaitForVBL();	// hopefully the large buffer manages this ... if not, make it bigger or try with only one WaitForVBL()
    }		
     
     
    //load info file---------------------------------------------------

    FILE* infoFile = fopen(platname,"rb"); 

         
    int infoSize;
    fseek (infoFile , 0 , SEEK_END);
    infoSize = ftell (infoFile);
    rewind (infoFile); 

    char *infobuffer;          
    infobuffer = (char*) malloc (sizeof(char)*infoSize);
    fread ((void*)infobuffer,1,infoSize,infoFile);  
    fclose (infoFile);		
    
    switch(intrand){
      case 0:
        sprintf(platname,"%s/platforms/level%d_Tiles.bin",path,level);
      break; 
    
      case 1:
        sprintf(platname,"%s/platforms/level%d_Tiles.bin",path,random.oldplat);
      break;
    }
      
    //load tiles file---------------------------------------------------

    FILE* tileFile = fopen(platname,"rb");      
    int tileSize;
    fseek (tileFile , 0 , SEEK_END);
    tileSize = ftell (tileFile);
    rewind (tileFile);  

    char *tilebuffer;     
    tilebuffer = (char*) malloc (sizeof(char)*tileSize);
    fread ((void*)tilebuffer,1,tileSize,tileFile);  
    fclose (tileFile);

    switch(intrand){
      case 0:
        sprintf(platname,"%s/platforms/level%d_Map.bin",path,level);
      break;
    
      case 1:
        sprintf(platname,"%s/platforms/level%d_Map.bin",path,random.oldplat);
      break;
    }
    
    //load map file---------------------------------------------------
       
    FILE* mapFile = fopen(platname,"rb");      
    int mapSize;
    fseek (mapFile , 0 , SEEK_END);
    mapSize = ftell (mapFile);
    rewind (mapFile); 
    
    char *mapbuffer;     
    mapbuffer = (char*) malloc (sizeof(char)*mapSize);
    fread ((void*)mapbuffer,1,mapSize,mapFile);  
    fclose (mapFile);
  
    switch(intrand){
      case 0:
        sprintf(platname,"%s/platforms/level%d_Pal.bin",path,level);  
      break;
    
      case 1:
        sprintf(platname,"%s/platforms/level%d_Pal.bin",path,random.oldplat);
      break;
      
    } 
    //load palette file---------------------------------------------------
                 
    FILE* palFile = fopen(platname,"rb");      
    int palSize;
    fseek (palFile , 0 , SEEK_END);
    palSize = ftell (palFile);
    rewind (palFile); 
      
    char *palbuffer;         
    palbuffer = (char*) malloc (sizeof(char)*palSize);
    
    PA_WaitForVBL();
    
    fread ((void*)palbuffer,1,palSize,palFile);  
    fclose (palFile);
    
    if(soundsystem->state == PLAYING){ 
       soundsystem->sendFIFO = true;
       
       PA_WaitForVBL();
    }

    PA_EasyBgLoadEx(0,2,(void *)infobuffer,(void *)tilebuffer,tileSize,(void *)mapbuffer,mapSize,(void*)palbuffer);
    
  
   if(intrand==0) random.oldplat=level;//old platform now equals new platform to check again next time a platform needs to be loaded
   intrand=0;
     
   loadplatforms=0;
     
  }
}

int countfiles(char* directory){//counts files in a directory

  	DIR_ITER* dir = diropen((char*)directory);
  	
    struct stat st;
    char files;
    int filenum=0;
    while (dirnext(dir, files, &st) == 0) filenum++;
    
    return(filenum-2);//returns files no directories
}

//tiled Backgrounds
/*
void bgload(){

    char bgname[512];

   if(enablemusic==0){
      int intensity=PA_RandMinMax(0,15);
      sine.width=intensity;
      sine.height=intensity;
    }
    else{
      sine.width=0;
      sine.height=0;
   }
       
    
    background=PA_RandMinMax(1,maxbg+1);
    
    if(background==random.oldbg)background= PA_RandMinMax(1,maxbg+1);//if the platform pick was the same as last time, pick another one
    else if(background==random.oldbg)background= PA_RandMinMax(1,maxbg+1);//does that twice
     
    
    if(random.oldbg>maxbg+1)random.oldbg=1;
    else if(random.oldbg<1)random.oldbg=maxbg+1;

    switch(intrand){
      case 0:
        sprintf(bgname,"%s/bgs/bg%d_Info.bin",path,background);
      break;
      
      case 1:
        sprintf(bgname,"%s/bgs/bg%d_Info.bin",path,random.oldbg);  
      break;
    }
    
	  if(soundsystem->state == PLAYING){ 
     soundsystem->sendFIFO = false;
     PA_WaitForVBL();	// hopefully the large buffer manages this ... if not, make it bigger or try with only one WaitForVBL()
    }	
    //load info file---------------------------------------------------
           
    FILE* infoFile = fopen(bgname,"rb");      
    int infoSize;
    fseek (infoFile , 0 , SEEK_END);
    infoSize = ftell (infoFile);
    rewind (infoFile); 

    char *infobuffer;              
    infobuffer = (char*) malloc (sizeof(char)*infoSize);

    fread ((void*)infobuffer,1,infoSize,infoFile);  
    fclose (infoFile);		
        
   // PA_WaitForVBL();PA_WaitForVBL();       
    
    switch(intrand){  
      case 0:
        sprintf(bgname,"%s/bgs/bg%d_Tiles.bin",path,background);
      break;
    
      case 1:     
        sprintf(bgname,"%s/bgs/bg%d_Tiles.bin",path,random.oldbg);  
      break;
    }
    
    //load tiles file---------------------------------------------------
             
    FILE* tileFile = fopen(bgname,"rb");      
    int tileSize;
    fseek (tileFile , 0 , SEEK_END);
    tileSize = ftell (tileFile);
    rewind (tileFile);  

    char *tilebuffer;       
    tilebuffer = (char*) malloc (sizeof(char)*tileSize);

    fread ((void*)tilebuffer,1,tileSize,tileFile);  
    fclose (tileFile);
            

    switch(intrand){
      case 0:
        sprintf(bgname,"%s/bgs/bg%d_Map.bin",path,background);
      break;
      
      case 1:
        sprintf(bgname,"%s/bgs/bg%d_Map.bin",path,random.oldbg);  
      break;
    }
            
    //load map file---------------------------------------------------
       
    FILE* mapFile = fopen(bgname,"rb");      
    int mapSize;
    fseek (mapFile , 0 , SEEK_END);
    mapSize = ftell (mapFile);
    rewind (mapFile); 
  
    char *mapbuffer;      
    mapbuffer = (char*) malloc (sizeof(char)*mapSize);

    fread ((void*)mapbuffer,1,mapSize,mapFile);  
    fclose (mapFile);
     
    switch(intrand){
      case 0:
        sprintf(bgname,"%s/bgs/bg%d_Pal.bin",path,background);
      break;
      
      case 1:
        sprintf(bgname,"%s/bgs/bg%d_Pal.bin",path,random.oldbg);  
      break;
    }  
         
    //load palette file---------------------------------------------------
                 
    FILE* palFile = fopen(bgname,"rb");      
    int palSize;
    fseek (palFile , 0 , SEEK_END);
    palSize = ftell (palFile);
    rewind (palFile); 

    char *palbuffer;         
    palbuffer = (char*) malloc (sizeof(char)*palSize);
    
    
    PA_WaitForVBL();

    fread ((void*)palbuffer,1,palSize,palFile);  
    fclose (palFile);   


    
    PA_EasyBgLoadEx(0,3,(void *)infobuffer,(void *)tilebuffer,tileSize,(void *)mapbuffer,mapSize,(void*)palbuffer);//bottom screen
    PA_EasyBgLoadEx(1,3,(void *)infobuffer,(void *)tilebuffer,tileSize,(void *)mapbuffer,mapSize,(void*)palbuffer);//top screen
    

    if(soundsystem->state == PLAYING){ 
       soundsystem->sendFIFO = true;
       PA_WaitForVBL();      
    }
    

   
    //set paralax scroll speeds 
    
      switch(player.speed){
        case 1:gamedata.paralxscroll=256;break;
        case 2:gamedata.paralxscroll=300;break;
        case 3:gamedata.paralxscroll=192;break;
        case 4:gamedata.paralxscroll=170;break;
      }
     

      PA_InitParallaxY(0,0,0, gamedata.paralxscroll,0);
       


      
    if(intrand==0){
      gamedata.scrolly=100; 
      random.oldbg=background;
    }
    

        
}
*/
//Gif backgrounds
void bgload(){

  bool loadbackground=1;
  
  while (loadbackground==1){

    char pathbuf[20];

    char bgname[256];
       
	    
	  sprintf(pathbuf,"%s/bgs",path);  
	    
		background=PA_RandMinMax(1,maxbg);
	
      
		if(background==random.oldbg)background= PA_RandMinMax(1,maxbg);//if the platform pick was the same as last time, pick another one
    else if(background==random.oldbg)background= PA_RandMinMax(1,maxbg);//does that twice
    
    
    if(random.oldbg>maxbg)random.oldbg=1;
    else if(random.oldbg<1)random.oldbg=maxbg;
    
    
    switch(intrand){
      case 0:
        sprintf(bgname,"%s/bgs/bg%d.gif",path,background);
      break;
      
      case 1:
        sprintf(bgname,"%s/bgs/bg%d.gif",path,random.oldbg);
      break;
      
      case 2:
         sprintf(bgname,"%s/bgs/bg%d.gif",path,random.oldbg);
      break;
      
      case 3:
         sprintf(bgname,"%s/bgs/bg%d.gif",path,random.oldbg);
      break;
    }
		
		char * bgbuffer;
		
		
		if(soundsystem->state == PLAYING){ 
     soundsystem->sendFIFO = false;
     PA_WaitForVBL();	// hopefully the large buffer manages this ... if not, make it bigger or try with only one WaitForVBL()

    }		
		 
    FILE* bgFile = fopen (bgname, "rb"); //rb = read
    
 
        // obtain file size:
        int bgSize;
        fseek (bgFile , 0 , SEEK_END);
        bgSize = ftell (bgFile);
        rewind (bgFile);
        // allocate memory to store the mod file
      
        bgbuffer = (char*) malloc (sizeof(char)*bgSize);
        fread (bgbuffer,1,bgSize,bgFile);
        // close the file
        fclose (bgFile);
       
      
     if(soundsystem->state == PLAYING){ 
        soundsystem->sendFIFO = true;
        
        PA_WaitForVBL();      
      }

      
      switch(intrand){
        case 0://general randomness(after each platform finishes scrolling)
          PA_Init8bitBg(0, 3); 
          PA_LoadGif(	0,(void*)bgbuffer); 
       
          PA_Init8bitBg(1, 3); 
          PA_EasyBgLoad(1,2,scorebg);
          
          PA_WaitForVBL();  	
          PA_Init16cBg(1,1);	
	
          PA_LoadGif(	1,(void*)bgbuffer); 
         
        break;
      
        case 1://controlled platforms (changed in pause menu)
          PA_Init8bitBg(0, 3); 
          PA_LoadGif(	0,(void*)bgbuffer); 
       
          PA_Init8bitBg(1, 3); 
          PA_EasyBgLoad(1,2,pausebg);
          
          PA_WaitForVBL();
          PA_Init16cBg(1,1);	
	
          PA_LoadGif(	1,(void*)bgbuffer); 
        break;
        
        case 2://entering pause menu
        
          PA_Init8bitBg(1, 3); 
          PA_EasyBgLoad(1, 2,pausebg); 
          PA_WaitForVBL();
          PA_Init16cBg(1,1);	
	
          PA_LoadGif(	1,(void*)bgbuffer);
        
        break;
        
        case 3://exiting pause menu
          PA_Init8bitBg(1, 3); 
          PA_EasyBgLoad(1, 2,scorebg); 
          PA_WaitForVBL();
          PA_Init16cBg(1,1);	
	
          PA_LoadGif(	1,(void*)bgbuffer);
        
        break;
      } 
      
      
      
      switch(player.speed){
        case 1:gamedata.paralxscroll=256;break;
        case 2:gamedata.paralxscroll=300;break;
        case 3:gamedata.paralxscroll=192;break;
        case 4:gamedata.paralxscroll=170;break;
      }
     

      PA_InitParallaxY(0,0,0, gamedata.paralxscroll,0);
      
      
      if(intrand==0){
        gamedata.scrolly=100; 
        random.oldbg=background;
      }
       
    
    
    loadbackground=0;
	}				
}






//loads mod music
void musicload(){

    char pathbuf[20];

    char modname[20];
       
    PA_StopMod();
		char * modbuffer;
	    
	  sprintf(pathbuf,"%s/music",path);    
		int song = PA_RandMinMax(0,countfiles(pathbuf));
		
		sprintf(modname,"%s/music/song%d.mod",path,song);	
		PA_WaitForVBL();PA_WaitForVBL();
    FILE* modFile = fopen (modname, "rb"); //rb = read

    
    if(modFile){//if there is a mod file
      // obtain file size:
      int modSize;
      fseek (modFile , 0 , SEEK_END);
      modSize = ftell (modFile);
      rewind (modFile);
      // allocate memory to store the mod file
      
      modbuffer = (char*) malloc (sizeof(char)*modSize);
      fread (modbuffer,1,modSize,modFile);
      // close the file
      fclose (modFile);
      PA_PlayMod(modbuffer);
			free((void *)modbuffer);
      	
    }
					
}

//load mp3 music
 void mp3load(){
 
    char bgname[128];
    char pathbuf[20];
    
    sprintf(pathbuf,"%s/mp3",path);
    int song = PA_RandMinMax(1,countfiles(pathbuf));//counts how many files there are and picks a random one

    
    //load mp3 based on the song number
    sprintf(bgname,"%s/mp3/song%d.mp3",path,song); 
    PA_WaitForVBL(); PA_WaitForVBL();   
    infile = fopen(bgname,"rb");
     
     
    if(!infile){//if no mp3 found, switch back to mod files

       enablemusic=0;
       musicload();       
    }
 
  	if (!(soundsystem->state & PLAYING)){
        soundsystem->sendFIFO = true;
				PA_PlayMP3(infile);	// the parameter must be an opened file handle
				PA_ResumeMP3(); 
				PA_WaitForVBL();PA_WaitForVBL();
		}
			else
			{
				PA_StopMP3();		// this does nothing to the file handle - don't forget to close it!
			}
      

	
}
void stopmp3(){//stops an mp3
  PA_StopMP3();
  PA_WaitForVBL(); PA_WaitForVBL();
  PA_WaitForVBL(); PA_WaitForVBL();
 
  if(player.y<0)fclose(infile);


}

