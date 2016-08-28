#BrickFall-NDS

An upload of my original code for a project I released back in 2007 prior to any formal education.

Here is the original readme below:


BrickFall 

Special Thanks to Tom @ Palib forum for helping me add the Helix mp3 decoder to my project
and also to Sumiguchi who created the online leaderboard. 



[Description]--------------------------------------------------

BrickFall is basically the game Falldown, you guide a square through a maze of platforms without letting it hit the top of the screen. If it hits the top you lose. Your score is generated on how long you continue to fall. Unlike Falldown, this game has powerups. These powerups can help you or go against you so be careful as it is completely random.

[Installation]-----------------------------------------------------
***Important****
Game will freeze after the motion card splash screen if brickfall directory not on root!

-Copy the "brickfall" folder to your card(any where less than 10 directory's deep)
-DLDI patch brickfall nds file for your card
-enjoy!

[Controls]----------------------------------------------------
This game has 3 control styles you can use:
1: Directional pads and buttons. 
	[Menus]
	 Up and down or X and B will go up and down in menus and A or Left on the D-pad will select the  highlighted option in the menus.
	[Game]
	 Left and right on the d-pad or Y and A buttons will move the guy left and right on screen, and L,R,or start will pause or unpause the game.
2: Stylus.
	[Menus]
	You can navigate through the menus by touching the icons with the stylus.
	[Game]
	All you have to do is drag your stylus left and right and the guy will move with it/

3: Motion:

*******Must be enabled in options menu********
	[Game]	
	With a motion card inserted and enabled in the options menu, you can rotate your DS left and right to move the guy.

	
[Wifi LeaderBoard] http://leaderboard.palib.info/games.php?gameid=11-----------------------------------

When you lose, you have the option to upload your score to an online leaderboard. 

To use, make sure that wifi settings are set up correctly using a wifi compatable game and check that your in range of a wireless router of some sort.

[MP3's]------------------------------------------------------

*******Must be enabled in options menu********

In this game you are able to listen to your own mp3's while playing. For this to work correctly you need to make sure your mp3's follow this format.

-Must be named correctly!
-Must be placed in "brickfall/mp3" folder! 
-bitrate must be 128 kbps or less, anything higher you will get severe slow down while playing or it won't load it at all. 128 May or may not lag, just depends on the song.

****************Make sure folder is Completely empty before adding songs***********

The name must follow this format
song(whatever number).mp3

***CASE SENSATIVE*******
Must use all lower case letters

eg. song1.mp3, song2.mp3, song3.mp3

Do not skip numbers or it won't play it!
You can add as many songs as long as it follows the format.

The program I use for bitrate converting is Switch which can be trialed freely here- http://www.nch.com.au/switch/plus.html

Another recomended program is Sox which can be found here- http://sox.sourceforge.net/

High speed sd card is recomended

[Trouble shooting]---------------------

Problem: Lag while playing mp3s

change the bitrate to something lower, or if it lags only when pausing or new things being loaded, delete mp3 and reput it on



Problem: Score doesn't show up on leaderboard

The score has been submitted anyways and is a bug with the new wifi lib.
The score can be found here: http://leaderboard.palib.info/games.php?gameid=11



[random info]
-you can change the guy on the speed select menu

[Suggestions?]

If you have any, please email me at bassacegold@hotmail.com if your suggestion is good enough, i may add it to the game and your name to the credits... and give you a cookie :D





[History]----------------------------------------------------------------

BrickFall LP-5 Tuesday December 4th 2007

-New background rendering method: allows more detailed/better looking platforms!

-slight volume increase for mp3's

-volume fix for .mod files

-some code cleanup and a lot of tweaks and fixes 

-smaller file size (if that counts as an update :p)

-added text based pause menu

-can now go back to main menu from pause menu

-smoothed out transitions between menus

-2 new items

-tweaked collisions

-fixed a few platforms

-works on g6 real now and probably any other card it didn't work before

-new mp3 system (allows any sized mp3 files, stereo and up to 128 kbps mp3's)

-added Lick's Locator, brickfall folder can be placed any where on your card now


BrickFall LP-4  Thursday September 20th 2007

-added new backgrounds

-added new platforms

-now able to change backgrounds in pause menu with d-pad

-tweaked item movements

-items appear more often

-fixed button sounds bug

-another attempt at fixing the invisible platform bug, I think i got it this time :P

-added new item

-fixed random freeze from unpausing

-does some more "checking" to prevent freezing

-fixed light brightness bug (still crashes if you try to change brightness on a Fat DS)

-fixed exploit in leaderboard system (Thanks sumiguchi for the help!)
IMPORTANT: in order to use leaderboard functions you need the newest release of BrickFall! So please update now!



BrickFall LP-3 Saturday September 1st 2007

-fixed platform collision maps

-New levels

-optimised platform loading (loads platforms faster)

-Fixed wifi leaderboard freeze

-Menus redone

-can now switch mp3s while playing (while paused press select to load a new mp3)

-updated mod song handling

-added new songs

-now checks to see if "brickfall" directory is on the root of card, if not displays error

-got rid of data folder

-updated readme with more info

-random things are more random

-fixed invisible platform bug(i think)

--------------------------------------------------------------------------

BrickFall LP-2 Sunday August 19th 2007

New additions:

-Added readme to rar

-Everything now loads from FAT

-Added wifi leaderboard

-Added mp3 decoder(can now listen to mp3's while playing)


Updates:

-Added more platforms and backgrounds

-Fixed various bugs


--------------------------------------------------------------------------

BrickFall LP-1 Sunday August 5th 2007

From Falldown DS - BrickFall

complete rewrite

New changes:

-added graphics to the menus

-added an options menu

-added stylus controls in-game and in menus

-added new characters which can be selected on the main menu

-added speeds 1 and 4

-added left handed controls (y and a for left and right, x and b for up and down in the menus,and left on the D-pad for selecting in menu)

-added motion card support(tilt DS left and right to move. Turn on in options to enable)

-you can now pause in-game by pressing L,R, or Start

-score now shows on top screen while playing

-added music

-added new platforms and backgrounds

-backgrounds are even more trippy
-added items in-game (only 3, some can help you and some will work against you)

-added sleep mode for when you close your DS

Fixes:

-fix platform and background loading to be more random

-fix bug where you fall off the bottom of the screen

-tweaked speeds to be a little more easy

-loads a random platform after each cycle through
