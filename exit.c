#include "shell.h"
#include "shelll.h"

/**
 * b_ex - Implementation of the exit builtin
 * @infomation: Information about the shell
 * @arguments: Arguments received
 */
void b_ex(general_t *infomation, char **arguments)
{
	int code, ch;

	ch = _TRUE;
	if (arguments[1] != NULL)
		ch = numroller(infomation, arguments[1]);

	if (ch == _FALSE)
		return;

	code = infomation->status_code;

	free_mm((void **) arguments);
	free_mem((void *) infomation->buffer);
	free_mem((void *) infomation->environment);
	free_mem((void *) infomation);

	exit(code);
}

/**
 * number_controller - Control the argument of exit
 * @info: General information about the shell
 * @num: Argument of the builtin
 * Return: If the actual argument is valid, return _TRUE
 * if not, return _FALSE
 */
int numroller(general_t *info, char *num)
{
	int _num;

	_num = _atoi(num);

	if (_num < 0 || _alpha(num))
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
