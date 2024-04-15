#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // code here
  pid_t pid;

  pid = getpid();

  printf("The proc id is %d\n", pid);

  return (EXIT_SUCCESS);
}
