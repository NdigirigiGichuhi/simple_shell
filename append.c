#include "shell.h"
#include "shelll.h"

/**
 * my_putchar - prints a char to a file
 * @ch: Character
 * @file: file to print on
 * Return: On success 1.
 */
int my_putchar(char ch, int file)
{
	return (write(file, &ch, 1));
}


/**
 * my_print - Print a string
 * @message: string
 * @file: file to print on
 * Return: bytes printed.
 */
int my_print(char *message, int file)
{
	int s;

	s = my_strlen(message);

	return (write(file, message, s));
}

/**
 * print_error - message printer
 * @message: string
 * Return: bytes printed
 */
int print_error(char *message)
{
	return (my_print(message, STDERR));
}

/**
 * free_mem - free mem
 * @pointer: pointer to memory.
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
 * free_mm - double pointer
 * @pointer: double pointer to memory
 */
void free_mm(void **pointer)
{
	void **tmp;

	for (tmp = pointer; *tmp != NULL; tmp++)
		free_mem(*tmp);

	free_mem(pointer);
}

