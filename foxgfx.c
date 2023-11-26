#include "foxgfx.h"
#include "foxfs.h"
#include "common.h"

#define fixedSprHflip  ((1 << 4) | FUNC_Texture | (UseTexture << 16))
VECTOR FNORMS[] =
{
    POStoFIXED(0, -1, 0),
    POStoFIXED(0.723608, -0.447221, 0.525724),
    POStoFIXED(-0.276387, -0.447221, 0.850649),
    POStoFIXED(-0.894427, -0.447214, 0),
    POStoFIXED(-0.276387, -0.447221, -0.850649),
    POStoFIXED(0.723608, -0.447221, -0.525724),
    POStoFIXED(0.276387, 0.447221, 0.850649),
    POStoFIXED(-0.723608, 0.447221, 0.525724),
    POStoFIXED(-0.723608, 0.447221, -0.525724),
    POStoFIXED(0.276387, 0.447221, -0.850649),
    POStoFIXED(0.894427, 0.447214, 0),
    POStoFIXED(0, 1, 0),
    POStoFIXED(-0.23282, -0.657519, 0.716564),
    POStoFIXED(-0.162454, -0.850655, 0.499995),
    POStoFIXED(-0.0776063, -0.96795, 0.23885),
    POStoFIXED(0.203179, -0.96795, 0.147618),
    POStoFIXED(0.425322, -0.850655, 0.309011),
    POStoFIXED(0.609548, -0.657518, 0.442857),
    POStoFIXED(0.531942, -0.502302, 0.681711),
    POStoFIXED(0.262868, -0.525739, 0.809011),
    POStoFIXED(-0.0296365, -0.502302, 0.864184),
    POStoFIXED(0.81273, -0.502301, -0.295235),
    POStoFIXED(0.850649, -0.525735, 0),
    POStoFIXED(0.81273, -0.502301, 0.295235),
    POStoFIXED(0.203179, -0.96795, -0.147618),
    POStoFIXED(0.425322, -0.850655, -0.309011),
    POStoFIXED(0.609548, -0.657518, -0.442857),
    POStoFIXED(-0.753442, -0.657514, 0),
    POStoFIXED(-0.525728, -0.850653, 0),
    POStoFIXED(-0.251145, -0.96795, 0),
    POStoFIXED(-0.483971, -0.502301, 0.716565),
    POStoFIXED(-0.688189, -0.525736, 0.499998),
    POStoFIXED(-0.831052, -0.502297, 0.23885),
    POStoFIXED(-0.23282, -0.657519, -0.716564),
    POStoFIXED(-0.162454, -0.850655, -0.499995),
    POStoFIXED(-0.0776063, -0.96795, -0.23885),
    POStoFIXED(-0.831052, -0.502297, -0.23885),
    POStoFIXED(-0.688189, -0.525736, -0.499998),
    POStoFIXED(-0.483971, -0.502301, -0.716565),
    POStoFIXED(-0.0296365, -0.502302, -0.864184),
    POStoFIXED(0.262868, -0.525739, -0.809011),
    POStoFIXED(0.531942, -0.502302, -0.681711),
    POStoFIXED(0.956626, 0.251149, 0.147618),
    POStoFIXED(0.951059, 0, 0.30901),
    POStoFIXED(0.860698, -0.251149, 0.442858),
    POStoFIXED(0.860698, -0.251149, -0.442858),
    POStoFIXED(0.951059, 0, -0.30901),
    POStoFIXED(0.956626, 0.251149, -0.147618),
    POStoFIXED(0.155213, 0.251149, 0.955423),
    POStoFIXED(0, 0, 1),
    POStoFIXED(-0.155213, -0.251149, 0.955423),
    POStoFIXED(0.687159, -0.251149, 0.681716),
    POStoFIXED(0.587786, 0, 0.809016),
    POStoFIXED(0.436006, 0.251149, 0.864189),
    POStoFIXED(-0.860698, 0.251149, 0.442858),
    POStoFIXED(-0.951059, 0, 0.30901),
    POStoFIXED(-0.956626, -0.251149, 0.147618),
    POStoFIXED(-0.436006, -0.251149, 0.864189),
    POStoFIXED(-0.587786, 0, 0.809016),
    POStoFIXED(-0.687159, 0.251149, 0.681716),
    POStoFIXED(-0.687159, 0.251149, -0.681716),
    POStoFIXED(-0.587786, 0, -0.809016),
    POStoFIXED(-0.436006, -0.251149, -0.864189),
    POStoFIXED(-0.956626, -0.251149, -0.147618),
    POStoFIXED(-0.951059, 0, -0.30901),
    POStoFIXED(-0.860698, 0.251149, -0.442858),
    POStoFIXED(0.436006, 0.251149, -0.864189),
    POStoFIXED(0.587786, 0, -0.809016),
    POStoFIXED(0.687159, -0.251149, -0.681716),
    POStoFIXED(-0.155213, -0.251149, -0.955423),
    POStoFIXED(0, 0, -1),
    POStoFIXED(0.155213, 0.251149, -0.955423),
    POStoFIXED(0.831052, 0.502297, 0.23885),
    POStoFIXED(0.688189, 0.525736, 0.499998),
    POStoFIXED(0.483971, 0.502301, 0.716565),
    POStoFIXED(0.0296365, 0.502302, 0.864184),
    POStoFIXED(-0.262868, 0.525739, 0.809011),
    POStoFIXED(-0.531942, 0.502302, 0.681711),
    POStoFIXED(-0.81273, 0.502301, 0.295235),
    POStoFIXED(-0.850649, 0.525735, 0),
    POStoFIXED(-0.81273, 0.502301, -0.295235),
    POStoFIXED(-0.531942, 0.502302, -0.681711),
    POStoFIXED(-0.262868, 0.525739, -0.809011),
    POStoFIXED(0.0296365, 0.502302, -0.864184),
    POStoFIXED(0.483971, 0.502301, -0.716565),
    POStoFIXED(0.688189, 0.525736, -0.499998),
    POStoFIXED(0.831052, 0.502297, -0.23885),
    POStoFIXED(0.0776063, 0.96795, 0.23885),
    POStoFIXED(0.162454, 0.850655, 0.499995),
    POStoFIXED(0.23282, 0.657519, 0.716564),
    POStoFIXED(0.753442, 0.657514, 0),
    POStoFIXED(0.525728, 0.850653, 0),
    POStoFIXED(0.251145, 0.96795, 0),
    POStoFIXED(-0.203179, 0.96795, 0.147618),
    POStoFIXED(-0.425322, 0.850655, 0.309011),
    POStoFIXED(-0.609548, 0.657518, 0.442857),
    POStoFIXED(-0.203179, 0.96795, -0.147618),
    POStoFIXED(-0.425322, 0.850655, -0.309011),
    POStoFIXED(-0.609548, 0.657518, -0.442857),
    POStoFIXED(0.0776063, 0.96795, -0.23885),
    POStoFIXED(0.162454, 0.850655, -0.499995),
    POStoFIXED(0.23282, 0.657519, -0.716564),
    POStoFIXED(0.361798, 0.894431, -0.26286),
    POStoFIXED(0.638192, 0.723611, -0.262864),
    POStoFIXED(0.44721, 0.723612, -0.525728),
    POStoFIXED(-0.138195, 0.894431, -0.425317),
    POStoFIXED(-0.052788, 0.723612, -0.688185),
    POStoFIXED(-0.361803, 0.723613, -0.587778),
    POStoFIXED(-0.447209, 0.89443, 0),
    POStoFIXED(-0.670816, 0.723612, -0.162457),
    POStoFIXED(-0.670816, 0.723612, 0.162457),
    POStoFIXED(-0.138195, 0.894431, 0.425317),
    POStoFIXED(-0.361803, 0.723613, 0.587778),
    POStoFIXED(-0.052788, 0.723612, 0.688185),
    POStoFIXED(0.361798, 0.894431, 0.26286),
    POStoFIXED(0.44721, 0.723612, 0.525728),
    POStoFIXED(0.638192, 0.723611, 0.262864),
    POStoFIXED(0.861805, 0.276395, -0.425321),
    POStoFIXED(0.80902, 0, -0.587782),
    POStoFIXED(0.670821, 0.276395, -0.68819),
    POStoFIXED(-0.138199, 0.276395, -0.951056),
    POStoFIXED(-0.309015, 0, -0.951057),
    POStoFIXED(-0.447214, 0.276395, -0.85065),
    POStoFIXED(-0.947214, 0.276394, -0.162457),
    POStoFIXED(-1, 0, 0),
    POStoFIXED(-0.947214, 0.276394, 0.162457),
    POStoFIXED(-0.447214, 0.276395, 0.85065),
    POStoFIXED(-0.309015, 0, 0.951057),
    POStoFIXED(-0.138199, 0.276395, 0.951056),
    POStoFIXED(0.670821, 0.276395, 0.68819),
    POStoFIXED(0.80902, 0, 0.587782),
    POStoFIXED(0.861805, 0.276395, 0.425321),
    POStoFIXED(0.309015, 0, -0.951057),
    POStoFIXED(0.447213, -0.276398, -0.850649),
    POStoFIXED(0.138199, -0.276398, -0.951055),
    POStoFIXED(-0.80902, 0, -0.587782),
    POStoFIXED(-0.670819, -0.276394, -0.688192),
    POStoFIXED(-0.861803, -0.276395, -0.425325),
    POStoFIXED(-0.80902, 0, 0.587782),
    POStoFIXED(-0.861803, -0.276395, 0.425325),
    POStoFIXED(-0.670819, -0.276394, 0.688192),
    POStoFIXED(0.309015, 0, 0.951057),
    POStoFIXED(0.138199, -0.276398, 0.951055),
    POStoFIXED(0.447213, -0.276398, 0.850649),
    POStoFIXED(1, 0, 0),
    POStoFIXED(0.947214, -0.276394, 0.162457),
    POStoFIXED(0.947214, -0.276394, -0.162457),
    POStoFIXED(0.361803, -0.723613, -0.587778),
    POStoFIXED(0.138195, -0.89443, -0.42532),
    POStoFIXED(0.052788, -0.723612, -0.688185),
    POStoFIXED(-0.44721, -0.723612, -0.525728),
    POStoFIXED(-0.361798, -0.894431, -0.26286),
    POStoFIXED(-0.638195, -0.72361, -0.262861),
    POStoFIXED(-0.638194, -0.723609, 0.262864),
    POStoFIXED(-0.361799, -0.894429, 0.262865),
    POStoFIXED(-0.44721, -0.723612, 0.525728),
    POStoFIXED(0.670816, -0.723612, -0.162457),
    POStoFIXED(0.670816, -0.723612, 0.162457),
    POStoFIXED(0.447211, -0.894429, 0),
    POStoFIXED(0.052788, -0.723612, 0.688185),
    POStoFIXED(0.138199, -0.894429, 0.42532),
    POStoFIXED(0.361806, -0.723612, 0.587778),
};

