#include "shell.h"

/**
* parseSpace - function for parsing command words
* @str: string to be parsed
* @parsed: command to parse
* Return: void
*/
void parseSpace(char *str, char **parsed)
{
	int i;

	for (i = 0; i < MAXLIST; i++)
	{
		parsed[i] = strsep(&str, " ");

		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}
