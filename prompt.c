#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int interactive;
} Flags;

Flags flags = { 0 }; // Initialize flags

void prompt_user(void) {
    if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
        flags.interactive = 1;
    if (flags.interactive)
        write(STDERR_FILENO, "$ ", 2);
}
