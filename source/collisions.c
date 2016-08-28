#include <PA9.h> 

#include "header.h"
#include "collision.h"

//collision of platforms

//checks collision based on the color of the background
s16 DownCollision(){
	return (PA_EasyBgGetPixel(0, 2,player.x+4,player.y+8 ));
}

s16 RightCollision(){
	return (PA_EasyBgGetPixel(0, 2,player.x+8,player.y+4 ));
}

s16 LeftCollision(){
	return (PA_EasyBgGetPixel(0, 2,player.x,player.y+4));
}
s16 TopCollision(){
	return (PA_EasyBgGetPixel(0, 2,player.x+4,player.y+3));
}

//do action based on what part of the sprite is colliding		
void CheckCollisions(){
	while(DownCollision()){ 

    switch(player.speed){
      case 1:
        player.y--; 
      break;

      case 2:
        player.y--; 
      break;

      case 3:
        player.y-=1; 
      break;
      
      case 4:
        player.y-=2;
      break;
    }

	}
	
	while(LeftCollision()){ 
	
    switch(player.speed){
      case  1:
        player.x+=1; 
      break;

      case 2:
        player.x+=2; 
      break;

      case 3:
        player.x+=3; 
      break;
      
      case 4:
        player.x+=4;
      break;
		}

	}

	while(RightCollision()){

		switch(player.speed){
      case 1:
        player.x-=1; 
      break;

      case 2:
        player.x-=2; 
      break;

      case 3:
        player.x-=3; 
      break;
      
      case 4:
        player.x-=4;
      break;
		}

	}


  while(TopCollision()){ 
  
    switch(player.speed){
      case 1:
        player.y++; 
      break;

      case 2:
        player.y++; 
      break;

      case 3:
        player.y+=1; 
      break;
      
      case 4:
        player.y+=2;
      break;
		}

	}
}





