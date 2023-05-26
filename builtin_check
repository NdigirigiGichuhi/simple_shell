#include "shell.h"

/**
 * builtin_check - this function checks built in functions
 *
 * @command: user input
 * @buffer: standard input.
 *
 * Return: 1 if command is excuted oherwise 0.
 */

int builtin_check(char **command, char *buffer)
{
	if (fun_handler(command, buffer))
	{
		return (1);
	}
	else if (**command == '/')
	{
		execute_comm(command[0], command);
		return (1);
	}
	return (0);
}
