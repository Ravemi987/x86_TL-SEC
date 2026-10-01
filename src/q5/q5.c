#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int strlen_dumb(const char *str, unsigned int max) {
  unsigned int size = 0;
  while (*str != '\0' && size < max) {
    size++;
    str++;
  }
  return size;
}

// Une structure assez grosse pour ne pas tenir dans les registres
struct dumber {
  int c0;   int c1;   int c2;   int c3;
  int c4;   int c5;   int c6;   int c7;
  int c8;   int c9;   int c10;  int c11;
  int c12;  int c13;  int c14;  int c15;
};

void display_dumber(struct dumber d) {
  printf("%x %x %x %x\n%x %x %x %x\n%x %x %x %x\n%x %x %x %x\n",
      d.c0,   d.c1,   d.c2,   d.c3,
      d.c4,   d.c5,   d.c6,   d.c7,
      d.c8,   d.c9,   d.c10,  d.c11,
      d.c12,  d.c13,  d.c14,  d.c15
  );
  printf("Oui c'est un copie : %p !\n", &d);
}

int main(int argc, char *argv[]) {
  int size;
  printf("argc = %d, argv = %p\n", argc, argv);
  char str[] = "I love tls-secte";

  // Calcul de la taille de str à l'aide de strlen_dumb
  size = strlen_dumb(&str[0], 0x20);

  printf("\"%s\" string is 0x%08x bytes long\n", &str[0], size);

  struct dumber d = {
    .c0 = 0x0,  .c1 = 0x1,  .c2 = 0x2,  .c3 = 0x3,
    .c4 = 0x4,  .c5 = 0x5,  .c6 = 0x6,  .c7 = 0x7,
    .c8 = 0x8,  .c9 = 0x9,  .c10 = 0xa, .c11 = 0xb,
    .c12 = 0xc, .c13 = 0xd, .c14 = 0xe, .c15 = 0xf,
  };
  printf("Est-ce une copie :   %p ?\n", &d);
  display_dumber(d);

  return 0;
}
