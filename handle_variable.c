#include "shell.h"

/**
 * handle_variable_replacement - replaces special variables
 * in a given input string.
 *
 * @input: input from the user.
 *
 * Return: A newly allocated string with the replaced variables,
 */

char *handle_variable_replacement(char *input)
{
	size_t length;
	char *result;
	unsigned int i, j;
	int pid;
	char pid_str[10];
	int return_code;
	char return_code_str[10];

	 if (input == NULL)
                return (NULL);

	length = my_strlen(input);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0, j = 0; i < length; i++, j++)
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '$')
			{
				pid = getpid();

				sprintf(pid_str, "%d", pid);
				my_strcpy(&result[j], pid_str);
				j += my_strlen(pid_str) - 1;
				i++;
			} else if (input[i + 1] == '?')
			{
				return_code = 0;

				sprintf(return_code_str, "%d", return_code);
				my_strcpy(&result[j], return_code_str);
				j += my_strlen(return_code_str) - 1;
				i++;
			} else
				result[j] = input[i];
		} else
			result[j] = input[i];
	}
	result[j] = '\0';
	return (result);
}

