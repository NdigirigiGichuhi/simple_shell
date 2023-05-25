#include "shell.h"

/**
 * my_strncmp - this function compares str1 and str2 up to n bytes
 *
 * @str1: str1 comparisson to str2.
 *
 * @str2: str2 comparisson to str1.
 * @n: number of bytes
 *
 * Return: difference between str1 and str2
 */
int my_strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}

	return (0);
}