#pragma pack(1)
typedef struct {
  unsigned char id_len;
  unsigned char color_map_type;
  unsigned char image_type;
  unsigned short color_map_start;
  unsigned short color_map_length;
  unsigned char color_map_depth;
  unsigned short x_origin;
  unsigned short y_origin;
  unsigned short width;
  unsigned short height;
  unsigned char bits_per_pixel;
  unsigned char image_descriptor;
} TGA_HEADER;
#pragma pack(0)

#define maxPtWork 600

TEXTURE TexSGL[100];

ptTransfer ptWorkArea[maxPtWork];

GOURAUDTBL GouraudFinal[2056];
unsigned short         GouraudUsed = 0;


int FILSEIZEPERM;

int totalTextures = 0;
int TotalSizeVram = 0;


Sint32 LoadTGA(char* FileName) {
    
        unsigned char RGBVAL[3];
        unsigned char RGBVAL32[4];

        int WidthI;
        int HeightI;

    TGA_HEADER *header;
    TGA_HEADER ReadableTGAHead;
    int FileSize = OpenFileSimple((Sint8 *)FileName, &LoadingHeap[0]);
    ReadableTGAHead = *(TGA_HEADER *)&LoadingHeap[0];
    TexSGL[totalTextures].CGadr = (cgaddress+(((TotalSizeVram))>>(pal)))/8;
    TexSGL[totalTextures].Hsize = swap_endian_sshort(ReadableTGAHead.width);
    TexSGL[totalTextures].Vsize = swap_endian_sshort(ReadableTGAHead.height);
    TexSGL[totalTextures].HVsize = (((TexSGL[totalTextures].Hsize)&0x1f8)<<5 | (TexSGL[totalTextures].Vsize));

    TotalSizeVram += (TexSGL[totalTextures].Hsize * TexSGL[totalTextures].Vsize) * 4;
    Uint16 *texDest = (Uint16 *)&LoadingHeap[FileSize];

    if(ReadableTGAHead.bits_per_pixel == 24) {
    int ii = 0;
    for(int i = 0; i < (TexSGL[totalTextures].Hsize * TexSGL[totalTextures].Vsize); i++) {
        for(int j = 0; j < 3; j++) {
            RGBVAL[j] = *((unsigned char *)&LoadingHeap[0]+(i*3)+18+j);
        };
        *((Uint16 *)texDest+ii) =C_RGB((RGBVAL[2]>>3)& 0x1F,(RGBVAL[1]>>3)& 0x1F,(RGBVAL[0]>>3)& 0x1F);
        ii++;
    };
    } else if(ReadableTGAHead.bits_per_pixel == 32) {
    int ii = 0;
    for(int i = 0; i < (TexSGL[totalTextures].Hsize * TexSGL[totalTextures].Vsize); i++) {
        for(int j = 0; j < 4; j++) {
            RGBVAL32[j] = *((unsigned char *)&LoadingHeap[0]+(i*4)+18+j);
        };
        if(RGBVAL32[3] == 255)*((Uint16 *)texDest+ii) =C_RGB((RGBVAL32[2]>>3)& 0x1F,(RGBVAL32[1]>>3)& 0x1F,(RGBVAL32[0]>>3)& 0x1F); else *((Uint16 *)texDest+ii) = 0;
        ii++;
    };
    };
    
    TEXTURE *txptr = &TexSGL[totalTextures];
    PICTURE TexFinal[] = {PICDEF(totalTextures,COL_32K,(Uint8 *)(&LoadingHeap[FileSize+2]))};
    PICTURE * pcptr = &TexFinal[0];
    slDMACopy((void *)&LoadingHeap[FileSize],(void *)(SpriteVRAM + ((txptr->CGadr << 3))), (Uint32)((TexSGL[totalTextures].Hsize*TexSGL[totalTextures].Vsize*4>>(pcptr->cmode))));   
     slDMAWait();


//*(volatile unsigned long *)0x20200000 = (unsigned long)(SpriteVRAM + ((txptr->CGadr << 3)));
    totalTextures += 1;

    return FileSize;
    
};

