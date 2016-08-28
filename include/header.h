#ifndef __HEADER1__
#define __HEADER1__


#include <PA9.h>

#include "../source/gfx/all_gfx.h" // Gfx include for the header (.h)

#include "gamedone.h"
#include "button.h"
#include "gamepause.h"
#include "gameitems.h"


char showscore[1000];
char path[50];



//player
typedef struct{
	s32 y;
	s32 x;
	bool controls;
	u8 speed;
	int score;
	bool options;
	s8 platspeed;
	s8 skin;
	
}spriteinfo;

spriteinfo player;


typedef struct{
	int pausetimer;
	s16 paralxscroll;
	s8 startgame;
	int scrolly;
	s8 startarrowmov;
	s8 startarrowmove;
	s16 arrowy;
}gameplayinfo;

gameplayinfo gamedata;

bool intmotion;

u8 volume;
u8 lightframe;

bool startspeed;
bool startmenu;
bool enablemusic;
int maxbg;
int background;


void clearscreen(bool screen);
void clearspritesys(void);
void motionint(void);
void checkcontrolls(void);
void refreshscore(void);
void resetbuttons(void);
void playmp3(void);
bool fileLocator(char *start, char *target, bool isDir, int depth, char *result);


#endif

