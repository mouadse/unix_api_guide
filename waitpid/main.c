#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // code goes here
  pid_t pid1;
  pid_t pid2;

  pid1 = fork();
  if (-1 == pid1) {
    perror("PID1");
    return (EXIT_FAILURE);
  }
  if (pid1 == 0) {
    sleep(3);
    printf("The %d {pid1} finished execution\n", getpid());
    return (EXIT_SUCCESS);
  }
  pid2 = fork();
  if (-1 == pid2) {
    perror("PID2");
    return (EXIT_FAILURE);
  }
  if (pid2 == 0) {
    sleep(1);
    printf("The %d {pid2} finished execution\n", getpid());
    return (EXIT_SUCCESS);
  }
  int ret1 = wait(NULL);
  printf("Waited for %d\n", ret1);
  int ret2 = wait(NULL);
  printf("Waited for %d\n", ret2);
  return (EXIT_SUCCESS);
}
