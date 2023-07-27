#include "shell.h"
#include "shelll.h"

/**
 * my_putchar - Print a character to a specific file
 * descriptor
 * @ch: Character to print
 * @file: Place to print the character
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_putchar(char ch, int file)
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
int my_print(char *message, int file)
{
	int s;

	s = my_strlen(message);

	return (write(file, message, s));
}

/**
 * print_error - Print a message to STDERR
 * @message: Message to print
 * Return: Number of bytes printed
 */
int print_error(char *message)
{
	return (my_print(message, STDERR));
}

/**
 * free_mem - Free a pointer
 *
 * @pointer: Pointer to free
 */
void free_mem(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}

	pointer = NULL;
}

/**
 * free_mm - Free a double pointer
 *
 * @pointer: Double pointer to free
 */
void free_mm(void **pointer)
{
	void **tmp;

	for (tmp = pointer; *tmp != NULL; tmp++)
		free_mem(*tmp);

	free_mem(pointer);
}

