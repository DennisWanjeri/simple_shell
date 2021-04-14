#include "holberton.h"
/**
 *shell_help - implements builtin help
 *@args:array of strings
 *Return:1
 */
/*
int shell_help(char **args)
{
	void(args);

	printf("#cisfun$\n");
	printf("Type program names and their arguements then press enter\n");
	printf("Builtin commands:/n cd/nhelp/n/exit/n");
	printf("Explore the manpage to know about other programs\n");
	return (1);
	}*/
/**
 *shell_environ - prints environment variables when env is invoked
 *
 *Return:1 on success
 */
int shell_environ(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
