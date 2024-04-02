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
	/*Read input from stdin until newline or end of file*/
	while ((num_read = read(STDIN_FILENO, &command[i], 1)) > 0)
        {
		/*Skip leading whitespace characters*/
		if (!non_whitespace_found && (command[i] == ' ' || command[i] == '\t' || command[i] == '\n'))
			continue;
		/*if newline is encounterd, terminate command string and return*/
                if (command[i] == '\n')
		{
			command[i] = '\0';
			return;
		}
		/*Indicate non-whitespace character found*/
		non_whitespace_found = 1;
		/*Check if input exceeds the specified size*/
		if (++i == size - 1)
		{
			fprintf(stderr, "Input too long.\n");
			exit(EXIT_FAILURE);
		}
        }
	/*Handle end of file*/
	if (num_read == 0)
		exit(EXIT_SUCCESS);

	perror("Error while reading input");
	exit(EXIT_FAILURE);
}
