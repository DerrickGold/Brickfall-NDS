#ifndef __HEADER8__
#define __HEADER8__


#include <PA9.h>

typedef struct{
//sine bg
	s8 width;
	s8 height;
	int add;
	s8 x;
	s8 y;
}trippybginfo;

trippybginfo sine;

void HBL_function(void);

void transitionoutinvert(void);

void transitionin(void);

#endif
