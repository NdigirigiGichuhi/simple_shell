#include "shell.h"

/**
 * my_strcmp - this function compares str1 and str2
 *
 * @str1: str1 comparisson to str2;
 * @str2: str2 comparisson to str1;
 *
 * Return: returns difference between strings
 */
int my_strcmp(char *str1, char *str2)
{
	int a = 0, result;

	while (*(str1 + a) == *(str2 + a) && *(str1 + a) != '\0')
		a++;

	result = (*(str1 + a) - *(str2 + a));
	return (result);
}

