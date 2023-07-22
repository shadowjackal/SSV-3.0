#ifndef _COMMON_H_
#define _COMMON_H_

#include    "SGL.H"
#include "SEGA_GFS.H"

enum DirFlip{
    noFlip,
    vFlip,
    hFlip,
    hvFlip
};

static Uint16 pad_asign[]={
PER_DGT_KU,
PER_DGT_KD,
PER_DGT_KR,
PER_DGT_KL,
PER_DGT_TA,
PER_DGT_TB,
PER_DGT_TC,
PER_DGT_ST,
PER_DGT_TX,
PER_DGT_TY,
PER_DGT_TZ,
PER_DGT_TR,
PER_DGT_TL,
};

typedef Sint16 FIXED8;
#define     toFIXED8(n)         (FIXED8)(n*256.0)


#endif