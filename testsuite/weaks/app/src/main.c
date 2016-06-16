#include <stdlib.h>
#include <assert.h>

#include "test.h"

int main(int argc, char **argv)
{
    assert(get_extern_weak_not_overload() == INT_WEAK_NOT_OVERLOAD_INIT_VALUE);
    assert(get_extern_weak_overload() == INT_WEAK_OVERLOAD_INIT_VALUE);
    assert(get_extern_const_weak_overload() == INT_CONST_WEAK_OVERLOAD_INIT_VALUE);

    return 0;
}
