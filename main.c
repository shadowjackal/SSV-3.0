//  Include
#include "foxgfx.h"
#include "foxfs.h"


    extern Sint8 SynchConst;

//  Functions
int main(void)
{
    PFXDATA Sonic;

    //  Initialize Systems 
    slInitSystem(TV_320x224, NULL, 0);
    slDynamicFrame(ON);
    SynchConst = 2;

    InitFS();
    slZdspLevel(6);

    LoadMeshFromSSV("SNC.SSV",&Sonic,0);
    slSetScreenDist(toFIXED(200));
    LoadTGA("SONIC_11.TGA"); // Tex No 0
    LoadTGA("SONIC_09.TGA"); // Tex No 1
    LoadTGA("SONIC_08.TGA"); // Tex No 2
    LoadTGA("SONIC_05.TGA"); // Tex No 3
    LoadTGA("SONIC_03.TGA"); // Tex No 4
    LoadTGA("SONIC_04.TGA"); // Tex No 5
    LoadTGA("SONIC_01.TGA"); // Tex No 6
    LoadTGA("SONIC_02.TGA"); // Tex No 7
    LoadTGA("SONIC_15.TGA"); // Tex No 8
    LoadTGA("SONIC_12.TGA"); // Tex No 9
    LoadTGA("SONIC_14.TGA"); // Tex No 10
    LoadTGA("SONIC_10.TGA"); // Tex No 11
    LoadTGA("SONIC_06.TGA"); // Tex No 12
    LoadTGA("SONIC_07.TGA"); // Tex No 13


    int AngleX = 0;
    int AngleY = DEGtoANG(-90);
    int AngleZ = 0;

    FIXED MoveX = toFIXED(0);
    FIXED MoveY = toFIXED(-30);
    FIXED MoveZ = (-4);

    FIXED LVec[3] = {toFIXED(0.5),toFIXED(0.5),0};
    SetSceneColour(15,15,15);

     FIXED Lerp = 0;
     FIXED CurPos[XYZ] = {0,0,0};
        FIXED TarPos[XYZ] = {0,0,toFIXED(1)};
    //  Start Main Game Loop4
    while(1)
	{

        slUnitMatrix(CURRENT);
        Uint16 DataC = Smpc_Peripheral[0].data;

        if((DataC & pad_asign[4])==0) AngleX+=360;
        if((DataC & pad_asign[5])==0) AngleY+=360;
        if((DataC & pad_asign[6])==0) AngleZ+=360;

        if((DataC & pad_asign[0])==0) MoveY += toFIXED(1);
        if((DataC & pad_asign[1])==0) MoveY -= toFIXED(1);
        if((DataC & pad_asign[2])==0) MoveX += toFIXED(1);
        if((DataC & pad_asign[3])==0) MoveX -= toFIXED(1);
        if((DataC & pad_asign[11])==0) MoveZ += toFIXED(1);
        if((DataC & pad_asign[12])==0) MoveZ -= toFIXED(1);

        if((DataC & pad_asign[9])==0) Lerp += toFIXED(0.4);
        if((DataC & pad_asign[10])==0) Lerp -= toFIXED(0.4);

	if(Lerp < 0) Lerp = 0;
	if(Lerp > Sonic.FRC<<16) Lerp = 0;


        CurPos[0] = MoveX;
        TarPos[0] = MoveX;

        CurPos[2] = MoveY;
        TarPos[2] = MoveY+toFIXED(1);
        TarPos[1] = MoveZ;
        CurPos[1] = MoveZ;


        slLookAt(&CurPos,&TarPos,0);

        // Update RBG0 layer
        slPushMatrix();
        {
            slTranslate(0,toFIXED(0),0);
            slRotX(AngleX);
            slRotY(AngleY);
            FXDrawMeshAnim(&Sonic, CL_Gouraud | CL_Replace, Lerp, LVec);
            slPopMatrix();
        }
        slPopMatrix();

slPrint("Push A and B to rotate",slLocate(0,0));
slPrint("Push Y and Z to loop through animation",slLocate(0,1));
slPrint("DPad to Move and L and R for up and down", slLocate(0,2));
slPrint("Frame : ",slLocate(0,3)); slPrintFX(Lerp,slLocate(6,3));
        GouraudUpdate();
        slSynch();
	}
    
    //  End Program
	return 0;
}
 