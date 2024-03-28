#include "main.h"

/**
 * main - write a UNIX command line interpreter
 *
 * Return: 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH]; 

   	while (1)
	{
		printf("$ ");
		shell_input(command, sizeof(command));
		execute_command_with_args(command);
	}
	return (0);
}
