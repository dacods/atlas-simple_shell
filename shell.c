#include "main.h"

/**
 * main - write a UNIX command line interpreter
 *
 * Return: 0
 */

int main(void)
{
	int a = 1;
	char command[MAX_COMMAND_LENGTH]; 

        while (a == 1)
	{
		printf("#cisisfun$ ");
		shell_input(command, sizeof(command));
		execute_command_with_args(command);
	}
	return (0);
}
