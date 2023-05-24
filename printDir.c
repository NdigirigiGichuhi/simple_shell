#include "shell.h"

/**
 * printDir - Function to print Current Directory.
 * Return: void
 */
void printDir(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}
