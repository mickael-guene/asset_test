#include "test.h"
#include "test_p.h"

int global_test2_bss;
int global_test2_init = TEST2_INIT;
const int global_const_test2_bss = 0;
const int global_const_test2_init = CONST_TEST2_INIT;

__root void call_me_first_to_setup_variables_value_test2()
{
    global_test2_bss = TEST2_BSS;
}

__root int get_global_test1_bss()
{
    return global_test1_bss;
}

__root int get_global_test1_init()
{
    return global_test1_init;
}

__root int get_global_const_test1_bss()
{
    return global_const_test1_bss;
}

__root int get_global_const_test1_init()
{
    return global_const_test1_init;
}

