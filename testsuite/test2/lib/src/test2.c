#include "test.h"
#include "test_p.h"

int global_test2_bss;
int global_test2_init = TEST2_INIT;
const int global_const_test2_bss = 0;
const int global_const_test2_init = CONST_TEST2_INIT;

void call_me_first_to_setup_variables_value_test2()
{
    global_test2_bss = TEST2_BSS;
}

int get_global_test1_bss()
{
    return global_test1_bss;
}

int get_global_test1_init()
{
    return global_test1_init;
}

int get_global_const_test1_bss()
{
    return global_const_test1_bss;
}

int get_global_const_test1_init()
{
    return global_const_test1_init;
}

