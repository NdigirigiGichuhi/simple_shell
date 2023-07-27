#include "shell.h"
#include "shelll.h"

/**
 * is_exec - Check if a filename have permissions
 * for run
 * @name: Filename to check
 *
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 */
int is_exec(char *name)
{
	struct stat stats;

	if (stat(name, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_filee - Check if is a file or binary
 * @f:File to check
 * Return: If is a file with the correct permissions, PERMISSIONS
 */
int is_filee(char *f)
{
	int i, s;

	s = _strlen(f);
	for (i = 0; i < s; i++)
		if (f[i] == '/')
			return (is_exec(f));

	return (NON_FILE);
}

/**
 * _putchar - Print a character to STDOUT
 * @ch: Character to print
 * Return: On success 1
 * On error -1
 */
int _putchar(char ch)
{
	return (write(STDOUT, &ch, 1));
}

/**
 * print - Print a message to STDOUT
 * @message: Message to print
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 */
int print(char *message)
{
	return (print_to_fd(message, STDOUT));
}

