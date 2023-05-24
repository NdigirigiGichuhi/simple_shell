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

	while (1)
	{
		printDir();

		if (shell_prompt(inputString))
			continue;
		execFlag = processString(inputString, parsedArgs, parsedArgsPiped);

		if (execFlag == 1)
			execArgs(parsedArgs);

		if (execFlag == 2)
			execArgsPiped(parsedArgs);
	}
	return (0);
}
