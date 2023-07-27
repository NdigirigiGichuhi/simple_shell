#include "shell.h"
#include "shelll.h"

/**
 * my_strcmp - Compare two strings
 * @str1: String 1
 * @str2: String 2
 * Return: Integer
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
 * Return: Length of the string
 */
int my_strlen(char *message)
{
	int i;

	for (i = 0; message[i] != '\0'; i++)
		;

	return (i);
}


/**
 * my_strcpy - Copy a string to another
 * @destination: Destination copy
 * @source: Source for copy
 * Return: Return the value of dest
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
 * my_strdup - Pointer to a newly allocated space in memory
 * @s: String to copy
 * Return: String copied
 */
char *my_strdup(char *s)
{
	int size, i;
	char *dest;

	if (s == NULL)
		return (NULL);

	size =my_strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(s + i);
	return (dest);
}

/**
 * my_strcat - Concatenates two strings
 * @destination: String concatenate
 * @source: Source string
 * Return: A string concatenate
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

