#include "shell.h"

/**
 * exit_Shell - this function exits CLI.
 *
 * @command: command
 * @line: input in standard input
 *
 * Return: void
 */
void exit_Shell(char **command, char *line)
{
	free(line);
	freebuffers(command);
	_exit(0);
}

/**
 * builtin_check - checks if the command is a built-in command.
 *
 * @command: command
 * @line: input in standard input
 *
 * Return: 1 if it is a built-in command, 0 otherwise.
 */
int builtin_check(char **command, char *line)
{
	int status;
	if (my_strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
		{
			status = atoi(command[1]);
			exit(status);
		}
		else
		{
			exit_Shell(command, line);
		}
		return (1);
	}
	return (0);
}

int main(int ac, char **av, char *envp[])
{
	struct flags handles;
	struct information info;
	char *ln = NULL, *parsecomm = NULL, *parse = NULL;
	size_t bufsize = 0;
	ssize_t linelen = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, signal_handler);
	while (1)
	{
		freebuffers(command);
		freebuffers(paths);
		free(parsecomm);
		prompt();
		linelen = getline(&ln, &bufsize, stdin);
		if (linelen < 0)
			break;
		info.ln_count++;
		if (ln[linelen - 1] == '\n')
			ln[linelen - 1] = '\0';
		command = token_handler(ln);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (builtin_check(command, ln))
			continue;
		parse = pwd_path();
		paths = token_handler(parse);
		parsecomm = test_pwd(paths, command[0]);
		if (!parsecomm)
			perror(av[0]);
		else
			execute_comm(parsecomm, command);
	}
	handles.interactive = NULL;
	if (linelen < 0 && handles.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(ln);
	return (0);
}

