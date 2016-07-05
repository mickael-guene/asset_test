#include <math.h>

#include "fp.h"

// Pulling symbols from libgcc.a
__root long long psquarell(long long x) {
  __attribute__((noinline)) long long square(long long x) { return x*x; }
  return square(x);
}

__root float psquaref(float x) {
  __attribute__((noinline)) float square(float x) { return x*x; }
  return square(x);
}

__root _Complex float psquarecf(_Complex float x) {
  return x*x;
}

__root double psquared(double x) {
  return x*x;
}

__root _Complex double psquarecd(_Complex double x) {
  return x*x;
}

__root long double psquareld(long double x) {
  return x*x;
}

__root _Complex long double psquarecld(_Complex long double x) {
  return x*x;
}

// Creating some constants
__root double gcstd(int idx) {
  static const double const d[] = { M_E, M_LOG2E, M_LOG10E, M_LN2, M_LN10, M_PI, M_PI_2, M_PI_4, M_1_PI, M_2_PI, M_2_SQRTPI, M_SQRT2, M_SQRT1_2 }; 
  if (idx>=0 && idx<sizeof(d)/sizeof(0[d]))
    return d[idx];
  else
    return __builtin_nan("");
}

__root double gcstjmpd(int idx) {
  static const void * const jmp[] = { &&E, &&LOG2E, &&LOG10E, &&LN2, &&LN10, &&PI, &&PI_2, &&PI_4, &&C1_PI, &&C2_PI, &&C2_SQRTPI, &&SQRT2, &&SQRT1_2 }; 
  if (idx>=0 && idx<sizeof(jmp)/sizeof(0[jmp]))
    goto *jmp[idx];
  else
    return __builtin_nan("");
 E: return M_E;
 LOG2E: return M_LOG2E;
 LOG10E: return M_LOG10E;
 LN2: return M_LN2;
 LN10: return M_LN10;
 PI: return M_PI;
 PI_2: return M_PI_2;
 PI_4: return M_PI_4;
 C1_PI: return M_1_PI;
 C2_PI: return M_2_PI;
 C2_SQRTPI: return M_2_SQRTPI;
 SQRT2: return M_SQRT2;
 SQRT1_2: return M_SQRT1_2 ;
 UNDEFINED:
  __builtin_unreachable();
}
