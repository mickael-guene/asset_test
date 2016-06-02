#include "test.h"
#include "test_p.h"

const int global_const_test1_bss;
const int const_bss_array[NB];

int get_global_const_test2_bss()
{
    return global_const_test2_bss;
}

int get_global_const_bss_elt(int idx)
{
    return const_bss_array[idx];
}
