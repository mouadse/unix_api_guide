#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_null.h>
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
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp("ping", "ping", "-c", "3", "google.com", NULL);
  }
  pid_t pid2 = fork();
  if (pid2 < 0) {
    perror("2nd Fork 💀");
    return (EXIT_FAILURE);
  } else if (pid2 == 0) {
    // Child proc 2 for grep command
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp("grep", "grep", "packets", NULL);
  }
  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);
  return (EXIT_SUCCESS);
}
