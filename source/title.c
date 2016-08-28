#include <PA9.h> 

#include "header.h"
#include <fat.h>
#include <sys/dir.h> 


void title(){

  char pathbuf[20];

  startmenu=TRUE;
	PA_SetModVolume(50);
	
	//load menu music-----------------------
  //DIR_ITER* dir=diropen("/brickfall/music");

   sprintf(pathbuf,"%s/music/song0.mod",path);  
   FILE* modFile = fopen (pathbuf, "rb"); //rb = read

   // obtain file size:
   int modSize;
   fseek (modFile , 0 , SEEK_END);
   modSize = ftell (modFile);
   rewind (modFile);
   // allocate memory to store the mod file
   char * buffer;
   buffer = (char*) malloc (sizeof(char)*modSize);
   fread (buffer,1,modSize,modFile);
   // close the file
   fclose (modFile);
   PA_PlayMod(buffer);//play music
   
   free((void*)buffer);	
  //-----------------------------   
    clearscreen(1);  
    clearscreen(0); 

   PA_EasyBgLoad(1, 2,fdtitle);
   PA_EasyBgLoad(0, 2,menubg);
   
   
   PA_EasyBgLoad(0, 1,optionbg);
   PA_EnableSpecialFx(0, SFX_ALPHA, SFX_BG1, SFX_BG2 );
   PA_SetSFXAlpha (0,11,5);
   
}



