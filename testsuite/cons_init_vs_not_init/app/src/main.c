#include <stdlib.h>
#include <assert.h>

#include "test.h"

int main(int argc, char **argv)
{
    int i;

    assert(get_global_const_test1_bss() == 0);
    assert(get_global_const_test2_bss() == 0);
    for(i = 0; i < NB; i++)
        assert(get_global_const_bss_elt(i) == 0);

    return 0;
}