void fxDrawGen(int TexID, Uint16 Dir, Uint16 Color, Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, Uint16 Gouraud, Uint16 CMode ,Sint16 Z){
        SPRITE user_sprite;
        user_sprite.LINK =0;
        user_sprite.PMOD= CL32KRGB | ECdis | SPenb | CMode;
        if(TexID == -1) {
            user_sprite.CTRL = sprPolygon | _ZmCC;
            user_sprite.COLR=Color;
        } else {
            user_sprite.CTRL = Dir | _ZmCC;
            user_sprite.SRCA=(((TexSGL[TexID].CGadr)));
            user_sprite.SIZE=TexSGL[TexID].HVsize;
            user_sprite.COLR=0;
        };
        user_sprite.XA=XA;
        user_sprite.YA=YA;
        user_sprite.XB=XB;
        user_sprite.YB=YB;
        user_sprite.XC=XC;
        user_sprite.YC=YC;
        user_sprite.XD=XD;
        user_sprite.YD=YD;
        user_sprite.GRDA=Gouraud;


        slSetSprite(&user_sprite,toFIXED(Z));
};

Uint16 FxClipDataSprite(Uint16 Dir,Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, char* OrOut) { // if OrOut = -1, it means its either out of range, not facing the screen, or something else
        char XAON = 0;
        char YAON = 0;
        //checking if first point is on screen
        if(XA < -160) XAON = 1; else if(XA > 160) XAON = 1;
        if(YA < -112) YAON = 1; else if(YA > 112) YAON = 1;


        if(( // check if all points are on screen (if they are all off screen it is culled)
            ((XAON != 0) || (YAON != 0)) &&
            ((XB < -160 || XB > 160) || (YB < -112 || YB > 112)) &&
            ((XC < -160 || XC > 160) || (YC < -112 || YC > 112)) &&
            ((XD < -160 || XD > 160) || (YD < -112 || YD > 112))
        )) {
            *OrOut = -1;
            return 0;
        };






        if(XAON == 0 && YAON == 0) { // default orientation
            *OrOut = 0;
            switch(Dir) { // these switch statements are for orientation stuff
                        case (Uint16)0 :
                        return sprNoflip;
                        break;
                        case (Uint16)1 :
                        return fixedSprHflip;
                        break;
                        case (Uint16)2 :
                        return sprVflip;
                        break;
                        case (Uint16)3 :
                        return sprHVflip;
                        break;
                    };
        };

        if(XAON != 0) {
            if(YAON == 0) {
                    *OrOut = 1;
                    switch(Dir) { // these switch statements are for orientation stuff
                        case (Uint16)0 :
                        return fixedSprHflip;
                        break;
                        case (Uint16)1 :
                        return sprNoflip;
                        break;
                        case (Uint16)2 :
                        return sprHVflip;
                        break;
                        case (Uint16)3 :
                        return sprVflip;
                        break;
                    };
            };

            *OrOut = 2;
            switch(Dir) { // these switch statements are for orientation stuff
                        case (Uint16)0 :
                        return sprHVflip;
                        break;
                        case (Uint16)1 :
                        return sprVflip;
                        break;
                        case (Uint16)2 :
                        return fixedSprHflip;
                        break;
                        case (Uint16)3 :
                        return sprNoflip;
                        break;
            };

        };
            *OrOut = 3;
            switch(Dir) { // these switch statements are for orientation stuff
                case (Uint16)0 :
                return sprVflip;
                break;
                case (Uint16)1 :
                return sprHVflip;
                break;
                case (Uint16)2 :
                return sprNoflip;
                break;
                case (Uint16)3 :
                return fixedSprHflip;
                break;
            };
        
};


