#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - write a UNIX command line interpreter
 *
 * Return: 0
 */

int main()
{
        int x = 1;
        char buffer[1024];

        while (x == 1)
        {
                printf("#cisfun$ ");
                scanf("%s", buffer);
                if (access(buffer,F_OK) == 0)
                {
                        system (buffer);
                }
                else {
                        printf("./shell: No such file or directory\n");
                }

        }
        return (0);
}
