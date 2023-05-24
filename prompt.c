#include "shell.h"

int takeInput(char* str)
{
    char buf[100];
    ssize_t bytesRead;

    write(STDOUT_FILENO, "\n>>> ", 5);
    bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);
    if (bytesRead > 0) {
        buf[bytesRead - 1] = '\0';  // Remove the newline character
        strcpy(str, buf);
        return 0;
    } else {
        return 1;
    }
}

