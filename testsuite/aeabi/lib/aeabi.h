#ifndef __AEABI__
#define __AEABI__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

#define AEABI_READ_VALUE    0xdeafbeef

int get_aeabi_read_value(void);

#ifdef __cplusplus
};
#endif 	


#endif  /* __AEABI__ */
