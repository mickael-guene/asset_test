#ifndef __TEST__
#define __TEST__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

#define TEST1_BSS               0x733939d5
#define TEST1_INIT              0xed23168d
#define CONST_TEST1_INIT        0x02beaacb
#define TEST2_BSS               0xf724ba17
#define TEST2_INIT              0x7c0ed73a
#define CONST_TEST2_INIT        0x80572ecd

void call_me_first_to_setup_variables_value_test1(void);
void call_me_first_to_setup_variables_value_test2(void);

int get_global_test1_bss(void);
int get_global_test1_init(void);
int get_global_const_test1_bss(void);
int get_global_const_test1_init(void);
int get_global_test2_bss(void);
int get_global_test2_init(void);
int get_global_const_test2_bss(void);
int get_global_const_test2_init(void);

#ifdef __cplusplus
};
#endif 	


#endif  /* __TEST__ */
