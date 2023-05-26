#include "shell.h"

/**
* exit_Shell - this function exits CLI.
*
* @command: command
* @line: input in standard input
*
* Return: void
*/
void exit_Shell(char **command, char *line)
{
	free(line);
	freebuffers(command);
	exit(0);
}
