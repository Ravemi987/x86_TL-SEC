#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);

  // Declare A NULL table for envp and argv
  char *null[] = {NULL};

  // Execute /bin/bash shell
  execve("/bin/bash", &null[0], &null[0]);

  fprintf(stderr, "Failed to execute the binary\n");

  return 1;
}
