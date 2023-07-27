#include "shell.h"
#include "shelll.h"

/**
 * my_strcmp - Compare two strings
 * @str1: String 1
 * @str2: String 2
 * Return: 0
 */
int my_strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}

	return (0);
}


/**
 * my_strlen - Return the length of a strin
 * @message: String to calculate length
 * Return: string length
 */
int my_strlen(char *message)
{
	int i;

	for (i = 0; message[i] != '\0'; i++)
		;

	return (i);
}


/**
 * my_strcpy - copy string to another string
 * @destination: Destination
 * @source: Source
 * Return: value of dest
 */
char *my_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	destination[i] = '\0';

	return (destination);
}


/**
 * my_strdup - Pointer
 * @s: String
 * Return: pointer
 */
char *my_strdup(char *s)
{
	int size, i;
	char *dest;

	if (s == NULL)
		return (NULL);

	size = my_strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(s + i);
	return (dest);
}

/**
 * my_strcat - Concatenates two strings
 * @destination: string 1.
 * @source: string 2.
 * Return: pointer.
 */
char *my_strcat(char *destination, char *source)
{
	int l_dest, i;

	l_dest = my_strlen(destination);

	for (i = 0; source[i] != '\0'; i++, l_dest++)
		destination[l_dest] = source[i];

	destination[l_dest] = '\0';

	return (destination);
}

