//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char arrow_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : arrow_Pal
extern const unsigned char arrowh_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : arrowh_Pal
extern const unsigned char cyan_Sprite[576] __attribute__ ((aligned (4))) ;  // Pal : cyan_Pal
extern const unsigned char go1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : go1_Pal
extern const unsigned char go2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : go2_Pal
extern const unsigned char itemspri_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : itemspri_Pal
extern const unsigned char lights_Sprite[2560] __attribute__ ((aligned (4))) ;  // Pal : lights_Pal
extern const unsigned char menu1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : menu1_Pal
extern const unsigned char menu2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : menu2_Pal
extern const unsigned char music_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : music_Pal
extern const unsigned char op1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : op1_Pal
extern const unsigned char op2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : op2_Pal
extern const unsigned char retry1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : retry1_Pal
extern const unsigned char retry2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : retry2_Pal
extern const unsigned char speedspri_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : speedspri_Pal
extern const unsigned char start1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : start1_Pal
extern const unsigned char start2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : start2_Pal
extern const unsigned char tut1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : tut1_Pal
extern const unsigned char tut2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : tut2_Pal
extern const unsigned char wifi1_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : wifi1_Pal
extern const unsigned char wifi2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : wifi2_Pal

// Background files : 
extern const int credits_Info[3]; // BgMode, Width, Height
extern const unsigned short credits_Map[768] __attribute__ ((aligned (4))) ;  // Pal : credits_Pal
extern const unsigned char credits_Tiles[14208] __attribute__ ((aligned (4))) ;  // Pal : credits_Pal
extern PAGfx_struct credits; // background pointer

extern const int creditstop_Info[3]; // BgMode, Width, Height
extern const unsigned short creditstop_Map[768] __attribute__ ((aligned (4))) ;  // Pal : creditstop_Pal
extern const unsigned char creditstop_Tiles[13824] __attribute__ ((aligned (4))) ;  // Pal : creditstop_Pal
extern PAGfx_struct creditstop; // background pointer

extern const int fdbottom_Info[3]; // BgMode, Width, Height
extern const unsigned short fdbottom_Map[768] __attribute__ ((aligned (4))) ;  // Pal : fdbottom_Pal
extern const unsigned char fdbottom_Tiles[47872] __attribute__ ((aligned (4))) ;  // Pal : fdbottom_Pal
extern PAGfx_struct fdbottom; // background pointer

extern const int fdtitle_Info[3]; // BgMode, Width, Height
extern const unsigned short fdtitle_Map[768] __attribute__ ((aligned (4))) ;  // Pal : fdtitle_Pal
extern const unsigned char fdtitle_Tiles[31360] __attribute__ ((aligned (4))) ;  // Pal : fdtitle_Pal
extern PAGfx_struct fdtitle; // background pointer

extern const int menubg_Info[3]; // BgMode, Width, Height
extern const unsigned short menubg_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menubg_Pal
extern const unsigned char menubg_Tiles[45376] __attribute__ ((aligned (4))) ;  // Pal : menubg_Pal
extern PAGfx_struct menubg; // background pointer

extern const int motion_Info[3]; // BgMode, Width, Height
extern const unsigned short motion_Map[768] __attribute__ ((aligned (4))) ;  // Pal : motion_Pal
extern const unsigned char motion_Tiles[24192] __attribute__ ((aligned (4))) ;  // Pal : motion_Pal
extern PAGfx_struct motion; // background pointer

extern const int optionbg_Info[3]; // BgMode, Width, Height
extern const unsigned short optionbg_Map[2048] __attribute__ ((aligned (4))) ;  // Pal : optionbg_Pal
extern const unsigned char optionbg_Tiles[832] __attribute__ ((aligned (4))) ;  // Pal : optionbg_Pal
extern PAGfx_struct optionbg; // background pointer

extern const int pausebg_Info[3]; // BgMode, Width, Height
extern const unsigned short pausebg_Map[768] __attribute__ ((aligned (4))) ;  // Pal : pausebg_Pal
extern const unsigned char pausebg_Tiles[1984] __attribute__ ((aligned (4))) ;  // Pal : pausebg_Pal
extern PAGfx_struct pausebg; // background pointer

