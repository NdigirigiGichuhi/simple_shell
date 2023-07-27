#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include "general.h"

extern char **environ;

/* commands.c */
void analyze(char **arguments, general_t *info, char *buff);

/* permissions.c */
int is_exec(char *filename);
int is_filee(char *command);


/* memory.c */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* free.c */
void free_mem(void *ptr);
void free_mm(void **ptr);

/* error.c */
char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);


/* environment.c */
char *get_env(const char *name);
char *which_directory(char *name, general_t *info);
void is_curr_path(char *path, general_t *info);
void _get_env(void);

/* execute.c */
void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff,
				general_t *info);

/* builtins.c */
int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);

/* exit.c */
void bin_exit(general_t *info, char **arguments);
int number_controller(general_t *info, char *number);

/* env.c */
void bin_env(general_t *info, char **arguments);

/* echo.c */
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);


/* Entry point of the shell */
void start(general_t *info);

#endif /* COMMANDS_H */
