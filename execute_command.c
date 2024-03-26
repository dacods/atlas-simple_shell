#include "main.h"

/**
 * execute_command - 
 * @command: string
 * Return: 0
 */

void execute_command(char *command)
{
	char *args;
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args = strchr(command, ' ');
		if (args != NULL)
			execute_command_with_args(command);
		else
		{
			execlp(command, command, NULL);

			fprintf(stderr, "Error: Command '%s' not found\n", command);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}
