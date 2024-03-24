#include "main.h"

/**
 * execute_command - 
 * @command: string
 * Return: 0
 */

void execute_command(char *command)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(command, command, NULL);
		fprintf(stderr, "Error: Command '%s' not found\n", command);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}
