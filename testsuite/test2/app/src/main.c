#include <stdlib.h>
#include <assert.h>

#include "test.h"

int main(int argc, char **argv)
{
    call_me_first_to_setup_variables_value_test1();
    call_me_first_to_setup_variables_value_test2();

    assert(get_global_test1_bss() == TEST1_BSS);
    assert(get_global_test1_init() == TEST1_INIT);
    assert(get_global_const_test1_bss() == 0);
    assert(get_global_const_test1_init() == CONST_TEST1_INIT);
    assert(get_global_test2_bss() == TEST2_BSS);
    assert(get_global_test2_init() == TEST2_INIT);
    assert(get_global_const_test2_bss() == 0);
    assert(get_global_const_test2_init() == CONST_TEST2_INIT);

    return 0;
}
