#include <PA9.h> 

#include "header.h"
#include "collision.h"

//controls for playing

void checkcontrolls(){

	if(player.controls==FALSE){//if motion is not used

    switch(player.speed){
		
      case 1:
	
        if(item.number!=3){//regular controls
          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A)) player.x += (Pad.Held.Right - Pad.Held.Left) * 2;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.A - Pad.Held.Y) * 2;
          }

          if(Stylus.Held){//stylus
            if(Stylus.X>player.x+8)player.x+=2;
            else if(Stylus.X<player.x)player.x-=2;
          }

          player.y+=1;//falling speed
        }


        if(item.number==3){//if the reverse controls item is picked up
          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))player.x += (Pad.Held.Left- Pad.Held.Right) * 2;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.Y - Pad.Held.A) * 2;
          }

          else if(Stylus.Held){//stylus
            if(Stylus.X<player.x)player.x+=2;
            else if(Stylus.X>player.x+8)player.x-=2;
          }

          player.y+=1;//falling speed
        }
        
        			//left and right edge of screen collision (different based on speed)
        if (player.x<=0)player.x=player.x+2;
        else if (player.x>=248)player.x=player.x-2;
        if(player.y+9>192)player.y-=1;//bottom of the screen collision
      break;
	

      case 2:
  
        if(item.number!=3){//regular controls
          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))player.x += (Pad.Held.Right - Pad.Held.Left) * 2.5;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.A - Pad.Held.Y) * 2.5;
          }

          else if(Stylus.Held){//stulus
            if(Stylus.X>player.x+8)player.x+=2.5;
            else if(Stylus.X<player.x)player.x-=2.5;
          }

          player.y+=1;//falling speed
        }


        if(item.number==3){//reverse controls
          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))player.x += (Pad.Held.Left- Pad.Held.Right) * 2.5;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.Y - Pad.Held.A) * 2.5;
          }

          else if(Stylus.Held){//stylus
            if(Stylus.X<player.x)player.x+=2.5;
            else if(Stylus.X>player.x+8)player.x-=2.5;
          }

        player.y+=1;//falling speed
       }
       
              //left and right edge of screen collision (different based on speed)
        if (player.x<=0)player.x=player.x+2;
        else if (player.x>=248)player.x=player.x-2;
        if(player.y+9>192)player.y-=1;//bottom of the screen collision
      break;


	
      case 3:
	
        if(item.number!=3){//regular controls

          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))player.x += (Pad.Held.Right - Pad.Held.Left) * 3;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.A - Pad.Held.Y) * 3;
          }

         else if(Stylus.Held){//stylus
            if(Stylus.X>player.x+8)player.x+=3;
            else if(Stylus.X<player.x)player.x-=3;
          }

          player.y+=2;//falling speed

        }

	
        if(item.number==3){//reverse controls

          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))player.x += (Pad.Held.Left - Pad.Held.Right) * 3;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.Y - Pad.Held.A) * 3;
          }

          else if(Stylus.Held){//stylus
            if(Stylus.X<player.x)player.x+=3;
            else if(Stylus.X>player.x+8)player.x-=3;
          }

          player.y+=2;//falling speed

        }
                //left and right edge of screen collision (different based on speed)
        if (player.x<=0)player.x=player.x+3;
        else if (player.x>=248)player.x=player.x-3;
        if(player.y+9>192)player.y-=2;//bottom of the screen collision
      break;

	
      case 4:
	
       if(item.number!=3){//regular controls

          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))player.x += (Pad.Held.Right - Pad.Held.Left) * 4;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.A - Pad.Held.Y) * 4;
          }

          else if(Stylus.Held){//stylus
            if(Stylus.X>player.x+8)player.x+=4;
           else if(Stylus.X<player.x)player.x-=4;
          }

          player.y+=3;//falling speed
        }
	
        if(item.number==3){//reverse controls

          if(!Stylus.Held){
            if(!(Pad.Held.Y||Pad.Held.A))	player.x += (Pad.Held.Left - Pad.Held.Right) * 4;	
            else if(!(Pad.Held.Right||Pad.Held.Left)) player.x += (Pad.Held.Y - Pad.Held.A) * 4;
          }

          else if(Stylus.Held){//stylus
            if(Stylus.X<player.x)player.x+=4;
            else if(Stylus.X>player.x+8)player.x-=4;
          }

          player.y+=3;//falling speed

        }
        
        //left and right edge of screen collision (different based on speed)
        if (player.x<=0)player.x=player.x+4;
        else if (player.x>=248)player.x=player.x-4;
        if(player.y+9>192)player.y-=3;//bottom of the screen collision
      break;
      
   }//end of switch
	
 }//end of button/stylus control


	else if(player.controls==TRUE){//if motion enabled
	
		if(item.number!=3){//regular controls
		
      switch(player.speed){
        case 1:
          player.x += (Motion.Held.Right - Motion.Held.Left) * 2;
          player.y+=1;
          
                  			//left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+2;
          else if (player.x>=248)player.x=player.x-2;
          if(player.y+9>192)player.y-=1;//bottom of the screen collision
        break;
			
        case 2:
          player.x += (Motion.Held.Right - Motion.Held.Left) * 2;
          player.y+=1;
          
                          //left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+2;
          else if (player.x>=248)player.x=player.x-2;
          if(player.y+9>192)player.y-=1;//bottom of the screen collision
        break;

        case 3:
          player.x += (Motion.Held.Right - Motion.Held.Left) * 3;
          player.y+=2;
          
                          //left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+3;
          else if (player.x>=248)player.x=player.x-3;
          if(player.y+9>192)player.y-=2;//bottom of the screen collision
        break;

        case 4:
          player.x += (Motion.Held.Right - Motion.Held.Left) * 4;
          player.y+=3;
          
                  //left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+4;
          else if (player.x>=248)player.x=player.x-4;
          if(player.y+9>192)player.y-=3;//bottom of the screen collision
        break;
      }
    }
		//flip controls
		else if(item.number==3){
		
      switch(player.speed){
        case 1:
          player.x += (Motion.Held.Left - Motion.Held.Right) * 2;
          player.y+=1;
          
                  			//left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+2;
          else if (player.x>=248)player.x=player.x-2;
          if(player.y+9>192)player.y-=1;//bottom of the screen collision
        break;
			
        case 2:
          player.x += (Motion.Held.Left - Motion.Held.Right) * 2;
          player.y+=1;
          
                          //left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+2;
          else if (player.x>=248)player.x=player.x-2;
          if(player.y+9>192)player.y-=1;//bottom of the screen collision
        break;

        case 3:
          player.x += (Motion.Held.Left - Motion.Held.Right) * 3;
          player.y+=2;
          
                          //left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+3;
          else if (player.x>=248)player.x=player.x-3;
          if(player.y+9>192)player.y-=2;//bottom of the screen collision
        break;

        case 4:
          player.x += (Motion.Held.Left - Motion.Held.Right) * 4;
          player.y+=3;
          
                  //left and right edge of screen collision (different based on speed)
          if (player.x<=0)player.x=player.x+4;
          else if (player.x>=248)player.x=player.x-4;
          if(player.y+9>192)player.y-=3;//bottom of the screen collision
        break;
      }
		}
		

	}//end of motion 
	
	DownCollision();
	RightCollision();
  LeftCollision();
  TopCollision();

}

