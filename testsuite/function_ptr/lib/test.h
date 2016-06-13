#ifndef __TEST__
#define __TEST__   1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 	

#define KEY_VALUE_0         0x6a3546a4
#define KEY_VALUE_1         0x9b63edc0

enum key_idx {
    KEY_IDX_0,
    KEY_IDX_1,
};

typedef int (*get_key_cb)(void);

get_key_cb get_key_fct(enum key_idx idx);

#ifdef __cplusplus
};
#endif 	


#endif  /* __TEST__ */
