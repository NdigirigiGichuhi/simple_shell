#include "general.h"
#include "commands.h"

char *replacement(general_t *info, int *i, char *str)
{
	char *tmp;
	char symbol;

	(void) i;
	symbol = *str;

	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, str);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

char *replace_env(general_t *info, char *environ)
{
	char *env;
	
	(void) info;

	env = get_env(environ);
		if (env != NULL)
			return (env);

	return (NULL);
}

