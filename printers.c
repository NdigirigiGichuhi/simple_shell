#include "general.h"
#include "commands.h"

/**
 * _putchar_to_fd - Print a character to a specific file
 * descriptor
 * @ch: Character to print
 * @file: Place to print the character
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_to_fd(char ch, int file)
{
	return (write(file, &ch, 1));
}


/**
 * print_to_fd - Print a string
 * @message: Strin to print in the fd specified
 * @file: File descriptor to print
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_to_fd(char *message, int file)
{
	int s;

	s = _strlen(message);

	return (write(file, message, s));
}
