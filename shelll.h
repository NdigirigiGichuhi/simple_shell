#ifndef SHELLL_H
#define SHELLL_H

#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	int mode;
	int error_code;
	char *command;
	int n_commands;
	char *value_path;
	int is_current_path;
	int status_code;
	char *buffer;
	char **arguments;
	char *environment;
	int pid;
} general_t;

typedef struct __attribute__((__packed__))
{
	char *message;
	int code;
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;
	void (*func)(general_t *info, char **arguments);
} builtin_t;

char *c_to_string(int number);
int _numeral(unsigned int n);
int _atoi(char *s);
int _alpha(char *s);
void exec_prompt(general_t *info);
void prompt(general_t *info);
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
void anal_p(general_t *info, char **arguments);
char *pat_han(general_t *info, char *string);
char *rep_val(general_t *info, int *index, char *string);
char *replace(general_t *info, int *i, char *string);
char *rep_env(general_t *info, char *environment);

#endif /* GENERAL_H */
