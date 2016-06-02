#include <stdlib.h>
#include <assert.h>

#include "test.h"

int main(int argc, char **argv)
{
    int i;

    for(i = 0; i < NB; i++)
        assert(get_static_bss_elt(i) == 0);

    for(i = 0; i < NB; i++)
        assert(get_bss_elt(i) == 0);

    call_me_first_to_setup_bss_value();

    for(i = 0; i < NB; i++)
        assert(get_static_bss_elt(i) == STATIC_BSS_BASE_VALUE + i);
    for(i = 0; i < NB; i++) 
        assert(get_static_init_elt(i) == STATIC_INIT_BASE_VALUE + i);
    for(i = 0; i < NB; i++)
        assert(get_static_const_elt(i) == STATIC_CONST_BASE_VALUE + i);
    for(i = 0; i < NB; i++)
        assert(get_static_const_bss_elt(i) == 0);

    for(i = 0; i < NB; i++)
        assert(get_bss_elt(i) == BSS_BASE_VALUE + i);
    for(i = 0; i < NB; i++)
        assert(get_init_elt(i) == INIT_BASE_VALUE + i);
    for(i = 0; i < NB; i++)
        assert(get_const_elt(i) == CONST_BASE_VALUE + i);
    for(i = 0; i < NB; i++)
        assert(get_const_bss_elt(i) == 0);

    return 0;
}
