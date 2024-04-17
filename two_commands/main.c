#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int fd[2];
  pid_t pid_input;
  pid_t pid_output;

  int sourcefile_fd;
  int destfile_fd;

  if (pipe(fd) == -1) {
    perror("Pipe 💀");
    return (EXIT_FAILURE);
  }

  pid_input = fork();
  if (pid_input == -1) {
    perror("Fork 💀");
    return (EXIT_FAILURE);
  }

  return (EXIT_SUCCESS);
}
