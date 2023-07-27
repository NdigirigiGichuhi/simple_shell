#include "shell.h"
#include "shelll.h"

/**
 * b_ex - implements exit builtin
 * @infomation: information
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
 * numroller - Control the arguments
 * @infomation: information
 * @num: builtin args
 * Return: If actual argument is valid, return _TRUE, otherwise _FALSE
 */
int numroller(general_t *infomation, char *num)
{
	int _num;

	_num = _atoi(num);

	if (_num < 0 || _alpha(num))
	{
		infomation->status_code = 2;
		infomation->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(infomation, num);
		return (_FALSE);
	}

	if (_num > 255)
		infomation->status_code = _num % 256;
	else
		infomation->status_code = _num;
	return (_TRUE);
}
