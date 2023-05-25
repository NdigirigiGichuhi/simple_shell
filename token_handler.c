#include "shell.h"
#include "shell.h"

/**
* token_handler - this function creates tokens
*
* @line: input to be tokenized
*
* Return: tokens
*/
char **token_handler(char *line)
{
	char *buffer = NULL, *bufp = NULL, *token = NULL, *delimiter = " :;\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;
	char *comment;

	buffer = my_strdup(line);
	if (!buffer)
		return (NULL);
	comment = my_strchr(buffer, '#');
	if (comment)
		*comment = '\0';
	bufp = buffer;
	while (*bufp)
	{
		if (my_strchr(delimiter, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (my_strchr(delimiter, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = my_strtok(buffer, delimiter);
	while (token)
	{
		tokens[index] = my_strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = my_strtok(NULL, delimiter);
		index++;
	}
	tokens[index] = NULL;
	free(buffer);
	return (tokens);
}

