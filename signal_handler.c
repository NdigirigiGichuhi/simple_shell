#include "shell.h"

/**
 * signal_handler - this function  tracks interactive mode
 *
 * @c: the signal number
 *
 * Return: void
 */

void signal_handler(int c)
{
	(void)c;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "Boniel_Ben-Shell-$ ", 19);
}
