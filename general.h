#ifndef GENERAL_H
#define GENERAL_H

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

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133
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


/* text.c */
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);

/* utils_text.c */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

/* utils_text2.c */
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/* printers_out.c */
int _putchar(char c);
int print(char *msg);

/* printers_err.c */
int print_error(char *msg);

/* tokenization.c */
char **spt_wd(char *line, const char *sep);
char *j_wd(char *word1, char *word2, char *word3, const char *sep);

/* patterns.c */
void anal_p(general_t *info, char **arguments);
char *pat_han(general_t *info, char *string);
char *rep_val(general_t *info, int *index, char *string);

/* patterns_replacer.c */
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);

#endif /* GENERAL_H */
