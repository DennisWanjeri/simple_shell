#include "holberton.h"
/**
 *shell_exit - exits a shell,taking into account different exit statuses
 *@args:arguements passed
 *@line:string to free
 *Return:void
 */
void shell_exit(char **args, char *line)
{
	int status = 0;

	if (args[i] != NULL)
	{
		status = atoi(args[1]);
		if (status >= 0)
		{
			free(line);
			free(args);
			exit(status);
		}
		printf("Exit: illegal status: %s\n", args[1]);
	}
	else
	{
		free(line);
		free(args);
		exit(0);
	}
}
