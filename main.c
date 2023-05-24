#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void prompt_user(void);

int main(void) {
    char command[100];

    while (1) {
        prompt_user();

        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end-of-file condition
            printf("\n");
            break;
        }

        // Remove the newline character at the end of the command
        command[strcspn(command, "\n")] = '\0';

        // Check if the command is empty
        if (strlen(command) == 0)
            continue;

        // Check if the command is longer than one word
        if (strchr(command, ' ') != NULL) {
            printf("Error: Command should be a single word\n");
            continue;
        }

        // Execute the command or print an error message
        if (system(command) == -1)
            printf("Error: Command not found\n");
    }

    return 0;
}
