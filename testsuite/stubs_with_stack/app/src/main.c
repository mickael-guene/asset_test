#include <stdlib.h>
#include <assert.h>

#include "stubs_with_stack.h"

int main(int argc, char **argv)
{
    assert(get_param5_value(1,2,3,4,5) == 5);
    assert(get_param5_xor_param6_value(1,2,3,4,0xabde1234, 0x5a5aabcd) == (0xabde1234 ^ 0x5a5aabcd));
    {
        struct four_values res = get_param3_to_param6_values(1,2,3,4,5,6);

        assert(res.a == 3 && res.b == 4 && res.c == 5 && res.d == 6);
    }

    return 0;
}
