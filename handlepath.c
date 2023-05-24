#include "test.h"

/**
 * handlePath - function that handles path
 *
 * @command: command to pass on the shell prompt
 *
 * Return: 0 when success
 */

int handlePath(char *command)
{
	char *path;
	char *token;
	char commandPath[MAX_COMMAND_LENGTH];

	if (access(command, X_OK) == 0)
	{
		parseCommand(command);
		return (1);
	}

	path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH variable not found\n");
		return (0);
	}

	token = strtok(path, ":");

	while (token != NULL)
	{
		sprintf(commandPath, "%s/%s", token, command);
		if (access(commandPath, X_OK) == 0)
		{
			parseCommand(commandPath);
			return (1);
		}
		token = strtok(NULL, ":");
	}

	return (0);
}

