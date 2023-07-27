#include "general.h"
#include "commands.h"

/**
 * bin_exit - Implementation of the exit builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 *
 * @info: Information about the shell
 * @args: Arguments received
 */
void bin_exit(general_t *info, char **args)
{
	int code, status;

	status = _TRUE;
	if (args[1] != NULL)
		status = number_controller(info, args[1]);

	if (status == _FALSE)
		return;

	code = info->status_code;

	free_mm((void **) args);
	free_mem((void *) info->buffer);
	free_mem((void *) info->environment);
	free_mem((void *) info);

	exit(code);
}

/**
 * number_controller - Control the argument of exit
 *
 * @info: General information about the shell
 * @number: Argument of the builtin
 *
 * Return: If the actual argument is valid, return _TRUE
 * if not, return _FALSE
 */
int number_controller(general_t *info, char *num)
{
	int _num;

	_num = _atoi(num);

	if (_num < 0 || contains_letter(num))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, num);
		return (_FALSE);
	}

	if (_num > 255)
		info->status_code = _num % 256;
	else
		info->status_code = _num;
	return (_TRUE);
}
