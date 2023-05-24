#include "shell.h"

/**
 * execArgsPiped - Function where the piped system commands is executed
 * @parsed: command to be parsed
 * Return: void
 */
void execArgsPiped(char **parsed)
{
	int pipefd[2];
	pid_t p1;

	if (pipe(pipefd) < 0)
	{
		printf("\nPipe could not be initialized");
		return;
	}
	p1 = fork();
	if (p1 < 0)
	{
		printf("\nCould not fork");
		return;
	}
	if (p1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould not execute command 1..");
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		wait(NULL);
	}
}
