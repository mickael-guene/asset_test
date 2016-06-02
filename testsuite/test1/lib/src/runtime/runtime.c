#include <string.h>

/* these two variables force presence of ro segment and rw segment */
static const int __force_rodata_present__ __attribute__((used)) = 0;
static int __force_rwdata_present__ __attribute__((used)) = 0;

void *memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    while(n--)
        *d++ = *s++;

    return dest;
}

void *memset(void *s, int c, size_t n)
{
    char *dst = s;

    while(n--)
        *dst++ = c;

    return s;
}
