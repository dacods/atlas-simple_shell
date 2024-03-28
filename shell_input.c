#include "main.h"

/**
 * shell_input - string that prints an error if not executable
 * @command: string
 * @size: size
 */

void shell_input(char *command, size_t size)
{
	int c;
	size_t i = 0;

	while ((c = getchar()) != EOF && c != '\n')
        {
                if (i < size - 1)
		       command[i++] = c;	
		else
		{
                        printf("Error while reading input.\n");
                        exit(EXIT_FAILURE);
                }
        }
        
	if (c == EOF)
		exit(EXIT_SUCCESS);

	command[i] = '\0';
}
