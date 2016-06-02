#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "ff.h"

static FRESULT dump_free_info()
{
    FATFS *fs;
    DWORD fre_clust, fre_sect, tot_sect;
    FRESULT res;

    res = f_getfree("", &fre_clust, &fs);
    if (res)
        return res;
    tot_sect = (fs->n_fatent - 2) * fs->csize;
    fre_sect = fre_clust * fs->csize;

    /* Print the free space (assuming 512 bytes/sector) */
    printf("%10lu KiB total drive space.\n%10lu KiB available.\n", tot_sect / 2, fre_sect / 2);

    return res;
}

int main(int argc, char **argv)
{
    FATFS fs;
    FRESULT res;
    FIL fil;
    UINT bw;
    TCHAR buf[256];
    FILINFO fno;

    /* Register work area (do not care about error) */
    f_mount(&fs, "", 0);

    res = f_mkfs("", 0, 1);
    if (res) {
        printf("f_mkfs failed with error %d\n", res);
        assert(0);
    }

    printf("Mem info\n");
    res = dump_free_info();
    if (res) {
        printf("dump_free_info failed with error %d\n", res);
        assert(0);
    }

    /* Create a file as new */
    res = f_open(&fil, "hello.txt", FA_CREATE_NEW | FA_WRITE);
    if (res) {
        printf("f_open failed with error %d\n", res);
        assert(0);
    }

    /* Write a message */
    f_write(&fil, "Hello, World!\r\n", 15, &bw);
    if (bw != 15) {
        printf("f_write failed with error %d\n", bw);
        assert(0);
    }

    /* Close the file */
    f_close(&fil);

    /* get cwd */
    res = f_getcwd(buf, sizeof(buf));
    if (res) {
        printf("f_getcwd failed with error %d\n", res);
        assert(0);
    } else
        printf("cwd = %s\n", buf);

    /* get created file info */
    res = f_stat("hello.txt", &fno);
    if (res == FR_OK) {
        printf("Fname: %s\n", fno.fname);
        printf("Size: %lu\n", fno.fsize);
        printf("Timestamp: %u/%02u/%02u, %02u:%02u\n",
               (fno.fdate >> 9) + 1980, fno.fdate >> 5 & 15, fno.fdate & 31,
               fno.ftime >> 11, fno.ftime >> 5 & 63);
        printf("Attributes: %c%c%c%c%c\n",
               (fno.fattrib & AM_DIR) ? 'D' : '-',
               (fno.fattrib & AM_RDO) ? 'R' : '-',
               (fno.fattrib & AM_HID) ? 'H' : '-',
               (fno.fattrib & AM_SYS) ? 'S' : '-',
               (fno.fattrib & AM_ARC) ? 'A' : '-');
    } else if (res == FR_NO_FILE) {
        printf("It is not exist.\n");
        assert(0);
    } else {
        printf("An error occured. (%d)\n", res);
        assert(0);
    }

    /* Unregister work area */
    f_mount(0, "", 0);

    return 0;
}
