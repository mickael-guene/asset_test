#include <stdlib.h>
#include <assert.h>

#include "hello.h"

int main(int argc, char **argv)
{
    assert(get_hello_version() == GET_HELLO_VERSION);
    return 0;
}
