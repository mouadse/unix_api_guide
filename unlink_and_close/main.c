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
  char *file_name = "names.txtt";
  int fd = open(file_name, O_RDWR, 0777);
  if (-1 == fd) {
    perror("Open!!!");
    return (EXIT_FAILURE);
  }

  int ret = unlink(file_name);

  if (!ret)
    printf("File deleted !!!\n");
  return (EXIT_SUCCESS);
}
