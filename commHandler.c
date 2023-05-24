#include "shell.h"

/**
* HandleCommand - Function to execute builtin commands
* @parsed: command to parse
*
* Return: 0 always
*/
int HandleCommand(char** parsed)
{
	int Commands = 4, i, switchOwnArg = 0;
	char* MyCmd[4];
	char* user;

	MyCmd[0] = "exit";
	MyCmd[1] = "cd";
	MyCmd[2] = "help";
	MyCmd[3] = "hello";

	for (i = 0; i < Commands; i++)
	{
		if (strcmp(parsed[0], MyCmd[i]) == 0)
		{
			switchOwnArg = i + 1;
			break;
		}
	}
	switch (switchOwnArg)
	{
		case 1:
			printf("\nGoodbye\n");
			exit(0);
		case 2:
			chdir(parsed[1]);
			return (1);
		case 3:
			return (1);
		case 4:
			user = getenv("USER");
			printf("\nHello %s.\n helps you to know more...\n", user);
			return (1);
		default:
			break;
	}
	return (0);
}
