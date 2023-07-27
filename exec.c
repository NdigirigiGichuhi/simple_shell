#include "shell.h"
#include "shelll.h"

/**
 * execute - executes commands
 * @command: command
 * @args: Arguments
 * @infomation: information
 * @buffer: read bytes
 */
void execute(char *command, char **args, general_t *infomation, char *buffer)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, args, environ);
		perror("./sh");

		free_mm((void *) args);

		if (infomation->value_path != NULL)
		{
			free(infomation->value_path);
			infomation->value_path = NULL;
		}

		free(infomation);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			infomation->status_code = WEXITSTATUS(status);
	}
}


/**
 * current_dirctory - execute command
 * @command: command
 * @args: arguments
 * @buffer: read bytes
 * @infomation: information
 * Return: status
 */
int current_dirctory(char *command, char **args, char *buffer,
		general_t *infomation)
{
	if (infomation->is_current_path == _FALSE)
		return (_FALSE);

	if (is_exec(command) == PERMISSIONS)
	{
		execute(command, args, infomation, buffer);
		return (_TRUE);
	}

	return (_FALSE);
}

/**
 * *my_realloc - reallocates memory
 * @pointer: pointer
 * @old: old bytes
 * @new: new bytes
 * Return: memory pointer
 **/
void *my_realloc(void *pointer, size_t old, size_t new)
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

