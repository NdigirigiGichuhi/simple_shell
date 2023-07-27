#include "commands.h"
#include "general.h"

/**
 * get_env - gets environment variable
 * @n: variable to get
 * Return: name
 */
char *get_env(const char *n)
{
	char **environment;
	char *a, *tok, *v;
	int size;

	size = _strlen((char *) n);

	for (environment = environ; *environment; ++environment)
	{
		a = _strdup(*environment);

		tok = strtok(a, "=");
		if (tok == NULL)
		{
			free(a);
			return (NULL);
		}

		if (_strlen(tok) != size)
		{
			free(a);
			continue;
		}

		if (_strcmp((char *) n, a) == 0)
		{
			tok = strtok(NULL, "=");
			v = _strdup(tok);

			free(a);
			return (v);
		}

		free(a);
	}

	return (NULL);
}

/**
 * which_directory - Find the directory needed
 *
 * @name: Command received
 * @info: General info about the shell
 *
 * Return: pointer string with found path or NULL in failure
 */
char *which_directory(char *name, general_t *info)
{
	char *path, *tmp, *tok;
	char *s;
	int size;

	(void) info;

	path = get_env("PATH");
	if (path == NULL)
		return (NULL);

	tok = strtok(path, ":");

	size = _strlen(name) + 2;
	s = malloc(size * sizeof(char));
	s = _strcpy(s, "/");
	s = _strcat(s, name);

	while (tok != NULL)
	{
		tmp = malloc(_strlen(tok) + size);
		tmp = _strcpy(tmp, tok);
		tmp = _strcat(tmp, s);

		if (is_exec(tmp) == PERMISSIONS)
		{
			free(s);
			free(path);
			return (tmp);
		}
		tok = strtok(NULL, ":");

		free(tmp);
	}

	free(path);
	free(s);

	return (NULL);
}

/**
 * is_curr_path -Check the order of the path
 * @p: PATH to check
 * @info: General infor about the shell
 */
void is_curr_path(char *p, general_t *info)
{
	info->is_current_path = _FALSE;

	if (p == NULL)
		return;

	if (p[0] == ':')
		info->is_current_path = _TRUE;
}

/**
 * _get_env - Get all the environment
 */
void _get_env(void)
{
	char **tmp;
	int i;

	for (i = 0, tmp = environ; tmp[i] != NULL; i++)
	{
		print(tmp[i]);
		_putchar('\n');
	}
}

/**
 * bin_env - Implementation for the env builtin
 *
 * @info: General information about the shell
 * @args: Command
 */
void bin_env(general_t *info, char **args)
{
	(void) info;
	(void) args;

	_get_env();
}
