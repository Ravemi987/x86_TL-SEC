#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);
  char *null[] = {NULL};
  char path[] = "/bin/bash";

  //execve("/bin/bash", &null[0], &null[0]);
  __asm__ volatile(
    "syscall"
    :
    : "a" (59),
      "D" (path),
      "S" (null),
      "d" (null)
  );

  fprintf(stderr, "Failed to execute the binary\n");

  return 1;
}
