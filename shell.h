#ifndef SHELL_H
#define SHELL_H

/* C Program to design a shell in Linux */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

#define MAXCOM 1000 /* max number of letters to be supported */
#define MAXLIST 100 /* max number of commands to be supported */

/* Clearing the shell using escape sequences */
#define clear() printf("\033[H\033[J")

int shell_prompt(char *str);
void printDir(void);
void execArgs(char **parsed);
void execArgsPiped(char **parsed);
void openHelp(void);
int HandleCommand(char **parsed);
int parsePipe(char *str, char **strpiped);
void parseSpace(char *str, char **parsed);
int processString(char *str, char **parsed, char **parsedpipe);


#endif /* SHELL_H */
