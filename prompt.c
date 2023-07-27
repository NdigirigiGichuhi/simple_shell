#include "shell.h"
#include "shelll.h"

/**
 * prompt - Print the prompt
 * @infomation: Struct of general information
 */
void prompt(command_t *infomation)
{
	if (infomation->mode == 0)
		return;

	print("Ben$ ");
}

/**
 * start - Handle the mode
 * @infomation: Struct of information about the shell
 */
void start(command_t *infomation)
{
	exec_prompt(infomation);
}


/**
 * read_line - Read lines in the prompt
 * Return: read bytes
 */
char *read_line()
{
	char *buffer;
	int r;
	size_t s;

	buffer = NULL;

	r = getline(&buffer, &s, stdin);

	if (r == EOF)
	{
		free_mem((void *) buffer);
		return (NULL);
	}

	return (buffer);
}

/**
 * exec_prompt - execute read prompt
 * @infomation: Struct of general informatio
 * Return: read bytes
 */
void exec_prompt(command_t *infomation)
{
	char *buffer;
	char **arguments;
	char *path;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(infomation);

		path = get_env("PATH");
		is_curr_path(path, infomation);

		infomation->enviro = path;
		buffer = read_line();
		if (buffer == NULL)
		{
			print(infomation->mode == 1 ? "exit\n" : "");
			free(path);
			break;
		}

		infomation->n_commands++;
		if (buffer[0] != '\n')
		{
			arguments = spt_wd(buffer, " \t\n");

			infomation->args = arguments;
			infomation->buff = buffer;
			anal_p(infomation, arguments);
			analyze(arguments, infomation, buffer);

			free_mm((void *) arguments);
		}

		free_mem((void *) buffer);
		free_mem((void *) path);
	}
}

/**
 * sigintHandler - handler
 * @sig_n: void
 * Return: void.
 */
void sigintHandler(int sig_n)
{
	(void) sig_n;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
