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
	/*Infinite loop*/
   	while (1)
	{
		/*Prompt the user*/
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$: ", 4);
		}
		/*Get user input command*/
		shell_input(command, sizeof(command));
		/*Check for whitespace*/
		for (i = 0; i < strlen(command); i++)
		{
			if (command[i] != ' ' && command[i] != '\t' && command[i] != '\n')
			{
				all_whitespace = 0;
				break;
			}
		}
		/*If only whitespace continue*/
		if (all_whitespace)
			continue;
		/*Execute user input with arguments*/
		execute_command_with_args(command);
	}
	return (0);
}
