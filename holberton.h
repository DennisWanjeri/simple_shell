#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv);
/*handling ctrl + c signal*/
void sigint_handler(int signum);
/*print string content*/
int _putchar(char c);
void _print(char *str);

/*helper functions*/
int _strlen(const char *s);
int _execute(char **argv);
unsigned int _occurence(char *s);
char **_strtotokens(char *str);
int check_file_status(char *filename);

/*helper functions2*/
int _strcmp(char *s1, char *s2);
char *read_line(void);

/*builtin implementation*/
int shell_exit(char **args);
int shell_help(char **args);
int shell_environ(void);
/*cd_handler*/
int _cd(char **args);
int cd_home(void);
int cd_prev(void);

#endif /*HOLBERTON_H*/
