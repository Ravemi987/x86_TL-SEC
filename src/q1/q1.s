// Export du symbole fac_asm pour utilisation possible dans d'autres
// fichiers i.e src/q1/bs.c
.global fac_asm


// Calcul de factorielle
// paramètre : x dans %rax
// retour : placé dans %rax
fac_asm:

  // Sauvegarde et définition du contexte
  // push décrémente rsp de 4 et écrit la valeur
  push %rbp
  mov %rsp, %rbp

  // r (accumulateur) dans rbx
  mov $1, %rbx

fac_loop:
  // Si i > x (i - x > 0)
  cmp $1, %rax
  jle fac_endloop

  // S i <= x, r = r * i
  imul %rax, %rbx
  sub $1, %rax
  jmp fac_loop

fac_endloop:
  // Copie du résultat dans rax
  mov %rbx, %rax

  // Restauration du contexte (mov %rbp, %rsp; pop %rbp; = leave)
  // pop lit la valeur et incrémente rsp de 4
  mov %rbp, %rsp
  pop %rbp
  // retour de la fonction
  ret
