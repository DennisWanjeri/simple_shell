#include "holberton.h"
/**
 *shell_help - implements builtin help
 *@args:array of strings
 *Return:1
 */
int shell_help(char **args)
{
	int i = 0;

	_print("#cisfun$\n");
	_print("Type program names and their arguements then press enter\n");
	_print("Builtin commands:\n cd\nhelp\n\exit\n");
	_print("Explore the manpage to know about other programs\n");
	return (1);
}
/**
 *shell_environ - prints environment variables when env is invoked
 *
 *Return:1 on success
 */
int shell_environ(void)
{
	extern char **environ;
	int i, j;

	for (; *environ; *environ++)
	{
		printf("%s\n", *environ);
	}
	return (1);
}
