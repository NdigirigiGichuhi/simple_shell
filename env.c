#include "shell.h"
#include "shelll.h"

/**
 * get_env - checks environment variables
 * @n: variable
 * Return: name
 */
char *get_env(const char *n)
{
	char **environment;
	char *a, *tok, *v;
	int size;

	size = my_strlen((char *) n);

	for (environment = environ; *environment; ++environment)
	{
		a = my_strdup(*environment);

		tok = strtok(a, "=");
		if (tok == NULL)
		{
			free(a);
			return (NULL);
		}

		if (my_strlen(tok) != size)
		{
			free(a);
			continue;
		}

		if (my_strcmp((char *) n, a) == 0)
		{
			tok = strtok(NULL, "=");
			v = my_strdup(tok);

			free(a);
			return (v);
		}

		free(a);
	}

	return (NULL);
}

/**
 * which_directory - locate directory
 * @name: commands
 * @infomation: information
 * Return: pointer
 */
char *which_directory(char *name, general_t *infomation)
{
	char *path, *tmp, *tok;
	char *s;
	int size;

	(void) infomation;

	path = get_env("PATH");
	if (path == NULL)
		return (NULL);

	tok = strtok(path, ":");

	size = my_strlen(name) + 2;
	s = malloc(size * sizeof(char));
	s = my_strcpy(s, "/");
	s = my_strcat(s, name);

	while (tok != NULL)
	{
		tmp = malloc(my_strlen(tok) + size);
		tmp = my_strcpy(tmp, tok);
		tmp = my_strcat(tmp, s);

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
 * is_curr_path - current path
 * @p: path check
 * @infomation: information
 */
void is_curr_path(char *p, general_t *infomation)
{
	infomation->is_current_path = _FALSE;

	if (p == NULL)
		return;

	if (p[0] == ':')
		infomation->is_current_path = _TRUE;
}

/**
 * _get_env - environment
 */
void _get_env(void)
{
	char **temp;
	int i;

	for (i = 0, temp = environ; temp[i] != NULL; i++)
	{
		print(temp[i]);
		_putchar('\n');
	}
}

/**
 * bin_env -  env builtin
 * @infomation: informatin
 * @args: arguments
 */
void bin_env(general_t *infomation, char **args)
{
	(void) infomation;
	(void) args;

	_get_env();
}
