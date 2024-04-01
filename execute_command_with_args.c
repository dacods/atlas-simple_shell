#include "main.h"

/**
 * execute_command_with_args - 
 * @command: string
 * Return: 0
 */

void execute_command_with_args(char *command)
{
	char **env;
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	int i = 0;
	int status;
	pid_t pid;
	char *path;
	char exec_path[MAX_COMMAND_LENGTH];

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			fprintf(stderr, "exit: too many arguments\n");
			return;
		}
		exit(EXIT_SUCCESS);
	}

	if (strcmp(args[0], "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return;
	}

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		sprintf(exec_path, "%s/%s", token, args[0]);

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(exec_path, args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				return;
		}

		token = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", args[0]);
	exit(EXIT_FAILURE);
}
