#include "main.h"

/**
 * execute_command_with_args - 
 * @command: string
 * Return: 0
 */

void execute_command_with_args(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	int i = 0;
	int status;
	pid_t pid;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}
