#include "stubs_with_stack.h"

__root int get_param5_value(int param1, int param2, int param3, int param4, int param5)
{
    return param5;
}

__root int get_param5_xor_param6_value(int param1, int param2, int param3, int param4, int param5, int param6)
{
    return param5 ^ param6;
}

__root struct four_values get_param3_to_param6_values(int param1, int param2, int param3, int param4, int param5, int param6)
{
    struct four_values res = {param3, param4, param5, param6};

    return res;
}