Uint16 FxClipDataNClipSprite(Uint16 Dir,Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, char* OrOut) { // if OrOut = -1, it means its either out of range, not facing the screen, or something else
        char XAON = 0;
        char YAON = 0;
        //checking if first point is on screen
        if(XA < -160) XAON = 1; else if(XA > 160) XAON = 1;
        if(YA < -112) YAON = 1; else if(YA > 112) YAON = 1;


        if(( // check if all points are on screen (if they are all off screen it is culled)
            ((XAON != 0) || (YAON != 0)) &&
            ((XB < -160 || XB > 160) || (YB < -112 || YB > 112)) &&
            ((XC < -160 || XC > 160) || (YC < -112 || YC > 112)) &&
            ((XD < -160 || XD > 160) || (YD < -112 || YD > 112))
        )) {
            *OrOut = -1;
            return 0;
        };


        Sint16 C0 = (XB - XD) * (YA - YC);
	    Sint16 C1 = (YB - YD) * (XA - XC);
        //Normal Clipping
         if(C0 <= C1) {
            *OrOut = -1;
            return 0;
        };
      


        if(XAON == 0 && YAON == 0) { // default orientation
            *OrOut = 0;
            switch(Dir) { // these switch statements are for orientation stuff
                        case (Uint16)0 :
                        return sprNoflip;
                        break;
                        case (Uint16)1 :
                        return fixedSprHflip;
                        break;
                        case (Uint16)2 :
                        return sprVflip;
                        break;
                        case (Uint16)3 :
                        return sprHVflip;
                        break;
                    };
        };

        if(XAON != 0) {
            if(YAON == 0) {
                    *OrOut = 1;
                    switch(Dir) { // these switch statements are for orientation stuff
                        case (Uint16)0 :
                        return fixedSprHflip;
                        break;
                        case (Uint16)1 :
                        return sprNoflip;
                        break;
                        case (Uint16)2 :
                        return sprHVflip;
                        break;
                        case (Uint16)3 :
                        return sprVflip;
                        break;
                    };
            };

            *OrOut = 2;
            switch(Dir) { // these switch statements are for orientation stuff
                        case (Uint16)0 :
                        return sprHVflip;
                        break;
                        case (Uint16)1 :
                        return sprVflip;
                        break;
                        case (Uint16)2 :
                        return fixedSprHflip;
                        break;
                        case (Uint16)3 :
                        return sprNoflip;
                        break;
            };

        };
            *OrOut = 3;
            switch(Dir) { // these switch statements are for orientation stuff
                case (Uint16)0 :
                return sprVflip;
                break;
                case (Uint16)1 :
                return sprHVflip;
                break;
                case (Uint16)2 :
                return sprNoflip;
                break;
                case (Uint16)3 :
                return fixedSprHflip;
                break;
            };
        
};


char fxClipPt(Sint16 XA, Sint16 YA) {
        // 0 means on-screen, 1 means x off, 2 means y off, 3 means both! :D
        char XAON, YAON = 0;
        if(XA < -160|| XA > 160) XAON = 1;
        if(YA < -112|| YA > 112) YAON = 2;
        return XAON + YAON;
};

