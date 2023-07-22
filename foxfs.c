#include "common.h"
#include "foxfs.h"

GfsDirName dir_name[MAX_DIR];
GfsDirTbl	dir_tbl;
Uint8 gfs_work[GFS_WORK_SIZE(OPEN_MAX)];
unsigned char Heap[256000];
unsigned char LoadingHeap[128000];

int nextFreeIndex = 0;
int totalBlocks = 0;
int nextFreeFreed = 0;
unsigned int amtUsed = 0;
int          swap_endian_sint(   int value)   { return ((((value) & 0xff000000) >> 24) | (((value) & 0x00ff0000) >>  8) | (((value) & 0x0000ff00) <<  8) | (((value) & 0x000000ff) << 24)); }
short          swap_endian_sshort( short value)   { return (((value >> 8)&0xFF) | ((value & 0xFF) << 8));}



void InitFS(void)
{
	Sint32 file_num;

    /* Initialize the file system */
	GFS_DIRTBL_TYPE(&dir_tbl) = GFS_DIR_NAME;
	GFS_DIRTBL_DIRNAME(&dir_tbl) = dir_name;
	GFS_DIRTBL_NDIR(&dir_tbl) = MAX_DIR;
    file_num = GFS_Init(OPEN_MAX, gfs_work, &dir_tbl);
	if (file_num < 0) {
		return;
	}

};

GfsHn OpenFS(char *fname)
{
    Sint32 fid;

    /* Find the file identifier from the file name */
    fid = GFS_NameToId(fname);
    return GFS_Open(fid);
};

void CloseFS(GfsHn fp)
{
	GFS_Close(fp);
};

Sint32 SizeFS(GfsHn File) {
    Sint32 sctsz, nsct, lstsz;
    GFS_GetFileSize(File,&sctsz,&nsct,&lstsz);
    return sctsz * (nsct - 1) + lstsz;
};
 
int OpenFileSimple(Sint8 *FileName, void *Destination) { // Opens a File and dumps into a destination, make sure destination wont override anything
    GfsHn File = OpenFS(FileName);
     Sint32 sctsz, nsct, lstsz;
    GFS_GetFileSize(File,&sctsz,&nsct,&lstsz);
    Sint32 FileSizeTrue = sctsz * (nsct - 1) + lstsz;
    CloseFS(File);
    int fid = GFS_NameToId(FileName);

    GFS_Load(fid,0,(void *)Destination,FileSizeTrue);
    return FileSizeTrue;
};
