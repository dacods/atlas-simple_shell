#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_LENGTH 100

extern char **environ;

int main(void);
void shell_input(char *command, size_t size);
void execute_command_with_args(char *command);

#endif
