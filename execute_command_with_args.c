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
	pid_t pid = fork();
	char *command_path = get_path(command);

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		token = strtok(command, " ");

		 while (token != NULL && i < MAX_COMMAND_LENGTH - 1)
                {
                        args[i++] = token;
                        token = strtok(NULL, " ");
                }
                args[i] = NULL;

		command_path = get_path(args[0]);
		if (command_path == NULL)
			exit(EXIT_FAILURE);

		if (execve(command_path, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
	free(command_path);
}
