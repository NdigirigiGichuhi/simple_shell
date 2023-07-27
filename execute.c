#include "commands.h"
#include "general.h"

/**
 * execute - Execute a command in other process
 *
 * @cmd: Command to execute
 * @args: Arguments of the @command
 * @info: General info about the shell
 * @buffer: Line readed
 */
void execute(char *cmd, char **args, general_t *info, char *buffer)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, environ);
		perror("./sh");

		free_mm((void *) args);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}


/**
 * current_directory - Execute the command if the order require
 * 
 * @command: Command to execute
 * @args: Arguments of the @cmd
 * @buffer: Line readed
 * @info: General info about the shell
 *
 * Return: Status of the operations
 */
int current_directory(char *command, char **args, char *buffer, general_t *info)
{
	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_exec(command) == PERMISSIONS)
	{
		execute(command, args, info, buffer);
		return (_TRUE);
	}

	return (_FALSE);
}
