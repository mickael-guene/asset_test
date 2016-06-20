#include <string.h>

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
