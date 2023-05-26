#include "shell.h"
/**
 * my_strcpy - copies one string to another.
 *
 * @destination: where the string is copied.
 * @source: string to be copied.
 *
 * Return: copied string.
 */

char *my_strcpy(char *destination, char *source)
{
    char *ptr = destination;

    while (*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    }

    *ptr = '\0';

    return destination;
}
