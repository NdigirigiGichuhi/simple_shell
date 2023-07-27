#include "general.h"
#include "commands.h"

/**
 * _strlen - Return the length of a strin
 * @message: String to calculate length
 * Return: Length of the string
 */
int _strlen(char *message)
{
	int i;

	for (i = 0; message[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenates two strings
 * @destination: String concatenate
 * @surce: Source string
 * Return: A string concatenate
 */
char *_strcat(char *destination, char *source)
{
	int l_dest, i;

	l_dest = _strlen(destination);

	for (i = 0; source[i] != '\0'; i++, l_dest++)
		destination[l_dest] = source[i];

	destination[l_dest] = '\0';

	return (destination);
}

/**
 * _strcpy - Copy a string to another
 * @destination: Destination copy
 * @source: Source for copy
 * Return: Return the value of dest
 */
char *_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	destination[i] = '\0';

	return (destination);
}


/**
 * _strdup - Pointer to a newly allocated space in memory
 * @s: String to copy
 * Return: String copied
 */
char *_strdup(char *s)
{
	int size, i;
	char *dest;

	if (s == NULL)
		return (NULL);

	size = _strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(s + i);

	return (dest);
}

/**
 * _strcmp - Compare two strings
 * @str1: String 1
 * @str2: String 2
 * Return: Integer
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}

	return (0);
}
