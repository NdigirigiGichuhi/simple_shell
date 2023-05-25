#include "shell.h"

/**
* print_Shellenv - this function prints the env str to stdout.
*
* Return: void
*/
void print_Shellenv(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], my_strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
