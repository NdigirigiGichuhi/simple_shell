#include "shell.h"

/**
 * prompt - this function prompts the user to enter commands.
 *
 * Return: void
 */
void prompt(void)
{
        struct flags handle;

        handle.interactive = NULL;

        if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
                handle.interactive = 1;
        if (handle.interactive)
                write(STDERR_FILENO, "Boniel_Ben-Shell-$ ", 19);
}


/**
 * execute_comm - this function executes inputs.
 *
 * @comm_p: command input
 * @command: vector array of pointers to commands
 *
 * Return: void
 */
void execute_comm(char *comm_p, char **command)
{
    if (my_strcmp(command[0], "setenv") == 0)
    {
        setenv_Shell(command);
    }
    else if (my_strcmp(command[0], "unsetenv") == 0)
    {
        unsetenv_Shell(command);
    }
    else
    {
        pid_t pid;
        int status;
        char **env = environ;

        pid = fork();
        if (pid < 0)
        {
            perror(comm_p);
        }
        else if (pid == 0)
        {
            execve(comm_p, command, env);
            perror(comm_p);
            free(comm_p);
            freebuffers(command);
            exit(98);
        }
        else
        {
            wait(&status);
        }
    }
}

