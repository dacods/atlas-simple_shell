#include "main.h"

/**
 * main - write a UNIX command line interpreter
 *
 * Return: 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int all_whitespace = 1;
	size_t i;

   	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$: ", 4);
		}

		shell_input(command, sizeof(command));

		for (i = 0; i < strlen(command); i++)
		{
			if (command[i] != ' ' && command[i] != '\t' && command[i] != '\n')
			{
				all_whitespace = 0;
				break;
			}
		}

		if (all_whitespace)
			continue;

		execute_command_with_args(command);
	}
	return (0);
}
