#include "shell.h"

/* Greeting shell during startup */
/**
 * init_shell - function that welcomes you to the shell
 * Return: void
 */
void init_shell(void)
{
	char *username;

	clear();
	printf("\n\n\n\n******************");
	printf("\n\n\n\t****MY SHELL****");
	printf("\n\n\t-USE AT YOUR OWN RISK-");
	printf("\n\n\n\n*******************");
	username = getenv("USER");

	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(1);
	clear();
}
