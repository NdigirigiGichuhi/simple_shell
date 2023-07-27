#include "shell.h"
#include "shelll.h"

/**
 * b_ex - implements exit builtin
 * @infomation: information
 * @arguments: Arguments received
 */
void b_ex(command_t *infomation, char **arguments)
{
	int code, ch;

	ch = 1;
	if (arguments[1] != NULL)
		ch = numroller(infomation, arguments[1]);

	if (ch == 0)
		return;

	code = infomation->status_code;

	free_mm((void **) arguments);
	free_mem((void *) infomation->buff);
	free_mem((void *) infomation->enviro);
	free_mem((void *) infomation);

	exit(code);
}

/**
 * numroller - Control the arguments
 * @infomation: information
 * @num: builtin args
 * Return: If actual argument is valid, return 1, otherwise 0
 */
int numroller(command_t *infomation, char *num)
{
	int _num;

	_num = _atoi(num);

	if (_num < 0 || _alpha(num))
	{
		infomation->status_code = 2;
		infomation->err_code = CODE_133;
		error_extra(infomation, num);
		return (0);
	}

	if (_num > 255)
		infomation->status_code = _num % 256;
	else
		infomation->status_code = _num;
	return (1);
}
