#include "commands.h"
#include "general.h"

void anal_p(general_t *infomation, char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		args[i] = pat_han(infomation, args[i]);
}

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

char *rep_val(general_t *infomation, int *ind, char *str)
{
	int i, new, old;
	char *value;

	i = *ind;
	i++;

	value = replacement(infomation, ind, str + i);
	if (value == NULL)
	{
		str = _strcpy(str, "");
		return (str);

		old = _strlen(str);
		new = _strlen(value) + 1;

		str = _realloc(str, old, new);
		str = _strcpy(str, value);

		free_mem(value);
		*ind = i;
	}
	return (str);
}
