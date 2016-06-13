#ifndef __TEST__
#define __TEST__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

#define NB          4

#define STATIC_BSS_BASE_VALUE                   0x6f360ba0
#define STATIC_INIT_BASE_VALUE                  0x4a8b478e
#define STATIC_CONST_BASE_VALUE                 0x233a893c

#define BSS_BASE_VALUE                          0xa2def09d
#define INIT_BASE_VALUE                         0xbaab2a71
#define CONST_BASE_VALUE                        0x23fcb23b

void call_me_first_to_setup_bss_value(void);

int get_static_bss_elt(int idx);
int get_static_init_elt(int idx);
int get_static_const_elt(int idx);
int get_static_const_bss_elt(int idx);
int get_bss_elt(int idx);
int get_init_elt(int idx);
int get_const_elt(int idx);
int get_const_bss_elt(int idx);

#ifdef __cplusplus
};
#endif 	


#endif  /* __TEST__ */
