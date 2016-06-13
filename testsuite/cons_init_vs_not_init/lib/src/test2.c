#include "test.h"
#include "test_p.h"

const int global_const_test2_bss;

__root int get_global_const_test1_bss()
{
    return global_const_test1_bss;
}
