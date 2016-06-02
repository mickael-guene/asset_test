#include <string.h>

#include "diskio.h"

#define RAMDISK_SECTOR_COUNT            128
#define RAMDISK_SECTOR_SIZE             512


static char ramdisk[RAMDISK_SECTOR_COUNT][RAMDISK_SECTOR_SIZE];

DSTATUS disk_initialize(BYTE pdrv)
{
    return RES_OK;
}

DSTATUS disk_status(BYTE pdrv)
{
    return RES_OK;
}

DRESULT disk_read(BYTE pdrv, BYTE* buff, DWORD sector, UINT count)
{
    int i;

    for(i = 0; i < count; i++)
        memcpy(buff, ramdisk[sector + i], RAMDISK_SECTOR_SIZE);

    return RES_OK;
}

DRESULT disk_write (BYTE pdrv, const BYTE* buff, DWORD sector, UINT count)
{
    int i;

    for(i = 0; i < count; i++)
        memcpy(ramdisk[sector + i], buff, RAMDISK_SECTOR_SIZE);

    return RES_OK;
}

DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff)
{
    DRESULT res;

    switch(cmd) {
        case CTRL_SYNC:
            res = RES_OK;
            break;
        case GET_SECTOR_COUNT:
            *(DWORD *) buff = RAMDISK_SECTOR_COUNT;
            res = RES_OK;
            break;
        case GET_SECTOR_SIZE:
            *(DWORD *) buff = RAMDISK_SECTOR_SIZE;
            res = RES_OK;
            break;
        case GET_BLOCK_SIZE:

        default:
            res = RES_ERROR;
    }

    return res;
}
