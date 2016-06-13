#include "test.h"
#include "test_p.h"

int global_test1_bss;
int global_test1_init = TEST1_INIT;
const int global_const_test1_bss = 0;
const int global_const_test1_init = CONST_TEST1_INIT;

__root void call_me_first_to_setup_variables_value_test1()
{
    global_test1_bss = TEST1_BSS;
}

__root int get_global_test2_bss()
{
    return global_test2_bss;
}

__root int get_global_test2_init()
{
    return global_test2_init;
}

__root int get_global_const_test2_bss()
{
    return global_const_test2_bss;
}

__root int get_global_const_test2_init()
{
    return global_const_test2_init;
}
