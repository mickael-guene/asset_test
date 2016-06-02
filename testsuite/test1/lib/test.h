#ifndef __TEST__
#define __TEST__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

#define __root

#define TEST_STATIC_INT_BSS_VALUE           0x40baa114
#define TEST_GLOBAL_INT_BSS_VALUE           0x16f1b9f2
#define TEST_STATIC_INT_INIT_VALUE          0x0f9f9b56
#define TEST_GLOBAL_INT_INIT_VALUE          0x669b22ce
#define TEST_CONST_STATIC_INT_VALUE         0x9f6b531a
#define TEST_CONST_GLOBAL_INT_VALUE         0x83c8efc5

#define TEST_STATIC_PTR_CONTENT             "3b8ab587-4fda-455e-bc00-f45f39f4400d"
#define TEST_GLOBAL_PTR_CONTENT             "832427c6-70fb-424c-a298-06a9be19772e"
#define TEST_CONST_CHAR_PTR_CONTENT         "ad4ea3b9-4b4e-446f-b3d4-a457f2a2e467"


void call_me_first_to_setup_variables_value(void);

int get_static_int_bss(void);
int get_global_int_bss(void);
int *get_static_int_init_ptr(void);
int get_global_int_init(void);
const int *get_const_static_int_ptr(void);
const int *get_const_global_int_ptr(void);

char *get_static_ptr(void);
char *get_global_ptr(void);
char *get_const_char_ptr(void);

#ifdef __cplusplus
};
#endif 	


#endif  /* __TEST__ */