Uint16 fxClipPoly(Uint16 Dir, Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, char A, char B, char C, char D, char* OrOut) {
    
    if(A != 0 && B != 0 && C != 0 && D != 0) {
        *OrOut = -1;
        return 0;
    }

    Sint16 C0 = (XB - XD) * (YA - YC);
	Sint16 C1 = (YB - YD) * (XA - XC);
    //Normal Clipping
     if(C0 <= C1) {
        *OrOut = -1;
        return 0;
    };

    if(A == 0) { // default orientation :D
        *OrOut = 0;
        return Dir;
    };

    if(A == 1) { // X flip orientation!
        *OrOut = 1;
        switch(Dir) { // these switch statements are for orientation stuff
            case (Uint16)sprNoflip :
            return fixedSprHflip;
            break;
            case (Uint16)fixedSprHflip :
            return sprNoflip;
            break;
            case (Uint16)sprVflip :
            return sprHVflip;
            break;
            case (Uint16)sprHVflip :
            return sprVflip;
            break;
        };
    };

    if(A == 2) { // Y flip Orientation!
            *OrOut = 3;
            switch(Dir) { // these switch statements are for orientation stuff
                case (Uint16)sprNoflip :
                return sprVflip;
                break;
                case (Uint16)fixedSprHflip :
                return sprHVflip;
                break;
                case (Uint16)sprVflip :
                return sprNoflip;
                break;
                case (Uint16)sprHVflip :
                return fixedSprHflip;
                break;
            };
    };

    // Flip X and Y orientation!
    *OrOut = 2;
    switch(Dir) { // these switch statements are for orientation stuff
                case (Uint16)sprNoflip :
                return sprHVflip;
                break;
                case (Uint16)fixedSprHflip :
                return sprVflip;
                break;
                case (Uint16)sprVflip :
                return fixedSprHflip;
                break;
                case (Uint16)sprHVflip :
                return sprNoflip;
                break;
    };
};

void fxDrawPoly(int TexID, Uint16 Dir, char Orientation, Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, Uint16 Gouraud, Uint16 CMode ,FIXED Z){
        // basic sprite attribute stuff :)
        SPRITE user_sprite;
        user_sprite.LINK =0;
        user_sprite.PMOD= CL32KRGB | ECdis | SPenb | CMode;
        user_sprite.SRCA=(((TexSGL[TexID].CGadr)));
        user_sprite.SIZE=TexSGL[TexID].HVsize;
        user_sprite.COLR=0;
        user_sprite.CTRL = Dir | _ZmCC;
        user_sprite.GRDA=Gouraud;

        switch(Orientation) {
            case 0 : // Normal Orientation
            user_sprite.XA=XA;
            user_sprite.YA=YA;
            user_sprite.XB=XB;
            user_sprite.YB=YB;
            user_sprite.XC=XC;
            user_sprite.YC=YC;
            user_sprite.XD=XD;
            user_sprite.YD=YD;
            slSetSprite(&user_sprite,Z);
            return;
            break;
            case 1 : // Flipped X
            user_sprite.XA=XB;
            user_sprite.YA=YB;
            user_sprite.XB=XA;
            user_sprite.YB=YA;
            user_sprite.XC=XD;
            user_sprite.YC=YD;
            user_sprite.XD=XC;
            user_sprite.YD=YC;
            slSetSprite(&user_sprite,Z);
            return;
            break;
            case 2 : // Flipped X and Y
            user_sprite.XA=XC;
            user_sprite.YA=YC;
            user_sprite.XB=XD;
            user_sprite.YB=YD;
            user_sprite.XC=XA;
            user_sprite.YC=YA;
            user_sprite.XD=XB;
            user_sprite.YD=YB;
            slSetSprite(&user_sprite,Z);
            return;
            break;
            case 3 : // Flipped Y
            user_sprite.XA=XD;
            user_sprite.YA=YD;
            user_sprite.XB=XC;
            user_sprite.YB=YC;
            user_sprite.XC=XB;
            user_sprite.YC=YB;
            user_sprite.XD=XA;
            user_sprite.YD=YA;
            slSetSprite(&user_sprite,Z);
            return;
            break;
        };
};

void DrawSprite(int TexID, Sint16 X, Sint16 Y, Sint16 Depth) {
    char Orient;
    Uint16 Dir = FxClipDataSprite(sprNoflip,X-TexSGL[TexID].Hsize >> 1,Y-TexSGL[TexID].Vsize >> 1,X+TexSGL[TexID].Hsize >> 1,Y-TexSGL[TexID].Vsize >> 1,X+TexSGL[TexID].Hsize >> 1,Y+TexSGL[TexID].Vsize >> 1,X-TexSGL[TexID].Hsize >> 1,Y+TexSGL[TexID].Vsize >> 1,&Orient);
    if(Orient == -1) return;
    fxDrawPoly(TexID,Dir, 0,X-TexSGL[TexID].Hsize >> 1,Y-TexSGL[TexID].Vsize >> 1,X+TexSGL[TexID].Hsize >> 1,Y-TexSGL[TexID].Vsize >> 1,X+TexSGL[TexID].Hsize >> 1,Y+TexSGL[TexID].Vsize >> 1,X-TexSGL[TexID].Hsize >> 1,Y+TexSGL[TexID].Vsize >> 1,No_Gouraud,CL_Replace,toFIXED(Depth));
};

