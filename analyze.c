#include "shell.h"
#include "shelll.h"

/**
 * anal_p - analyze arguments.
 * @infomation: info about args.
 * @args: arguments.
 * Return: void.
 */

void anal_p(general_t *infomation, char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		args[i] = pat_han(infomation, args[i]);
}

/**
 * pat_han - handles patterns.
 * @infomation: info about args.
 * @str: arguments.
 * Return: pointer.
 */
char *pat_han(general_t *infomation, char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '$' && str[i + 1] != '\0')
			str = rep_val(infomation, &i, str);
	}

	return (str);
}

/**
 * rep_val - replaces value.
 * @infomation: info about args.
 * @ind: index.
 * @str: string:
 * Return: pointer
 */
char *rep_val(general_t *infomation, int *ind, char *str)
{
	int i, new, old;
	char *value;

	i = *ind;
	i++;

	value = replace(infomation, ind, str + i);
	if (value == NULL)
	{
		str = my_strcpy(str, "");
		return (str);

		old = my_strlen(str);
		new = my_strlen(value) + 1;

		str = my_realloc(str, old, new);
		str = my_strcpy(str, value);

		free_mem(value);
		*ind = i;
	}
	return (str);
}

/**
 * replace - replace values.
 * @infomation: information.
 * @i: index.
 * @str: passed string.
 * Return: pointer.
 */
char *replace(general_t *infomation, int *i, char *str)
{
	char *tmp;
	char symbol;

	(void) i;
	symbol = *str;

	if (symbol != '?' && symbol != '$')
	{
		tmp = rep_env(infomation, str);
		return (tmp);
	}

	tmp = (symbol == '$') ? c_to_string(infomation->pid) :
		c_to_string(infomation->status_code);

	return (tmp);
}

/**
 * rep_env - replaces environment.
 * @infomation: information.
 * @environ: environment.
 * Return: pointer.
 */
char *rep_env(general_t *infomation, char *environ)
{
	char *env;

	(void) infomation;

	env = get_env(environ);
	if (env != NULL)
		return (env);

	return (NULL);
}

