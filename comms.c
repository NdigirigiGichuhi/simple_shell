#include "commands.h"
#include "general.h"

/**
 * analyze - Analyse the arguments
 * @args: Commands
 * @information: info
 * @buffer: read bytes.
 */
void analyze(char **args, general_t *information, char *buffer)
{
	char *cmd;
	int status;

	if (*args == NULL || args == NULL)
		return;

	cmd = args[0];
	information->command = cmd;
	if (check_builtin(information, args) == _TRUE)
		return;

	status = is_filee(cmd);
	if (status == NON_PERMISSIONS)
	{
		information->status_code = 126;
		information->error_code = _CODE_EACCES;
		error(information);
		return;
	}

	if (status == 1)
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
 * builtins - Check and execute the builtins
 * @info: Information about the shell
 * @arguments: Commands and arguments
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

