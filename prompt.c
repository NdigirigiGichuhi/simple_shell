#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    char command[BUFFER_SIZE];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process

            // Execute the command
            if (execlp(command, command, NULL) == -1) {
                // Handle error when executable is not found
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process

            // Wait for the child process to complete
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

