#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
void *memcpy(void dest[restrict .n], const void src[restrict .n], size_t n);

movsb 
*/
void memcpy_asm(char *dst, const char *src, unsigned int size) {
  printf("dst(%p), src(%p), size(0x%08x)\n", dst, src, size);
  __asm__ volatile(
    "cld\n\t"       // direction vers l'avant (dans le sens inverse de la pile)
    "rep movsb"
    : "+D" (dst),   // D : rdi, + car lu et modifié
      "+S" (src),   // S : rsi, + car lu et modifié
      "+c" (size)   // c : rcx, + car lu et modifié
    :               // Il n'y a pas d'entrée pur, ce sont toutes des entrées-sorties
    : "memory"      // On écrit dans la mémoire (sinon la copie n'existe plus dans le C)
  );
}

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);
  char str1[] = "I love tls-secte";
  char str2[sizeof(str1)];
  // Copie à remplacer par memcpy_asm()
  memcpy_asm(&str2[0], &str1[0], sizeof(str1));
  printf("How do I do (%p) ? %s\n", &str2[0], &str2[0]);
  return 0;
}
