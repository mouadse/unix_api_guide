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
  }
  if (pid1 == 0) {
    sleep(3);
    printf("The %d {pid1} finished execution\n", pid1);
  }
  pid2 = fork();
  if (-1 == pid2) {
  }
  if (pid2 == 0) {
    sleep(1);
    printf("The %d {pid2} finished execution\n", pid2);
  }
  wait(NULL);
  wait(NULL);
  return (EXIT_SUCCESS);
}
