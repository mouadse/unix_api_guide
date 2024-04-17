#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int pid;
	int status;
	char *args[] = {"/bin/ls", "-l", NULL};

	pid = fork();
	if (pid == 0) {
		execv(args[0], args);
		perror("execv");
		exit(1);
	} else {
		wait(&status);
		printf("Child process terminated with status %d\n", status);
	}

	return (EXIT_SUCCESS);
}
