#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <complex.h>
#include <math.h>

#include "fp.h"

#define SIZEOF(arr) (sizeof(arr)/sizeof(0[arr]))

int main(int argc, char *argv[])
{
  static long long const ll[] = { -1LL, 0LL, 1LL };
  static float const f[] = { -1.0f, -0.0f, 0.0f, 1.0f };
  static _Complex float const cf[] = { -1.0f -I, -I, -1.0f, -0.0f, 0.0f, 1.0f, I, 1.0f+I };
  static double const d[] = { -1.0, -0.0, 0.0, 1.0 };
  static _Complex double const cd[] = { -1.0 -I, -I, -1.0, -0.0, 0.0, 1.0, I, 1.0+I };
  static long double const ld[] = { -1.0, -0.0, 0.0, 1.0 };
  static _Complex long double const cld[] =  { -1.0 -I, -I, -1.0, -0.0, 0.0, 1.0, I, 1.0+I };
  static const double const cstd[] = { M_E, M_LOG2E, M_LOG10E, M_LN2, M_LN10, M_PI, M_PI_2, M_PI_4, M_1_PI, M_2_PI, M_2_SQRTPI, M_SQRT2, M_SQRT1_2 }; 
  printf("Tests started from %s\n", argv[0]);
  for(int i=0; i<SIZEOF(ll); ++i)
    assert(ll[i]*ll[i] == psquarell(ll[i]));
  for(int i=0; i<SIZEOF(f); ++i)
    assert(f[i]*f[i] == psquaref(f[i]));
  for(int i=0; i<SIZEOF(cf); ++i)
    assert(cf[i]*cf[i] == psquarecf(cf[i]));
  for(int i=0; i<SIZEOF(d); ++i)
    assert(d[i]*d[i] == psquared(d[i]));
  for(int i=0; i<SIZEOF(cd); ++i)
    assert(cd[i]*cd[i] == psquarecd(cd[i]));
  for(int i=0; i<SIZEOF(ld); ++i)
    assert(ld[i]*ld[i] == psquareld(ld[i]));
  for(int i=0; i<SIZEOF(cld); ++i)
    assert(cld[i]*cld[i] == psquarecld(cld[i]));
  for(int i=0; i<SIZEOF(cstd); ++i)
    assert(cstd[i]==gcstd(i));
#if 0
  /* we disable this test since it will generate R_ARM_ABS32 relocation that
     will be solved when we generate temporary executable. So addresses will
     be wrong. */
  /* FIXME : See if we can generate other code sequence in gcc for this case */
  for(int i=0; i<SIZEOF(cstd); ++i)
    assert(cstd[i]==gcstjmpd(i));
#endif
  puts("Tests completed");
  return 0;
}
