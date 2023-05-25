#include "shell.h"

/**
* fun_handler - this function executes builtin functions
*
* @command: executed commands
* @line: input
*
* Return: 1 if executed, otherwise 0.
*/
int fun_handler(char **command, char *line)
{
	 struct builtin builtin = {"env", "exit"};

	if (my_strcmp(*command, builtin.env) == 0)
	{
		print_Shellenv();
		return (1);
	}
	else if (my_strcmp(*command, builtin.exit) == 0)
	{
		exit_Shell(command, line);
		return (1);
	}
	return (0);
}
