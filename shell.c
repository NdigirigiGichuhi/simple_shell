#include "shell.h"
#include "shelll.h"

/**
 * main - Entry point
 * @ac: arguments supplied
 * @av: arguments vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	command_t *infomation;
	int code;

	infomation = malloc(sizeof(command_t));
	if (infomation == NULL)
	{
		perror(av[0]);
		exit(1);
	}

	infomation->pid = getpid();
	infomation->status_code = 0;
	infomation->n_commands = 0;
	infomation->ac = ac;
	infomation->av = av;
	infomation->mode = isatty(STDIN_FILENO) == 1;
	start(infomation);

	code = infomation->status_code;

	free(infomation);

	return (code);
}
