#ifndef SHELLL_H
#define SHELLL_H


typedef struct __attribute__((__packed__))
{
	int ac;
	char **av;
	int mode;
	int err_code;
	char *command;
	int n_commands;
	char *value_path;
	int curr_path;
	int status_code;
	char *buff;
	char **args;
	char *enviro;
	int pid;
} command_t;


typedef struct __attribute__((__packed__))
{
	char *message;
	int code;
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;
	void (*func)(command_t *info, char **arguments);
} builtin_t;

char *c_to_string(int number);
int _numeral(unsigned int n);
int _atoi(char *s);
int _alpha(char *s);
void exec_prompt(command_t *info);
void prompt(command_t *info);
char *read_line();
void sigintHandler(int sig_num);
int my_putchar(char l, int fd);
int my_print(char *msg, int fd);
int my_strlen(char *msg);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *str);
int my_strcmp(char *str1, char *str2);
int _putchar(char c);
int print(char *msg);
char **spt_wd(char *line, const char *sep);
char *j_wd(char *word1, char *word2, char *word3, const char *sep);
int print_error(char *msg);
char **spt_wd(char *line, const char *sep);
char *j_wd(char *word1, char *word2, char *word3, const char *sep);
void anal_p(command_t *info, char **arguments);
char *pat_han(command_t *info, char *string);
char *rep_val(command_t *info, int *index, char *string);
char *replace(command_t *info, int *i, char *string);
char *rep_env(command_t *info, char *environment);

#endif /* COMMAND_H */
