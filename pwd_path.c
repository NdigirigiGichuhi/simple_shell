#include "shell.h"

/**
* pwd_path - this function finds the path from the env
*
* Return: NULL.
*/
char *pwd_path(void)
{
	int i;
	char **env = environ, *parse = NULL;

	while (*env)
	{
		if (my_strncmp(*env, "PATH=", 5) == 0)
		{
			parse = *env;
			while (*parse && i < 5)
			{
				parse++;
				i++;
			}
			return (parse);
		}
		env++;
	}
	return (NULL);
}