void FXDrawMeshStatic(PFXDATA *Mesh, Uint16 CMode) { // Draws Static Mesh without shading
    if(Mesh->PTC > maxPtWork) return; // Too many points! slow down!
    char Orient;
    FIXED tempPt[2];
    FIXED tempPt3D[3];

    
    for(int i = 0; i < Mesh->PTC; i++) {


        
        slCalcPoint( Mesh->PNTBL[i][X]<<8,
                     Mesh->PNTBL[i][Y]<<8, 
                     Mesh->PNTBL[i][Z]<<8,
        &tempPt3D);

        if(tempPt3D[Z] < toFIXED(15)) tempPt3D[Z] = toFIXED(15);

        slPushUnitMatrix();
        ptWorkArea[i].z = slConvert3Dto2DFX(&tempPt3D,&tempPt)>>16;
        slPopMatrix();


        ptWorkArea[i].x = tempPt[0]>>16;
        ptWorkArea[i].y = tempPt[1]>>16;

    };


    for(int i = 0; i < Mesh->FC; i++) {

        Uint16 Dir = FxClipDataNClipSprite(Mesh->FINDX[i].dir, ptWorkArea[Mesh->FINDX[i].pt1].x,ptWorkArea[Mesh->FINDX[i].pt1].y, ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y,&Orient);

        if(Orient == -1) continue;

        if(ptWorkArea[Mesh->FINDX[i].pt1].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt2].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt3].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt4].z <= 18) continue;

        

        FIXED ZVal = (((ptWorkArea[Mesh->FINDX[i].pt1].z +
                       ptWorkArea[Mesh->FINDX[i].pt2].z +
                       ptWorkArea[Mesh->FINDX[i].pt3].z +
                       ptWorkArea[Mesh->FINDX[i].pt4].z))<<16);
                     


        fxDrawPoly(Mesh->FINDX[i].texid+Mesh->TexOffset, Dir, Orient, 
        ptWorkArea[Mesh->FINDX[i].pt1].x, ptWorkArea[Mesh->FINDX[i].pt1].y, 
        ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, 
        ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, 
        ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y, No_Gouraud, CMode, (ZVal));



    };

};

Sint16 LightCol[3] = {15,15,15};

void SetSceneColour(Sint16 R, Sint16 G, Sint16 B) {
    LightCol[0] = R;
    LightCol[1] = G;
    LightCol[2] = B;
};

void FXDrawMeshStaticShaded(PFXDATA *Mesh, Uint16 CMode, FIXED * LVec) { // Draws Static Mesh without shading
    if(Mesh->PTC > maxPtWork) return; // Too many points! slow down!
    char Orient;
    FIXED tempPt[2];
    FIXED tempPt3D[3];

    for(int i = 0; i < Mesh->PTC; i++) {
        slCalcPoint( Mesh->PNTBL[i][X]<<8,
                     Mesh->PNTBL[i][Y]<<8, 
                     Mesh->PNTBL[i][Z]<<8,
                    &tempPt3D);

        if(tempPt3D[Z] < toFIXED(15)) tempPt3D[Z] = toFIXED(15);

        slPushUnitMatrix();
        ptWorkArea[i].z = slConvert3Dto2DFX(&tempPt3D,&tempPt)>>16;
        slPopMatrix();
        
        slCalcVector(&FNORMS[Mesh->NINDX[i]], &tempPt3D);

        VECTOR LLVC = {-LVec[0], -LVec[1], -LVec[2]};
        FIXED LightSimmer = slInnerProduct(&tempPt3D, &LLVC);
        Sint16 ShadeValR = slMulFX((LightCol[0]+1)<<16,LightSimmer)>>16;
        Sint16 ShadeValB = slMulFX((LightCol[1]+1)<<16,LightSimmer)>>16;
        Sint16 ShadeValG = slMulFX((LightCol[2]+1)<<16,LightSimmer)>>16;
        ptWorkArea[i].L = C_RGB(ShadeValR+LightCol[0]+1,ShadeValG+LightCol[1]+1,ShadeValB+LightCol[2]+1);
        ptWorkArea[i].x = tempPt[0]>>16;
        ptWorkArea[i].y = tempPt[1]>>16;
    };


    for(int i = 0; i < Mesh->FC; i++) {

        Uint16 Dir = FxClipDataNClipSprite(Mesh->FINDX[i].dir, ptWorkArea[Mesh->FINDX[i].pt1].x,ptWorkArea[Mesh->FINDX[i].pt1].y, ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y,&Orient);

        if(Orient == -1) continue;

        if(ptWorkArea[Mesh->FINDX[i].pt1].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt2].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt3].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt4].z <= 18) continue;

        FIXED ZVal = (((ptWorkArea[Mesh->FINDX[i].pt1].z +
                       ptWorkArea[Mesh->FINDX[i].pt2].z +
                       ptWorkArea[Mesh->FINDX[i].pt3].z +
                       ptWorkArea[Mesh->FINDX[i].pt4].z))<<16);

        switch(Orient) {
            case 0 :           // No Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt1].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt2].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt3].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt4].L;
            break;
            case 1 :           // H Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt2].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt1].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt4].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt3].L;
            break;
            case 2 :           // H V Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt3].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt4].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt1].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt2].L;
            break;
            case 3 :           // V Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt4].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt3].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt2].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt1].L;
            break;
        };

        fxDrawPoly(Mesh->FINDX[i].texid+Mesh->TexOffset, Dir, Orient, 
        ptWorkArea[Mesh->FINDX[i].pt1].x, ptWorkArea[Mesh->FINDX[i].pt1].y, 
        ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, 
        ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, 
        ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y, ((cgaddress + 256000 + GouraudUsed*8)>>3), CMode, (ZVal));
        GouraudUsed += 1;
    };


};

void GouraudUpdate() { // if there are any models that use gouraud shading *PLEASE* use this function at the end of a frame, otherwise it could break your lighting.

    slDMACopy((void *)&GouraudFinal,(void *)SpriteVRAM + cgaddress + 256000, sizeof(GOURAUDTBL)*1024);   
    slDMAWait();
    GouraudUsed = 0;

};

