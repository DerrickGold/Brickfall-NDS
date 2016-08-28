#ifndef __HEADER3__
#define __HEADER3__

#include <PA9.h>

//button x & y position
s16 x;u8 y;
s16 x2;u8 y2;
s16 x3;u8 y3;




void menu(void);//main menu

void loadmenu(void);//loads title screen and menu stuff

void gamespeed(void);//the select speed menu

void options(void);//option menu

void optiondefaults(void);// stores default values for option menu

void menuvars(void);//stores variables for menu

void pausemenu(void);// pause menu

void tutorial(void);//tutorial part

void submitscore(void);// leaderboard menu

void title(void);

#endif

