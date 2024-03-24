#include "main.h"

/**
 * main - write a UNIX command line interpreter
 *
 * Return: 0
 */

int main()
{
        char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nExiting shell...\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}

	return (0);
}
