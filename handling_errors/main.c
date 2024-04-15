#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_ssize_t.h>
#include <unistd.h>

int main(void) {
  // code here
  // lets try to close the standard output twice
  ssize_t status = close(STDIN_FILENO);

  printf("the value of status is %lu\n", status);

  status = close(STDIN_FILENO);
  if (status == -1) {
    perror("close");
  }

  // another way is using strerror
  char *err = strerror(errno);
  printf("The msg error is  --> %s\n", err);

  return (EXIT_SUCCESS);
}
