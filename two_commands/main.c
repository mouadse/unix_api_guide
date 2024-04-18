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

  int sourcefile_fd = open("source.txt", O_RDONLY);
  if (sourcefile_fd == -1) {
    perror("Open 💀");
    return (EXIT_FAILURE);
  }

  int destfile_fd = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (destfile_fd == -1) {
    perror("Open 💀");
    return (EXIT_FAILURE);
  }

  if (pipe(fd) == -1) {
    perror("Pipe 💀");
    return (EXIT_FAILURE);
  }

  pid_input = fork();
  if (pid_input == -1) {
    perror("Fork 💀");
    return (EXIT_FAILURE);
  }

  if (pid_input == 0) {
    close(fd[0]);
    dup2(sourcefile_fd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    execlp("cat", "cat", NULL);
    perror("Exec 💀");
    return (EXIT_FAILURE);
  }

  pid_output = fork();
  if (pid_output == -1) {
    perror("Fork 💀");
    return (EXIT_FAILURE);
  }

  if (pid_output == 0) {
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(destfile_fd, STDOUT_FILENO);
    execlp("grep", "grep", "John", NULL);
    perror("Exec 💀");
    return (EXIT_FAILURE);
  }

  close(fd[0]);
  close(fd[1]);
  int ret1 = waitpid(pid_input, NULL, 0);
  int ret2 = waitpid(pid_output, NULL, 0);
  printf("ret1: %d\n", ret1);
  printf("ret2: %d\n", ret2);
  close(sourcefile_fd);
  close(destfile_fd);

  return (EXIT_SUCCESS);
}
