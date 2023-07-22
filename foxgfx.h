#ifndef _GFX_H_
#define _GFX_H_

#include "common.h"

#define BACK_COL_ADR    (VDP2_VRAM_A1 + 0x1fffe)
#define LINE_TBL_ADR    (VDP2_VRAM_A1 + 0x1f000)

#define RBG0_KTBL_ADR   (VDP2_VRAM_A1 + 0x00000)
#define RBG0_PARA_ADR   (VDP2_VRAM_A1 + 0x1ff00)

#define RBG0_CEL_ADR    VDP2_VRAM_A0
#define RBG0_MAP_ADR    VDP2_VRAM_B0

#define NBG1_CEL_ADR    (VDP2_VRAM_B1 + 0x00000)
#define NBG1_MAP_ADR    (VDP2_VRAM_B1 + 0x18000)

#define NBG2_CEL_ADR    (VDP2_VRAM_B1 + 0x10000)
#define NBG2_MAP_ADR    (VDP2_VRAM_B1 + 0x1A000)

#define BEGIN_LWRAM 0x00200000
#define BEGIN_HWRAM 0x06062810

extern int totalTextures;
extern int TotalSizeVram;
extern TEXTURE TexSGL[100];
extern GOURAUDTBL GouraudFinal[2056];

Sint32 LoadTGA(char* FileName);


static inline void SGL_VDP2_Init() {
    slColRAMMode(CRM16_1024);

    slScrTransparent(NBG1ON);
    slScrWindowMode(scnROT, win0_IN);

    // RBG0
    slRparaInitSet((ROTSCROLL *)RBG0_PARA_ADR);
    slMakeKtable((void*)RBG0_KTBL_ADR);
    slCharRbg0(COL_TYPE_256, CHAR_SIZE_2x2);
    slPageRbg0((void *)RBG0_CEL_ADR, 0, PNB_1WORD);
    slPlaneRA(PL_SIZE_1x1);
    sl1MapRA((void*)RBG0_MAP_ADR);
    slKtableRA((void *)RBG0_KTBL_ADR, K_FIX | K_DOT | K_2WORD | K_ON);

    slRparaMode(W_CHANGE);
    slOverRA(0);

    // NBG1
    slCharNbg1(COL_TYPE_256, CHAR_SIZE_2x2);
    slPageNbg1((void *)NBG1_CEL_ADR, 0, PNB_1WORD);
    slPlaneNbg1(PL_SIZE_1x1);
    slMapNbg1((void *)NBG1_MAP_ADR, (void *)NBG1_MAP_ADR, (void *)NBG1_MAP_ADR, (void *)NBG1_MAP_ADR);

    slLineScrollModeNbg1(lineSZ1|lineHScroll);
    slLineScrollTable1((void*)LINE_TBL_ADR);

    // NBG2
    slCharNbg2(COL_TYPE_256, CHAR_SIZE_2x2);
    slPageNbg2((void *)NBG2_CEL_ADR, 0, PNB_1WORD);
    slPlaneNbg2(PL_SIZE_1x1);
    slMapNbg2((void *)NBG2_MAP_ADR, (void *)NBG2_MAP_ADR, (void *)NBG2_MAP_ADR, (void *)NBG2_MAP_ADR);

    // Back color and active layers
    slBack1ColSet((void *)BACK_COL_ADR, 0);
    slScrAutoDisp(RBG0ON | NBG0ON);

    slPriorityNbg1(1);
    slPriorityNbg2(2);
    slPriorityRbg0(3);
};

typedef FIXED8 FP8[XYZ];

typedef struct {
    Sint16 x,y,z,L;
}   ptTransfer;

typedef struct {
    Uint16 dir, pt1,pt2,pt3,pt4, texid; // Points and also the texture ID of the face.
} FXFACE;


typedef struct {
    Uint16 PTC,FC, FRC, TexOffset;
    FP8 *PNTBL;
    FXFACE *FINDX;
    Uint8 *NINDX;
}   PFXDATA;



Uint16 FxClipDataSprite(Uint16 Dir,Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, char* OrOut); // if OrOut = -1, it means its either out of range, not facing the screen, or something else
void fxDrawPoly(int TexID, Uint16 Dir, char Orientation, Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, Uint16 Gouraud, Uint16 CMode ,FIXED Z);
void fxDrawGen(int TexID, Uint16 Dir, Uint16 Color, Sint16 XA, Sint16 YA, Sint16 XB, Sint16 YB, Sint16 XC, Sint16 YC, Sint16 XD, Sint16 YD, Uint16 Gouraud, Uint16 CMode ,Sint16 Z);
void DrawSprite(int TexID, Sint16 X, Sint16 Y, Sint16 Depth);
void FXDrawMeshStatic(PFXDATA *Mesh, Uint16 CMode);
void FXDrawMeshStaticShaded(PFXDATA *Mesh, Uint16 CMode, FIXED * LVec);
void FXDrawMeshAnimFlat(PFXDATA *Mesh, Uint16 CMode, FIXED Lerp); // Draws animated Mesh without shading
void FXDrawMeshAnim(PFXDATA *Mesh, Uint16 CMode, FIXED Lerp, FIXED *LVec); // Draws animated Mesh without shading
void SetSceneColour(Sint16 R, Sint16 G, Sint16 B);

void GouraudUpdate();
void LoadMeshFromSSV(char* FileName, PFXDATA* FOXDATA, Uint16 TexOffset);

static inline fxPlane(Uint16 PLANE) {
            slCurRpara(PLANE);
            slScrMatConv();
            slScrMatSet();
};
#endif