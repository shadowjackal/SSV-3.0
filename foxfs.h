#ifndef _FS_H_
#define _FS_H_
#include "common.h"

typedef struct HeapInstance {
    char* HeapPtr;
    int size; // in bytes
    int totalUsed;
    int Blocks;
} HeapInstance;

typedef struct Block {
    void* Start;
    int size;
    char free;
} Block;


void* FxMalloc(int size, int Fast);

void  FxFree(void *Location);

#define OPEN_MAX 4
#define MAX_DIR 50
#define GFS_ON 1
extern unsigned int amtUsed;
extern GfsDirName dir_name[MAX_DIR];
extern GfsDirTbl	dir_tbl;
extern Uint8 gfs_work[GFS_WORK_SIZE(OPEN_MAX)];
extern unsigned char Heap[256000]; // WARNING : Manage this manually, you shouldn't need an allocator, just keep track of where you do stuff.
extern unsigned char LoadingHeap[128000]; //for loading

int          swap_endian_sint(   int value);
short          swap_endian_sshort( short value);

void InitFS(void);

GfsHn OpenFS(char *fname);
void CloseFS(GfsHn fp);
Sint32 SizeFS(GfsHn File);
int OpenFileSimple(Sint8 *FileName, void *Destination); // Opens a File and dumps into a destination, make sure destination wont override anything
#endif