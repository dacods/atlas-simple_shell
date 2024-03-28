#include "main.h"

/**
 * shell_input - string that prints an error if not executable
 * @command: string
 * @size: size
 */

void shell_input(char *command, size_t size)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		} else {
			printf("Error while reading input.\n");
			exit(EXIT_FAILURE);
                }
        }
	strncpy(command, line, size - 1);
	command[size - 1] = '\0';

	free(line);
}
