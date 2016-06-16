#ifndef __HELLO__
#define __HELLO__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define __weak__ __attribute__((weak))

#define INT_WEAK_NOT_OVERLOAD_INIT_VALUE            2
#define INT_WEAK_OVERLOAD_INIT_VALUE_FOR_WEAK       3
#define INT_WEAK_OVERLOAD_INIT_VALUE                4
#define INT_CONST_WEAK_OVERLOAD_INIT_VALUE_FOR_WEAK 5
#define INT_CONST_WEAK_OVERLOAD_INIT_VALUE          6

int get_extern_weak_not_overload(void);
int get_extern_weak_overload(void);
int get_extern_const_weak_overload(void);

#ifdef __cplusplus
};
#endif

#endif  /* __HELLO__ */
