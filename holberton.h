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

#define PATH_MAX 1024
extern char **environ;
int main(void);
/*handling ctrl + c signal*/
void ctrl_c(int signum);
/*ctrl_D*/
/*print prompt*/
void print_prompt(void);
/*print string content*/
int _putchar(char c);
void _print(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*helper functions*/
int _strlen(const char *s);
int _execute(char **tokens, char *line);
unsigned int _occurence(char *s);
char **_strtotokens(char *str);
int check_file_status(char *filename);
/*handling the path*/
char *cmd_build(char *token, char *dir_value);
int get_path(char **args);
char *get_env(char *path);
/*builtin parser*/
int builtin_parser(char **tokens);
/*helper functions2*/
int _strcmp(char *s1, char *s2);
char *read_line(void);
void free_args(char **args);
/*builtin implementation*/
void shell_exit(char **args, char *line);
int shell_help(char **args);
int shell_environ(void);
/*cd_handler*/
int _cd(char **args);
int cd_home(void);
int cd_prev(void);
char *_getcwd(void);
/*env_set and env_unset*/
int _setenv(char *var_name, char *var_value);
char *var_build(char *var_name, char *var_value);
int _unsetenv(char *var_name);
#endif /*HOLBERTON_H*/
