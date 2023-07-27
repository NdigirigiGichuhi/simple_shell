#include "shell.h"
#include "shelll.h"

/**
 * execute - Execute a command in other process
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
 * current_dirctory - Execute the command if the order require
 * @command: Command to execute
 * @args: Arguments of the @cmd
 * @buffer: Line readed
 * @info: General info about the shell
 * Return: Status of the operations
 */
int current_dirctory(char *command, char **args, char *buffer, general_t *info)
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

/**
 *  * _realloc - Reallocates a memory block using malloc and free
 * @pointer: Pointer to the memory previously allocated
 * @old: Size, in bytes, of the allocated space for ptr
 * @new: New size, in bytes of the new memory block
 * Return: Memory reallocated
 **/
void *_realloc(void *pointer, size_t old, size_t new)
{
	char *s, *au;
	unsigned int a;

	if (new == old)
		return (pointer);

	if (pointer == NULL)
	{
		s = malloc(new);
		if (s == NULL)
			return (NULL);

		return (s);
	}

	if (new == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	s = malloc(new);
	if (s == NULL)
		return (NULL);

	au = pointer;
	for (a = 0; a < old; a++)
		s[a] = au[a];

	free(pointer);

	return (s);
}

