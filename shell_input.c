#include "main.h"

/**
 * shell_input - string that prints an error if not executable
 * @command: string
 * @size: size
 */

void shell_input(char *command, size_t size)
{
	ssize_t num_read;
	size_t i = 0;
	int non_whitespace_found = 0;

	while ((num_read = read(STDIN_FILENO, &command[i], 1)) > 0)
        {
		if (!non_whitespace_found && isspace(command[i]))
			continue;

                if (command[i] == '\n')
		{
			command[i] = '\0';
			return;
		}

		non_whitespace_found = 1;

		if (++i == size - 1)
		{
			fprintf(stderr, "Input too long.\n");
			exit(EXIT_FAILURE);
		}
        }
        
	if (num_read == 0)
		exit(EXIT_SUCCESS);

	perror("Error while reading input");
	exit(EXIT_FAILURE);
}
