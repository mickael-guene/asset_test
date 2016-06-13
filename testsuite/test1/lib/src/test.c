#include <string.h>

#include "test.h"

static int static_int_bss;
int global_int_bss;
static int static_int_init = TEST_STATIC_INT_INIT_VALUE;
int global_int_init = TEST_GLOBAL_INT_INIT_VALUE;
static const int const_static_int = TEST_CONST_STATIC_INT_VALUE;
const int const_global_int = TEST_CONST_GLOBAL_INT_VALUE;
static char static_ptr[256];
char global_ptr[256];

__root void call_me_first_to_setup_variables_value()
{
    static_int_bss = TEST_STATIC_INT_BSS_VALUE;
    global_int_bss = TEST_GLOBAL_INT_BSS_VALUE;
    memcpy(static_ptr, TEST_STATIC_PTR_CONTENT, sizeof(TEST_STATIC_PTR_CONTENT));
    memcpy(global_ptr, TEST_GLOBAL_PTR_CONTENT, sizeof(TEST_GLOBAL_PTR_CONTENT));
}

__root int get_static_int_bss()
{
    return static_int_bss;
}

__root int get_global_int_bss()
{
    return global_int_bss;
}

__root int *get_static_int_init_ptr()
{
    return &static_int_init;
}

__root int get_global_int_init()
{
    return global_int_init;
}

__root const int *get_const_static_int_ptr()
{
    return &const_static_int;
}

__root const int *get_const_global_int_ptr()
{
    return &const_global_int;
}

__root char *get_static_ptr()
{
    return static_ptr;
}

__root char *get_global_ptr()
{
    return global_ptr;
}

__root char *get_const_char_ptr()
{
    return TEST_CONST_CHAR_PTR_CONTENT;
}
