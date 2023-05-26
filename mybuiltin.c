#include "shell.h"
/**
 * builtin_checker - checks if the command is a built-in command.
 *
 * @command: command
 * @line: input in standard input
 *
 * Return: 1 if it is a built-in command, 0 otherwise.
 */
int builtin_check(char **command, char *line)
{
	int status;

	if (my_strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
		{
			status = atoi(command[1]);
			free(line);
			freebuffers(command);
			exit(status);
		}
		else
		{
			exit_Shell(command, line);
		}
		return (1);
	}
	return (0);
}
