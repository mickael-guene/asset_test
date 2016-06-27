#include <stdlib.h>
#include <assert.h>

#include "aeabi.h"

int main(int argc, char **argv)
{
    assert(get_aeabi_read_value() == AEABI_READ_VALUE);
    return 0;
}