void FXDrawMeshAnimFlat(PFXDATA *Mesh, Uint16 CMode, FIXED Lerp) { // Draws animated Mesh without shading
    if(Mesh->PTC > maxPtWork) return; // Too many points! slow down!
    char Orient;
    FIXED tempPt[2];
    FIXED tempPt3D[3];
    Uint16 CurFrame = Lerp>>16;
    Uint16 NextFrame = CurFrame+1;
    FIXED  LerpInator = Lerp - toFIXED(CurFrame);

    if(Lerp > toFIXED(Mesh->FRC-1)) { 
        Lerp = 0;
        NextFrame =  Mesh->FRC-1;
        CurFrame = Mesh->FRC-1;
        LerpInator = 0;
    }

    if(Lerp < 0) {
        Lerp = 0;
        LerpInator = 0;
        CurFrame = 0;
        NextFrame = 0;
    };

    for(int i = 0; i < Mesh->PTC; i++) {
        FIXED tempPt[2];
        FIXED tempPt3D[3];
        FIXED otherTempPT3D[3];

		otherTempPT3D[0] = (Mesh->PNTBL[i+CurFrame*Mesh->PTC][X] + (slMulFX((Mesh->PNTBL[i+NextFrame*Mesh->PTC][X] - Mesh->PNTBL[i+CurFrame*Mesh->PTC][X])<<8, LerpInator  )>>8))<<8;
		otherTempPT3D[1] = (Mesh->PNTBL[i+CurFrame*Mesh->PTC][Y] + (slMulFX((Mesh->PNTBL[i+NextFrame*Mesh->PTC][Y] - Mesh->PNTBL[i+CurFrame*Mesh->PTC][Y])<<8, LerpInator  )>>8))<<8;
		otherTempPT3D[2] = (Mesh->PNTBL[i+CurFrame*Mesh->PTC][Z] + (slMulFX((Mesh->PNTBL[i+NextFrame*Mesh->PTC][Z] - Mesh->PNTBL[i+CurFrame*Mesh->PTC][Z])<<8, LerpInator  )>>8))<<8;

        slCalcPoint( otherTempPT3D[0],
                     otherTempPT3D[1], 
                     otherTempPT3D[2], &tempPt3D);

        if(tempPt3D[Z] < toFIXED(15)) tempPt3D[Z] = toFIXED(15);

        slPushUnitMatrix();
        ptWorkArea[i].z = slConvert3Dto2DFX(&tempPt3D,&tempPt)>>16;
        slPopMatrix();

        ptWorkArea[i].x = tempPt[0]>>16;
        ptWorkArea[i].y = tempPt[1]>>16;
    };

    for(int i = 0; i < Mesh->FC; i++) {
        Uint16 Dir = FxClipDataNClipSprite(Mesh->FINDX[i].dir, ptWorkArea[Mesh->FINDX[i].pt1].x,ptWorkArea[Mesh->FINDX[i].pt1].y, ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y,&Orient);
        if(Orient == -1) continue;

        if(ptWorkArea[Mesh->FINDX[i].pt1].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt2].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt3].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt4].z <= 18) continue;    

        FIXED ZVal = (((ptWorkArea[Mesh->FINDX[i].pt1].z +
                       ptWorkArea[Mesh->FINDX[i].pt2].z +
                       ptWorkArea[Mesh->FINDX[i].pt3].z +
                       ptWorkArea[Mesh->FINDX[i].pt4].z))<<16);

        fxDrawPoly(Mesh->FINDX[i].texid+Mesh->TexOffset, Dir, Orient, 
        ptWorkArea[Mesh->FINDX[i].pt1].x, ptWorkArea[Mesh->FINDX[i].pt1].y, 
        ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, 
        ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, 
        ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y, No_Gouraud, CMode, (ZVal));
    };
};

