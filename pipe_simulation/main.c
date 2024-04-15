#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // code goes here
  int fd[2];
  if (pipe(fd) == -1) {
    perror("Pipe 💀");
    return (EXIT_FAILURE);
  }
  pid_t pid1;
  pid1 = fork();
  if (pid1 < 0) {
    perror("Fork 💀");
    return (EXIT_FAILURE);
  } else if (pid1 == 0) {
    // child process 1 for ping command
  }

  return (EXIT_SUCCESS);
}
