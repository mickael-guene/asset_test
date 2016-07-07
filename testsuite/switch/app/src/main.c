#include <stdio.h>
#include <assert.h>

#include "switch.h"

int main(int argc, char *argv[])
{
  printf("Tests started from %s\n", argv[0]);
  for(char c='0'; c<= '9'; ++c)
    assert(c-'0' == icswitch(c));
  puts("Tests completed");
  return 0;
}
