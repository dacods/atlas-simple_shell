#include "main.h"

/**
 * main - write a UNIX command line interpreter
 *
 * Return: 0
 */

int main(void)
{
        char command[MAX_COMMAND_LENGTH];

	printf("$: ");

	while (1)
	{
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		execute_command_with_args(command);
	}

	return (0);
}
