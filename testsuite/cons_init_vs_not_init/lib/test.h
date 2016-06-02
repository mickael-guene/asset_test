#ifndef __TEST__
#define __TEST__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

#define __root

#define NB                  4

int get_global_const_test1_bss(void);
int get_global_const_test2_bss(void);
int get_global_const_bss_elt(int idx);

#ifdef __cplusplus
};
#endif 	


#endif  /* __HELLO__ */
