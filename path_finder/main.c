#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char **path_finder(char *path) {
  char **path_tokens = malloc(sizeof(char *));
  char *token = strtok(path, ":");
  int i = 0;

  while (token != NULL) {
    path_tokens[i] = malloc(strlen(token) + 1);
    strcpy(path_tokens[i], token);
    token = strtok(NULL, ":");
    i++;
    path_tokens = realloc(path_tokens, sizeof(char *) * (i + 1));
  }

  path_tokens[i] = NULL;

  return path_tokens;
}

int main(void) {
  // code it here

  char *path = getenv("PATH");
  char **path_tokens = path_finder(path);
  for (int i = 0; path_tokens[i] != NULL; i++) {
    printf("%s\n", path_tokens[i]);
    free(path_tokens[i]);
  }
  free(path_tokens);
  return (EXIT_SUCCESS);
}
