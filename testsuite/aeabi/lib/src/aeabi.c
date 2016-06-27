#include "aeabi.h"

extern int __aeabi_uread4(void *address);
int value = AEABI_READ_VALUE;

__root int get_aeabi_read_value()
{
    return __aeabi_uread4(&value);
}
