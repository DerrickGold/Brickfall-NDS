#ifndef __HEADER5__
#define __HEADER5__

#include <PA9.h>

//background stuff
typedef struct{
	int oldplat;
	int oldbg;
	int maxplatform;
}preloadinfo;

preloadinfo random;

int level;
bool loadplatforms;


int intrand;

void stopmp3(void);

void mp3load(void);

void loadsprite(void);

void musicload(void);

void bgload(void);

void platformload(void);

int countfiles(char* directory);


#endif

