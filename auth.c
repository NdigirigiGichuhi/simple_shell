#include "shell.h"
#include "shelll.h"

/**
 * is_exec - checking file permissions.
 * @name: file
 * Return: On success, PERMISSIONS.
 */
int is_exec(char *name)
{
	struct stat ben;

	if (stat(name, &ben) == 0)
	{
		if (ben.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_filee - evaluate file or binary
 * @f:File to evaluate
 * Return: permissions
 */
int is_filee(char *f)
{
	int i, s;

	s = my_strlen(f);
	for (i = 0; i < s; i++)
		if (f[i] == '/')
			return (is_exec(f));

	return (NON_FILE);
}

/**
 * _putchar - character printer
 * @ch: char
 * Return: On success 1, otherwise -1
 */
int _putchar(char ch)
{
	return (write(STDOUT, &ch, 1));
}

/**
 * print - print a string
 * @message: string
 * Return: bytes printed
 */
int print(char *message)
{
	return (my_print(message, STDOUT));
}

