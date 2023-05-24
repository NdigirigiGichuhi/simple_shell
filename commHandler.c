#include "shell.h"

/**
* ownCmdHandler - Function to execute builtin commands
* @parsed: command to parse
*
* Return: 0 always
*/
int ownCmdHandler(char **parsed)
{
	int NoOfOwnCmds = 4, i, switchOwnArg = 0;
	char *ListOfOwnCmds[100];
	char *username;

	ListOfOwnCmds[0] = "exit";
	ListOfOwnCmds[1] = "cd";
	ListOfOwnCmds[2] = "help";
	ListOfOwnCmds[3] = "hello";

	for (i = 0; i < NoOfOwnCmds; i++)
	{
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0)
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
			openHelp();
			return (1);
		case 4:
			username = getenv("USER");
			printf("\nHello %s.\n Use help to know more..\n", username);
			return (1);
		default:
			break;
	}
	return (0);
}
