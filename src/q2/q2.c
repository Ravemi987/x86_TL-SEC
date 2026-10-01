#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cpuid {
  int s1;
  int s2;
  int s3;
  int s4;
};

void cpuid_display(struct cpuid *in) {
  printf("s1(0x%08x), s2(0x%08x), s3(0x%08x), s4(0x%08x)\n",
      in->s1,
      in->s2,
      in->s3,
      in->s4
  );
}

void cpuid(int func, struct cpuid *out) {
  __asm__ volatile(
    "cpuid"
    : "=a" (out->s1),
      "=b" (out->s2),
      "=c" (out->s3),
      "=d" (out->s4)
    : "a" (func)
  );

  printf("Fonction demandée(0x%08x)\n", func);
}

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);

  // Déclaration de la variable de sortie
  struct cpuid out;

  // Appel de la fonction cpuid pour le constructeur
  cpuid(0x0, &out);

  char cons[13];
  memcpy(cons, &out.s2, 4);
  memcpy(cons + 4, &out.s4, 4);
  memcpy(cons + 8, &out.s3, 4);
  cons[12] = '\0';

  // Traitement du résultat et affichages
  cpuid_display(&out);

  printf("Nom du constructeur : %s\n", cons);

  // Appel de la fonction cpuid pour les fréquences
  cpuid(0x16, &out);

  // Traitement du résultat et affichages
  cpuid_display(&out);

  printf("Base : %d, Max : %d, Bus : %d\n", out.s1, out.s2, out.s3);

  return 0;
}
