#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char **argv, char **envp) {

  // code here
  // while (*environ) {
  //   printf("%s\n", *environ);
  //   environ++;
  // }
  char *string;
  while (*envp) {
    if (strncmp(*envp, "PATH=", 5) == 0) {
      string = *envp + 5;
      break;
    }
    envp++;
  }
  // lets separate the PATH variable into its components and print them
  char *commad = "ping";
  // now lets find the path of the command
  char *right_path;
  char *path;
  char *token = strtok(string, ":");
  while (token) {
    path = malloc(strlen(token) + strlen(commad) + 2);
    strcpy(path, token);
    strcat(path, "/");
    strcat(path, commad);
    if (access(path, X_OK) == 0) {
      right_path = path;
      break;
    }
    free(path);
    token = strtok(NULL, ":");
  }
  if (right_path) {
    printf("The path of the command is: %s\n", right_path);
  } else {
    printf("Command not found\n");
  }
  char *args[] = {"ping", "-c", "3", "google.com", NULL};
  pid_t pid = fork();
  if (pid == 0) {
    execve(right_path, args, environ);
    perror("execve");
    return (EXIT_FAILURE);
  }
  wait(NULL);
  free(right_path);
  return (EXIT_SUCCESS);
}
