#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);


void print_Shellenv(void);
void execute_comm(char *comm_p, char **command);
char *pwd_path(void);
void freebuffers(char **buffer);
char *test_pwd(char **parse, char *command);
char *parse_comm(char *parse, char *comm);
int fun_handler(char **command, char *line);
int builtin_check(char **command, char *buffer);
void exit_Shell(char **command, char *line);
void prompt(void);
void signal_handler(int c);
char **token_handler(char *line);



struct builtin
{
	char *env;
	char *exit;
};

struct information
{
	int final_exit;
	int ln_count;
};

struct flags
{
	bool interactive;
};

char *my_strchr(char *str, char m);
int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char *str);
int my_strncmp(char *str1, char *str2, int n);


#endif /* SHELL_H */




