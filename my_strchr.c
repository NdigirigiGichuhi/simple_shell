#include "shell.h"

/**
 * my_strchr - this function locates a char in str
 *
 * @str: str to check
 *
 * @m: char to locate
 *
 * Return: returns pointer.
 */
char *my_strchr(char *str, char m)
{
	while (*str)
	{
		if (*str == m)
			return (str);
		str++;
	}
	if (!m)
		return (str);

	return (NULL);
}

