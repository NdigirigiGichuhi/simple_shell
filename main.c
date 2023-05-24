#include "shell.h"
/**
 * main - Entry Point
 * Return: 0 always
 */
int main(void)
{
	char inputString[MAXCOM], *parsedArgs[MAXLIST];
	char *parsedArgsPiped[MAXLIST];
	int execFlag = 0;

	init_shell(void);

	while (1)
	{
		printDir(void);

		if (takeInput(inputString))
			continue;
		execFlag = processString(inputString, parsedArgs, parsedArgsPiped);

		if (execFlag == 1)
			execArgs(parsedArgs);

		if (execFlag == 2)
			execArgsPiped(parsedArgs, parsedArgsPiped);
	}
	return (0);
}
