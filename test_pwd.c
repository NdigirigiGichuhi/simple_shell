#include "shell.h"

/**
* test_pwd - tests the path
*
* @parse: tokenized parse
* @command: input
*
* Return: path, otherwise NULL.
*/
char *test_pwd(char **parse, char *command)
{
	int i = 0;
	char *result;

	while (parse[i])
	{
		result = parse_comm(parse[i], command);
		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	return (NULL);
}
