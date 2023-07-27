#include "shell.h"
#include "shelll.h"

/**
 * analyze - Analyse the arguments
 * @args: Commands
 * @information: info
 * @buffer: read bytes.
 */
void analyze(char **args, general_t *information, char *buffer)
{
	char *cmd;
	int pro;

	if (*args == NULL || args == NULL)
		return;

	cmd = args[0];
	information->command = cmd;
	if (c_builtins(information, args) == _TRUE)
		return;

	pro = is_filee(cmd);
	if (pro == NON_PERMISSIONS)
	{
		information->status_code = 126;
		information->error_code = _CODE_EACCES;
		error(information);
		return;
	}

	if (pro == 1)
	{
		execute(cmd, args, information, buffer);
		return;
	}

	if (current_dirctory(cmd, args, buffer, information) == _TRUE)
		return;

	information->value_path = which_directory(cmd, information);
	if (information->value_path != NULL)
	{
		execute(information->value_path, args, information, buffer);
		free_mem((void *) information->value_path);
		return;
	}

	information->status_code = 127;
	information->error_code = _CODE_CMD_NOT_EXISTS;
	error(information);
}

/**
 * exec_builtins - execute builtins
 * @info: information
 * @arguments: arguments
 * Return: command passed
 */
int exec_builtins(general_t *info, char **arguments)
{
	int s;

	s = c_builtins(info, arguments);
	if (s == _FALSE)
		return (_FALSE);

	return (_TRUE);
}

/**
 * c_builtins - check builtin
 * @info: information
 * @args: Arguments
 * Return: actual builtin
 */
int c_builtins(general_t *info, char **args)
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
			return (_TRUE);
		}
	}

	return (_FALSE);
}

