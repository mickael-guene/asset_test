#include "test.h"

extern __weak__ int int_weak_not_overload;
__weak__ int int_weak_overload = INT_WEAK_OVERLOAD_INIT_VALUE_FOR_WEAK;
__weak__ const int const_int_weak_overload = INT_CONST_WEAK_OVERLOAD_INIT_VALUE_FOR_WEAK;

__root int get_extern_weak_not_overload()
{
    return int_weak_not_overload;
}

__root int get_extern_weak_overload()
{
    return int_weak_overload;
}

__root int get_extern_const_weak_overload()
{
    return const_int_weak_overload;
}