#include "general.h"
#include "commands.h"

/**
 * builtins - Check and execute the builtins
 * @info: Information about the shell
 * @args: Commands and arguments
 * Return: If the command passed is a builtins
 * return _TRUE if not return _FALSE
 */
int builtins(general_t *info, char **arguments)
{
	int s;

	s = check_builtin(info, arguments);
	if (s == _FALSE)
		return (_FALSE);

	return (_TRUE);
}

/**
 * check_builtin - Check if the actual command is a builtin_t
 * or not
 *
 * @info: General information about the shell
 * @args: Arguments of the command
 * Return: If the command is an actual builtin, return _TRUE
 * if not _FALSE
 */
int check_builtin(general_t *info, char **args)
{
	int i, size;
	builtin_t builtins[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[i].func(info, args);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
