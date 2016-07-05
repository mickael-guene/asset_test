#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

#include "nocxx.h"

bool p(int x, int y) {
  return predicate(x,y);
}

int main(int argc, char *argv[])
{
  printf("Tests started from %s\n", argv[0]);
  std::vector<int> iv = { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };
  std::sort(iv.begin(), iv.end(), p);
  assert(std::is_sorted(iv.begin(), iv.end(), p));
  puts("Tests completed");
  return 0;
}
