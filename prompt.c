#include "holberton.h"

/**
 *print_prompt - displays promot b4 user inputs
 *
 *Return:void
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_print("#cisfun$ ");
	}
}

/**
 *ignore_space - return a string without a space in front
 *@str: string
 *Return: new string without space
 */
char *ignore_space(char *str)
{
  while (*str == ' ')
    str++;
  return (str);
}
