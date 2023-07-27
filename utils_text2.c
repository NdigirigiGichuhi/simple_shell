#include "general.h"
#include "commands.h"

/**
 * digits - Cout the numbe of digits of a number
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
 * to_string - Conver @number to string
 * @num: Number to convert
 * Return: Number as string
 */
char *to_string(int num)
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
 * is_numerical - Check if is a digit
 *
 * @num: Number
 *
 * Return: If is a number, return 1 else return 0
 */
int is_numerical(unsigned int num)
{
	return (num >= '0' && num <= '9');
}

/**
 * _atoi - Convert a string to a number
 * @str: String to convert
 * Return: Return the number
 */
int _atoi(char *str)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_numerical(str[i]))
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
 * contains_letter - Search non-digits in a string
 * @str: String for search
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE
 */
int contains_letter(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_numerical(str[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
