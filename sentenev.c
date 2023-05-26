#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * setenv_Shell - initialize a new environment variable or modify an existing one.
 *
 * @command: command
 *
 * Return: void
 */
void setenv_Shell(char **command)
{
	if (command[1] == NULL || command[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	if (setenv(command[1], command[2], 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}
}

/**
 * unsetenv_Shell - remove an environment variable.
 *
 * @command: command
 *
 * Return: void
 */
void unsetenv_Shell(char **command)
{
	if (command[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	if (unsetenv(command[1]) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}
}
