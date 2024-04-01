#include "main.h"

/**
 * get_path -
 * @command:
 * Return:
 */

char *get_path(char *command)
{
	char command_path[MAX_LENGTH];
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	if (path == NULL)
	{
		fprintf(stderr, "PATH enviroment variable not set.\n");
		exit(EXIT_FAILURE);
	}

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(command));
		}
		else
		{
			free(path_copy);
			return (NULL);
		}
	}

	while (dir != NULL)
	{
		strcpy(command_path, dir);
		strcat(command_path, "/");
		strcat(command_path, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(command_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