extern const int scorebg_Info[3]; // BgMode, Width, Height
extern const unsigned short scorebg_Map[768] __attribute__ ((aligned (4))) ;  // Pal : scorebg_Pal
extern const unsigned char scorebg_Tiles[1280] __attribute__ ((aligned (4))) ;  // Pal : scorebg_Pal
extern PAGfx_struct scorebg; // background pointer

extern const int tutbotsc_Info[3]; // BgMode, Width, Height
extern const unsigned short tutbotsc_Map[768] __attribute__ ((aligned (4))) ;  // Pal : tutbotsc_Pal
extern const unsigned char tutbotsc_Tiles[48064] __attribute__ ((aligned (4))) ;  // Pal : tutbotsc_Pal
extern PAGfx_struct tutbotsc; // background pointer

extern const int tuttopsc_Info[3]; // BgMode, Width, Height
extern const unsigned short tuttopsc_Map[768] __attribute__ ((aligned (4))) ;  // Pal : tuttopsc_Pal
extern const unsigned char tuttopsc_Tiles[47680] __attribute__ ((aligned (4))) ;  // Pal : tuttopsc_Pal
extern PAGfx_struct tuttopsc; // background pointer

extern const int youlose_Info[3]; // BgMode, Width, Height
extern const unsigned short youlose_Map[768] __attribute__ ((aligned (4))) ;  // Pal : youlose_Pal
extern const unsigned char youlose_Tiles[14528] __attribute__ ((aligned (4))) ;  // Pal : youlose_Pal
extern PAGfx_struct youlose; // background pointer


// Palette files : 
extern const unsigned short arrow_Pal[8] __attribute__ ((aligned (4))) ;
extern const unsigned short arrowh_Pal[8] __attribute__ ((aligned (4))) ;
extern const unsigned short cyan_Pal[13] __attribute__ ((aligned (4))) ;
extern const unsigned short go1_Pal[55] __attribute__ ((aligned (4))) ;
extern const unsigned short go2_Pal[63] __attribute__ ((aligned (4))) ;
extern const unsigned short itemspri_Pal[4] __attribute__ ((aligned (4))) ;
extern const unsigned short lights_Pal[58] __attribute__ ((aligned (4))) ;
extern const unsigned short menu1_Pal[63] __attribute__ ((aligned (4))) ;
extern const unsigned short menu2_Pal[73] __attribute__ ((aligned (4))) ;
extern const unsigned short music_Pal[50] __attribute__ ((aligned (4))) ;
extern const unsigned short op1_Pal[58] __attribute__ ((aligned (4))) ;
extern const unsigned short op2_Pal[73] __attribute__ ((aligned (4))) ;
extern const unsigned short retry1_Pal[59] __attribute__ ((aligned (4))) ;
extern const unsigned short retry2_Pal[64] __attribute__ ((aligned (4))) ;
extern const unsigned short speedspri_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short start1_Pal[62] __attribute__ ((aligned (4))) ;
extern const unsigned short start2_Pal[70] __attribute__ ((aligned (4))) ;
extern const unsigned short tut1_Pal[56] __attribute__ ((aligned (4))) ;
extern const unsigned short tut2_Pal[69] __attribute__ ((aligned (4))) ;
extern const unsigned short wifi1_Pal[63] __attribute__ ((aligned (4))) ;
extern const unsigned short wifi2_Pal[83] __attribute__ ((aligned (4))) ;
extern const unsigned short credits_Pal[26] __attribute__ ((aligned (4))) ;
extern const unsigned short creditstop_Pal[19] __attribute__ ((aligned (4))) ;
extern const unsigned short fdbottom_Pal[246] __attribute__ ((aligned (4))) ;
extern const unsigned short fdtitle_Pal[250] __attribute__ ((aligned (4))) ;
extern const unsigned short menubg_Pal[256] __attribute__ ((aligned (4))) ;
extern const unsigned short motion_Pal[249] __attribute__ ((aligned (4))) ;
extern const unsigned short optionbg_Pal[3] __attribute__ ((aligned (4))) ;
extern const unsigned short pausebg_Pal[15] __attribute__ ((aligned (4))) ;
extern const unsigned short scorebg_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short tutbotsc_Pal[255] __attribute__ ((aligned (4))) ;
extern const unsigned short tuttopsc_Pal[255] __attribute__ ((aligned (4))) ;
extern const unsigned short youlose_Pal[256] __attribute__ ((aligned (4))) ;


#endif

