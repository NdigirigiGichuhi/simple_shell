#include "shell.h"
/**
* parsePipe - function for finding pipe
* @str: string to be parsed
* @strpiped: str to be parsed
* Return: 1 if success, 0 if pipe not found
*/
int parsePipe(char *str, char **strpiped)
{
	int i;

	for (i = 0; i < 2; i++)
	{
		strpiped[i] = strsep(&str, "|");

		if (strpiped[i] == NULL)
			break;
	}
	if (strpiped[1] == NULL)
		return (0);
}
