#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "test.h"

int main(int argc, char **argv)
{
    call_me_first_to_setup_variables_value();

    assert(get_static_int_bss() == TEST_STATIC_INT_BSS_VALUE);
    assert(get_global_int_bss() == TEST_GLOBAL_INT_BSS_VALUE);
    assert(*get_static_int_init_ptr() == TEST_STATIC_INT_INIT_VALUE);
    assert(get_global_int_init() == TEST_GLOBAL_INT_INIT_VALUE);
    assert(*get_const_static_int_ptr() == TEST_CONST_STATIC_INT_VALUE);
    assert(*get_const_global_int_ptr() == TEST_CONST_GLOBAL_INT_VALUE);

    assert(memcmp(get_static_ptr(), TEST_STATIC_PTR_CONTENT, sizeof(TEST_STATIC_PTR_CONTENT)) == 0);
    assert(memcmp(get_global_ptr(), TEST_GLOBAL_PTR_CONTENT, sizeof(TEST_GLOBAL_PTR_CONTENT)) == 0);
    assert(memcmp(get_const_char_ptr(), TEST_CONST_CHAR_PTR_CONTENT, sizeof(TEST_CONST_CHAR_PTR_CONTENT)) == 0);

    return 0;
}
