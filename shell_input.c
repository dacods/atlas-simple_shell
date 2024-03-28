#include "main.h"

/**
 * shell_input - string that prints an error if not executable
 * @command: string
 * @size: size
 */

void shell_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
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
        command[strcspn(command, "\n")] = '\0';
}
