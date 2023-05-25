#include "shell.h"

/**
 * prompt - this function prompts the user to enter commands.
 *
 * Return: void
 */
void prompt(void)
{
        struct flags handle;

        if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
                handle.interactive = 1;
        if (handle.interactive)
                write(STDERR_FILENO, "Boniel_Ben-Shell-$ ", 19);
}
