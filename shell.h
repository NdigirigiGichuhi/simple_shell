#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include "shelll.h"

#define CODE_3			3
#define CODE_13		          13
#define CODE_132   132
#define CODE_133   133

extern char **environ;
void error_extra(command_t *info, char *extra);
void analyze(char **arguments, command_t *info, char *buff);
int is_exec(char *filename);
int is_filee(char *command);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);
void free_mem(void *ptr);
void free_mm(void **ptr);
char *message_selector(command_t info);
void error(command_t *info);
char *get_env(const char *name);
char *which_directory(char *name, command_t *info);
void is_curr_path(char *path, command_t *info);
void _get_env(void);
int exec_builtins(command_t *info, char **arguments);
int c_builtins(command_t *info, char **arguments);
void b_ex(command_t *info, char **arguments);
int numroller(command_t *info, char *number);
void execute(char *commands, char **arguments, command_t *info, char *buff);
void bin_env(command_t *info, char **arguments);
void bin_echo(command_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);
void start(command_t *info);
int current_dirctory(char *command, char **args, char *buffer,
		command_t *info);

#endif /* COMMANDS_H */
