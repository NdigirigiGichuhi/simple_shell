#include "commands.h"
#include "general.h"

/**
 *  * _realloc - Reallocates a memory block using malloc and free
 * @pointer: Pointer to the memory previously allocated
 * @old: Size, in bytes, of the allocated space for ptr
 * @new: New size, in bytes of the new memory block
 * Return: Memory reallocated
 **/
void *_realloc(void *pointer, size_t old, size_t new)
{
		char *s, *au;
		unsigned int a;

		if (new == old)
			return (pointer);

		if (pointer == NULL)
		{
			s = malloc(new);
			if (s == NULL)
				return (NULL);

			return (s);
		}

		if (new == 0 && pointer != NULL)
		{
			free(pointer);
			return (NULL);
		}

		s = malloc(new);
		if (s == NULL)
			return (NULL);

		au = pointer;
		for (a = 0; a < old; a++)
			s[a] = au[a];

		free(pointer);

		return (s);
}