void FXDrawMeshAnim(PFXDATA *Mesh, Uint16 CMode, FIXED Lerp, FIXED* LVec) { // Draws animated Mesh with shading
    if(Mesh->PTC > maxPtWork) return; // Too many points! slow down!
    char Orient;
    FIXED tempPt[2];
    FIXED tempPt3D[3];
    Uint16 CurFrame = Lerp>>16;
    Uint16 NextFrame = CurFrame+1;
    FIXED  LerpInator = Lerp - toFIXED(CurFrame);

    if(Lerp > toFIXED(Mesh->FRC-1)) { 
        Lerp = 0;
        NextFrame =  Mesh->FRC-1;
        CurFrame = Mesh->FRC-1;
        LerpInator = 0;
    }

    if(Lerp < 0) {
        Lerp = 0;
        LerpInator = 0;
        CurFrame = 0;
        NextFrame = 0;
    };

    for(int i = 0; i < Mesh->PTC; i++) {
        FIXED tempPt[2];
        FIXED tempPt3D[3];
        FIXED otherTempPT3D[3];

		otherTempPT3D[0] = (Mesh->PNTBL[i+CurFrame*Mesh->PTC][X] + (slMulFX((Mesh->PNTBL[i+NextFrame*Mesh->PTC][X] - Mesh->PNTBL[i+CurFrame*Mesh->PTC][X])<<8, LerpInator  )>>8))<<8;
		otherTempPT3D[1] = (Mesh->PNTBL[i+CurFrame*Mesh->PTC][Y] + (slMulFX((Mesh->PNTBL[i+NextFrame*Mesh->PTC][Y] - Mesh->PNTBL[i+CurFrame*Mesh->PTC][Y])<<8, LerpInator  )>>8))<<8;
		otherTempPT3D[2] = (Mesh->PNTBL[i+CurFrame*Mesh->PTC][Z] + (slMulFX((Mesh->PNTBL[i+NextFrame*Mesh->PTC][Z] - Mesh->PNTBL[i+CurFrame*Mesh->PTC][Z])<<8, LerpInator  )>>8))<<8;

        slCalcPoint( otherTempPT3D[0],
                     otherTempPT3D[1], 
                     otherTempPT3D[2], &tempPt3D);

        if(tempPt3D[Z] < toFIXED(15)) tempPt3D[Z] = toFIXED(15);

        slPushUnitMatrix();
        ptWorkArea[i].z = slConvert3Dto2DFX(&tempPt3D,&tempPt)>>16;
        slPopMatrix();

        slCalcVector(&FNORMS[Mesh->NINDX[i+(CurFrame*Mesh->PTC)]], &tempPt3D);

        VECTOR LLVC = {-LVec[0], -LVec[1], -LVec[2]};
        FIXED LightSimmer = slInnerProduct(&tempPt3D, &LLVC);
        Sint16 ShadeValR = slMulFX((LightCol[0]+1)<<16,LightSimmer)>>16;
        Sint16 ShadeValB = slMulFX((LightCol[1]+1)<<16,LightSimmer)>>16;
        Sint16 ShadeValG = slMulFX((LightCol[2]+1)<<16,LightSimmer)>>16;
        ptWorkArea[i].L = C_RGB(ShadeValR+LightCol[0]+1,ShadeValG+LightCol[1]+1,ShadeValB+LightCol[2]+1);

        ptWorkArea[i].x = tempPt[0]>>16;
        ptWorkArea[i].y = tempPt[1]>>16;
    };

    for(int i = 0; i < Mesh->FC; i++) {
        Uint16 Dir = FxClipDataNClipSprite(Mesh->FINDX[i].dir, ptWorkArea[Mesh->FINDX[i].pt1].x,ptWorkArea[Mesh->FINDX[i].pt1].y, ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y,&Orient);

        if(Orient == -1) continue;

        if(ptWorkArea[Mesh->FINDX[i].pt1].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt2].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt3].z <= 18 &&
           ptWorkArea[Mesh->FINDX[i].pt4].z <= 18) continue;

        FIXED ZVal = (((ptWorkArea[Mesh->FINDX[i].pt1].z +
                       ptWorkArea[Mesh->FINDX[i].pt2].z +
                       ptWorkArea[Mesh->FINDX[i].pt3].z +
                       ptWorkArea[Mesh->FINDX[i].pt4].z))<<16);

        switch(Orient) {
            case 0 :           // No Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt1].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt2].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt3].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt4].L;
            break;
            case 1 :           // H Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt2].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt1].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt4].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt3].L;
            break;
            case 2 :           // H V Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt3].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt4].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt1].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt2].L;
            break;
            case 3 :           // V Flip
            GouraudFinal[GouraudUsed][0] = ptWorkArea[Mesh->FINDX[i].pt4].L;;
            GouraudFinal[GouraudUsed][1] = ptWorkArea[Mesh->FINDX[i].pt3].L;
            GouraudFinal[GouraudUsed][2] = ptWorkArea[Mesh->FINDX[i].pt2].L;
            GouraudFinal[GouraudUsed][3] = ptWorkArea[Mesh->FINDX[i].pt1].L;
            break;
        };

        fxDrawPoly(Mesh->FINDX[i].texid+Mesh->TexOffset, Dir, Orient, 
        ptWorkArea[Mesh->FINDX[i].pt1].x, ptWorkArea[Mesh->FINDX[i].pt1].y, 
        ptWorkArea[Mesh->FINDX[i].pt2].x, ptWorkArea[Mesh->FINDX[i].pt2].y, 
        ptWorkArea[Mesh->FINDX[i].pt3].x, ptWorkArea[Mesh->FINDX[i].pt3].y, 
        ptWorkArea[Mesh->FINDX[i].pt4].x, ptWorkArea[Mesh->FINDX[i].pt4].y, ((cgaddress + 256000 + GouraudUsed*8)>>3), CMode, (ZVal));
        GouraudUsed += 1;
    };
};

void LoadMeshFromSSV(char* FileName, PFXDATA* FOXDATA, Uint16 TexOffset) {
    int size = OpenFileSimple((Sint8 *)FileName,&Heap[amtUsed]);
    FOXDATA->PTC = *((Uint16 *)&Heap[amtUsed]);
    FOXDATA->FC = *((Uint16 *)&Heap[amtUsed]+1);
    FOXDATA->FRC = *((Uint16 *)&Heap[amtUsed]+2);

    FOXDATA->PNTBL = ((Uint16 *)&Heap[amtUsed]+3);
    FOXDATA->FINDX = ((Uint16 *)&Heap[amtUsed]+3 + (FOXDATA->PTC*3)*FOXDATA->FRC);
    FOXDATA->NINDX = ((Uint8 *)&Heap[amtUsed+6 + ((FOXDATA->PTC*6)*FOXDATA->FRC) + (FOXDATA->FC * 12)]);
    
    amtUsed = (amtUsed + size + 3) & ~0x03;
    FOXDATA->TexOffset = TexOffset;  
};

void ResetModelHeap() {
    amtUsed = 0;
}


void ResetHeapToPrevious(Uint16 NewStart) { // value must be multiple of 4
    amtUsed = NewStart;
}