#include "shell.h"
#include "shelll.h"

/**
 * message_selector - selects message
 * @info: information
 * Return: error
 */
char *message_selector(command_t info)
{
	int i, options;
	error_t message[] = {
		{"No such file or directory", CODE_3},
		{"Permission denied", CODE_13},
		{"not found", CODE_132},
		{"Illegal number", CODE_133}
	};

	options = sizeof(message) / sizeof(message[0]);
	for (i = 0; i < options; i++)
		if (info.err_code == message[i].code)
			return (message[i].message);

	return ("");
}

/**
 * error - prints error to standard output
 * @infomation: information
 */
void error(command_t *infomation)
{
	char *msg;
	char *num;
	char *aux;
	int size_number, size_message;

	num = NULL;
	msg = message_selector(*infomation);
	num = c_to_string(infomation->n_commands);

	size_number = my_strlen(num);
	size_message = my_strlen(infomation->av[0]);

	aux = malloc(size_message + size_number + 3);

	aux = my_strcpy(aux, infomation->av[0]);
	aux = my_strcat(aux, ": ");
	aux = my_strcat(aux, num);

	msg = j_wd(aux, infomation->command, msg, ": ");
	print_error(msg);

	free(msg);
	free(num);
	free(aux);
}

/**
 * error_extra - prints error to stdout
 * @infomation: information
 * @extra: extra info
 */
void error_extra(command_t *infomation, char *extra)
{
	char *msg, *num, *ax, *ax2;
	int size_num, size_msg, size_extra;


	num = NULL;
	msg = message_selector(*infomation);
	num = c_to_string(infomation->n_commands);

	size_num = my_strlen(num);
	size_msg = my_strlen(infomation->av[0]);
	size_extra = my_strlen(extra);


	ax = malloc(size_msg + size_num + 3);
	ax = my_strcpy(ax, infomation->av[0]);
	ax = my_strcat(ax, ": ");
	ax = my_strcat(ax, num);

	ax2 = malloc(my_strlen(msg) + size_extra + 3);
	ax2 = my_strcpy(ax2, msg);
	ax2 = my_strcat(ax2, ": ");
	ax2 = my_strcat(ax2, extra);

	msg = j_wd(ax, infomation->command, ax2, ": ");
	print_error(msg);

	free(msg);
	free(num);
	free(ax);
	free(ax2);
}
