#include "shell.h"

/**
 * my_strdup - this funtion dupicates str.
 *
 * @str: to be duplicated
 * Return: returns pointer to duplicate str
 */
char *my_strdup(char *str)
{
	int i, length;
	char *pointer;

	if (str == NULL)
		return (NULL);

	length = my_strlen(str);

	pointer = malloc((length + 1) * sizeof(char));

	if (!pointer)
		return (NULL);

	for (i = 0; *str != '\0'; str++, i++)
		pointer[i] = str[0];

	pointer[i++] = '\0';

	return (pointer);
}

