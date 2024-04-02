#include "main.h"

/**
 * execute_command_with_args - execute a command with arguments 
 * @command: string
 * Return: 0
 */

void execute_command_with_args(char *command)
{
	char **env;
	char *args[MAX_COMMAND_LENGTH], *token;
	int i = 0, status;
	pid_t pid;
	/*Tokenize command into arguments*/
	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL; 
	/*Handle 'exit' command*/
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			fprintf(stderr, "exit: too many arguments\n");
			return;
		}
		exit(EXIT_SUCCESS);
	}
	/*Handle 'env' command*/
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
	/*Fork a new process*/
	pid = fork();
	/*Handle fork error*/
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	/*Child process*/
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	/*Parent process*/
	else
		waitpid(pid, &status, 0);
}
