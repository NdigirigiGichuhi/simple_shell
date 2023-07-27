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

	if (current_directory(cmd, args, buffer, information) == _TRUE)
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
