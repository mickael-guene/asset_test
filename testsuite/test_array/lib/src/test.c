#include "test.h"

static int static_bss_array[NB];
static int static_init_array[NB] = {STATIC_INIT_BASE_VALUE, STATIC_INIT_BASE_VALUE+ 1,
                                    STATIC_INIT_BASE_VALUE + 2, STATIC_INIT_BASE_VALUE + 3};
static const int static_const_array[NB] = {STATIC_CONST_BASE_VALUE, STATIC_CONST_BASE_VALUE + 1,
                                           STATIC_CONST_BASE_VALUE + 2, STATIC_CONST_BASE_VALUE + 3};
static const int static_const_bss_array[NB] = {0};

int bss_array[NB];
int init_array[NB] = {INIT_BASE_VALUE, INIT_BASE_VALUE + 1, INIT_BASE_VALUE + 2, INIT_BASE_VALUE + 3};
const int const_array[NB] = {CONST_BASE_VALUE, CONST_BASE_VALUE + 1, CONST_BASE_VALUE + 2, CONST_BASE_VALUE+ 3};
const int const_bss_array[NB] = {0};

void call_me_first_to_setup_bss_value()
{
    int i;

    for(i = 0; i < NB; i++) {
        static_bss_array[i] = STATIC_BSS_BASE_VALUE + i;
        bss_array[i] = BSS_BASE_VALUE + i;
    }
}

int get_static_bss_elt(int idx)
{
    return static_bss_array[idx];
}

int get_static_init_elt(int idx)
{
    return static_init_array[idx];
}

int get_static_const_bss_elt(int idx)
{
    return static_const_bss_array[idx];
}

int get_static_const_elt(int idx)
{
    return static_const_array[idx];
}

int get_bss_elt(int idx)
{
    return bss_array[idx];
}

int get_init_elt(int idx)
{
    return init_array[idx];
}

int get_const_elt(int idx)
{
    return const_array[idx];
}

int get_const_bss_elt(int idx)
{
    return const_bss_array[idx];
}
