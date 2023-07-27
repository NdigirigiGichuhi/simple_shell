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

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133

extern char **environ;
void error_extra(general_t *info, char *extra);
void analyze(char **arguments, general_t *info, char *buff);
int is_exec(char *filename);
int is_filee(char *command);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);
void free_mem(void *ptr);
void free_mm(void **ptr);
char *message_selector(general_t info);
void error(general_t *info);
char *get_env(const char *name);
char *which_directory(char *name, general_t *info);
void is_curr_path(char *path, general_t *info);
void _get_env(void);
int exec_builtins(general_t *info, char **arguments);
int c_builtins(general_t *info, char **arguments);
void b_ex(general_t *info, char **arguments);
int numroller(general_t *info, char *number);
void execute(char *commands, char **arguments, general_t *info, char *buff);
void bin_env(general_t *info, char **arguments);
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);
void start(general_t *info);
int current_dirctory(char *command, char **args, char *buffer,
		general_t *info);

#endif /* COMMANDS_H */
