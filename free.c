#include "general.h"
#include "commands.h"

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
