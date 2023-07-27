#include "general.h"
#include "commands.h"

/**
 * print_error - Print a message to STDERR
 * @message: Message to print
 * Return: Number of bytes printed
 */
int print_error(char *message)
{
		return (print_to_fd(message, STDERR));
}
