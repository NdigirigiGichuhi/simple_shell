#include "shell.h"
/**
 * main - Entry point.
 *
 * @ac: argument count
 * @av: argument vector
 * @envp: environment vector
 *
 * Return: always 0
 */

void handle_exit(int status) {
    exit(status);
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
		if (builtin_check(command, ln)) {
			if (my_strcmp(command[0], "exit") == 0) {
				if (command[1] != NULL) {
					int status = atoi(command[1]);
					handle_exit(status);
				} else {
					handle_exit(0);
				}
			}
			continue;
		}
	}
		handles.interactive = NULL;
		if (linelen < 0 && handles.interactive)
			write(STDERR_FILENO, "\n", 1);
		free(ln);
		return (0);
	}
