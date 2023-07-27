#include "shell.h"
#include "shelll.h"

/**
 * digits - digits
 * @num: Number
 * Return: Digits
 */
int digits(int num)
{
	int i;

	for (i = 0; num != 0; i++, num /= 10)
		;

	return (i);
}

/**
 * c_to_string - number to string
 * @num: number
 * Return: Number as string
 */
char *c_to_string(int num)
{
	int n_digits, i;
	char *_num;

	n_digits = digits(num);
	_num = malloc(n_digits * sizeof(char) + 2);
	if (num == 0)
	{
		_num[0] = '0';
		_num[1] = '\0';
		return (_num);
	}
	/* Check NULL */

	_num[n_digits] = '\0';
	for (i = n_digits - 1; num != 0; num /= 10, i--)
		_num[i] = (num % 10) + '0';

	return (_num);
}


/**
 * _numeral - digit checker
 * @num: number to check
 * Return: return 1 if it's a number, otherwise 0
 */
int _numeral(unsigned int num)
{
	return (num >= '0' && num <= '9');
}

/**
 * _atoi - Convert a string to a number
 * @str: string passed
 * Return: converted number
 */
int _atoi(char *str)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (_numeral(str[i]))
		{
			number = (str[i] - 48)	+ number * 10;

			if (str[i + 1] == ' ')
				break;
		}
		else if (str[i] == '-')
		{
			sign *= -1;
		}
	}

	return (number * sign);
}

/**
 * _alpha - search for alphabets in a string
 * @str: string
 * Return: If a non-digits was found, return 1 otherwise 0
 */
int _alpha(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (_numeral(str[i]) == 0)
			return (1);
	}

	return (0);
}
