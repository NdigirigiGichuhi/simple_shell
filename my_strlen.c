#include "shell.h"

/**
 * my_strlen - this function returns the length of str.
 *
 * @str: string passed
 * Return: length of a str.
 */
int my_strlen(char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		counter++;
		str++;
	}

	return (counter);
}
