#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv);

/*print string content*/
int _putchar(char c);
void _print(char *str);

/*helper functions*/
int _strlen(const char *s);
int _execute(char **argv);
unsigned int _occurence(char *s);
char **_strtotokens(char *str);

int check_file_status(char *filename);

#endif /*HOLBERTON_H*/
