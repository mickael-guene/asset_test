#ifndef _FP_H_
#define _FP_H_

#if defined(__cplusplus)
extern "C" {
#endif

long long psquarell(long long x);
float psquaref(float x);
_Complex float psquarecf(_Complex float x);
double psquared(double x);
_Complex double psquarecd(_Complex double x);
long double psquareld(long double x);
_Complex long double psquarecld(_Complex long double x);

double gcstd(int);
double gcstjmpd(int);

#if defined(__cplusplus)
}
#endif

#endif //_FP_H_
