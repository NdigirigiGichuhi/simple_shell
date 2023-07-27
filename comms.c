#include "shell.h"
#include "shelll.h"

/**
 * analyze - Analyse the arguments
 * @args: Commands
 * @information: info
 * @buffer: read bytes.
 */
void analyze(char **args, command_t *information, char *buffer)
{
	char *cmd;
	int pro;

	if (*args == NULL || args == NULL)
		return;

	cmd = args[0];
	information->command = cmd;
	if (c_builtins(information, args) == 1)
		return;

	pro = is_filee(cmd);
	if (pro == -1)
	{
		information->status_code = 126;
		information->err_code = CODE_13;
		error(information);
		return;
	}

	if (pro == 1)
	{
		execute(cmd, args, information, buffer);
		return;
	}

	if (current_dirctory(cmd, args, buffer, information) == 1)
		return;

	information->value_path = which_directory(cmd, information);
	if (information->value_path != NULL)
	{
		execute(information->value_path, args, information, buffer);
		free_mem((void *) information->value_path);
		return;
	}

	information->status_code = 127;
	information->err_code = CODE_132;
	error(information);
}

/**
 * exec_builtins - execute builtins
 * @info: information
 * @arguments: arguments
 * Return: command passed
 */
int exec_builtins(command_t *info, char **arguments)
{
	int s;

	s = c_builtins(info, arguments);
	if (s == 0)
		return (0);

	return (1);
}

/**
 * c_builtins - check builtin
 * @info: information
 * @args: Arguments
 * Return: actual builtin
 */
int c_builtins(command_t *info, char **args)
{
	int i, size;
	builtin_t builtins[] = {
		{"exit", b_ex},
		{"env", bin_env}
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < size; i++)
	{
		if (my_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[i].func(info, args);
			return (1);
		}
	}

	return (0);
}

