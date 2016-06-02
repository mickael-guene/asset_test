#include <stdlib.h>
#include <assert.h>

#include "test.h"

/* NOTE : calling cb is ok only if you are sure these cb
 don't use global variables in library */

int main(int argc, char **argv)
{
    get_key_cb key0_cb = get_key_fct(KEY_IDX_0);
    get_key_cb key1_cb = get_key_fct(KEY_IDX_1);

    assert(key0_cb() == KEY_VALUE_0);
    assert(key1_cb() == KEY_VALUE_1);

    return 0;
}
