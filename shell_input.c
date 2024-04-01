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

	while ((num_read = read(STDIN_FILENO, &command[i], 1)) > 0)
        {
                if (command[i] == '\n')
		{
			command[i] = '\0';
			return;
		}

		if (++i == size - 1)
		{
			fprintf(stderr, "Input too long.\n");
			exit(EXIT_FAILURE);
		}
        }
        
	if (num_read == 0)
		exit(EXIT_SUCCESS);

	if (num_read < 0)
	{
		perror("Error while reading input");
		exit(EXIT_FAILURE);
	}
}
