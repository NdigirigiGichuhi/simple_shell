#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char *prompt = "shell> ";
    char buffer[BUFFER_SIZE];

    while (1) {
        write(STDOUT_FILENO, prompt, strlen(prompt));

        ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (bytesRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        } else if (bytesRead == 0) {
            // End of file condition (Ctrl+D)
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char *args[] = {buffer, NULL};
            execve(args[0], args, NULL);
            perror("execve");
            _exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

