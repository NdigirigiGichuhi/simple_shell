#include "shell.h"
/**
* shell_prompt - function that accepts input
* @str:  It is a pointer to a character array or string
* Return: 0 when a str is parsed and 0 if not
*/
int shell_prompt(char *str)
{
	char buf[100];
	ssize_t bytesRead;

	write(STDOUT_FILENO, "Boniel_Ben-$ ", 13);
	bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);

	if (bytesRead > 0)
	{
		buf[bytesRead - 1] = '\0';
		strcpy(str, buf);
		return (0);
	}
	else
	{
		return (1);
	}
}
