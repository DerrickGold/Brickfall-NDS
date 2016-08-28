#ifndef __HEADER7__
#define __HEADER7__

#include <PA9.h>

//items
typedef struct{
	s16 y;
	s16 x;
	bool xaxis;
	bool movement;
	u8 speed;
	int number;
	int time;
	int timer;
	int slomo;
	int screen;
}iteminfo;

iteminfo item;

bool enableitems;

void createitems(void);

void itemhandling(void);



#endif

