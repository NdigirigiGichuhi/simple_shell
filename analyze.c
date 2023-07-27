#include "shell.h"
#include "shelll.h"

/**
 * anal_p - analyze arguments.
 * @infomation: info about args.
 * @args: arguments.
 * Return: void.
 */

void anal_p(command_t *infomation, char **args)
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
char *pat_han(command_t *infomation, char *str)
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
char *rep_val(command_t *infomation, int *ind, char *str)
{
	int i, new, old;
	char *val;

	i = *ind;
	i++;

	val = replace(infomation, ind, str + i);
	if (val == NULL)
	{
		str = my_strcpy(str, "");
		return (str);

		old = my_strlen(str);
		new = my_strlen(val) + 1;

		str = my_realloc(str, old, new);
		str = my_strcpy(str, val);

		free_mem(val);
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
char *replace(command_t *infomation, int *i, char *str)
{
	char *temp;
	char symbol;

	(void) i;
	symbol = *str;

	if (symbol != '?' && symbol != '$')
	{
		temp = rep_env(infomation, str);
		return (temp);
	}

	temp = (symbol == '$') ? c_to_string(infomation->pid) :
		c_to_string(infomation->status_code);

	return (temp);
}

/**
 * rep_env - replaces environment.
 * @infomation: information.
 * @environ: environment.
 * Return: pointer.
 */
char *rep_env(command_t *infomation, char *environ)
{
	char *env;

	(void) infomation;

	env = get_env(environ);
	if (env != NULL)
		return (env);

	return (NULL);
}

