#include "shell.h"

/**
* freebuffers - this function frees buffers
*
* @buffer: buffer to be freed
*
* Return: void
*/
void freebuffers(char **buffer)
{
	int i = 0;

	if (!buffer || buffer == NULL)
		return;

	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
