#include <stdio.h>
#include <unistd.h>

void execve_asm(char *path, char **null) {
  __asm__ volatile(
    "syscall"
    :
    : "a" (59),
      "D" (path),
      "S" (null),
      "d" (null)
  );
}

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);
  char *null[] = {NULL};
  char path[] = "/bin/bash";

  // Execute /bin/bash shell
  //execve("/bin/bash", &null[0], &null[0]);
  execve_asm(path, null);

  fprintf(stderr, "Failed to execute the binary\n");

  return 1;
}
