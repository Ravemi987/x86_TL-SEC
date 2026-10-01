#include <stdlib.h>
#include <stdio.h>

unsigned int fac(unsigned int x) {
  unsigned int r = 1;
  unsigned int i;
  for (i = 2; i <= x; i++) {
    r *= i;
  }
  return r;
}

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);
  if (argc < 2) {
    return 1;
  }
  printf("fac(%s) = %u\n", argv[1], fac(atoi(argv[1])));
  return 0;
}
