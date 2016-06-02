#include "test.h"

static int return_key_1(void);

static int return_key_0()
{
    return KEY_VALUE_0;
}

get_key_cb get_key_fct(enum key_idx idx)
{
    switch(idx) {
        case KEY_IDX_0:
            return return_key_0;
        case KEY_IDX_1:
            return return_key_1;
    }

    return 0;
}

static int return_key_1()
{
    return KEY_VALUE_1;
}
