#include "general.h"
#include "commands.h"

/**
 * main - Entry point
 * @ac: arguments supplied
 * @av: arguments vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	general_t *infomation;
	int code;

	infomation = malloc(sizeof(general_t));
	if (infomation == NULL)
	{
		perror(av[0]);
		exit(1);
	}

	infomation->pid = getpid();
	infomation->status_code = 0;
	infomation->n_commands = 0;
	infomation->argc = ac;
	infomation->argv = av;
	infomation->mode = isatty(STDIN) == INTERACTIVE;
	start(infomation);

	code = infomation->status_code;

	free(infomation);

	return (code);
}
