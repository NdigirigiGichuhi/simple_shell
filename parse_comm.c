#include "shell.h"

/**
 * parse_comm - this function parse to command
 *
 * @parse: parse command path
 *
 * @comm: inputted command
 *
 * Return: buffer containing comm with parse on success
 * NULL on failure
 */
char *parse_comm(char *parse, char *comm)
{
	char *buffer;
	unsigned int i = 0;
	unsigned int j = 0;

	if (comm == 0)
		comm = "";

	if (parse == 0)
		parse = "";

	buffer = malloc(sizeof(char) * (my_strlen(parse) + my_strlen(comm) + 2));
	if (buffer == NULL)
		return (NULL);

	while (parse[i])
	{
		buffer[i] = parse[i];
		i++;
	}

	if (parse[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}
	while (comm[j])
	{
		buffer[i + j] = comm[j];
		j++;
	}
	buffer[i + j] = '\0';

	return (buffer);
}
