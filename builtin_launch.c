#include "holberton.h"
/**
 *shell_exit - terminates a shell
 *@args:array of strings
 *Return:0 on success
 */
int shell_exit(char **args)
{
	return (0);
}
/**
 *shell_help - implements builtin help
 *@args:array of strings
 *Return:1
 */
int shell_help(char **args)
{
	int i = 0;

	printf("cisfun$\n");
	printf("Type program names and their arguements then press enter\n");
	printf("Builtin commands:\n cd\nhelp\n\exit\n");
	printf("Explore the manpage to know about other programs\n");
	return (1);
}
int shell_cd(char **args)
{
/*when a user presses cd only -> home directory*/
	if (args[1] == NULL)
	{
		chdir("/root");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error: Can't change directory");
		}
	}
	return (1);
}
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
