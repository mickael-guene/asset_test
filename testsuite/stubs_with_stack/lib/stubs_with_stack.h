#ifndef __STUBS_WITH_STACK__
#define __STUBS_WITH_STACK__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

struct four_values {
    int a;
    int b;
    int c;
    int d;
};

int get_param5_value(int param1, int param2, int param3, int param4, int param5);
int get_param5_xor_param6_value(int param1, int param2, int param3, int param4, int param5, int param6);
struct four_values get_param3_to_param6_values(int param1, int param2, int param3, int param4, int param5, int param6);

#ifdef __cplusplus
};
#endif 	


#endif  /* __STUBS_WITH_STACK__ */
