#include "holberton.h"
/**
 *free_args - frees a two dimensional string
 *@args:array of pointers to strings
 *Return:void
 */
void free_args(char **args)
{
	int i = 0;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);
}
/**
 *read_line - reads user's input from stdin
 *
 *Return:pointer to string containing user input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			if (isatty(0) == 1)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (line);
}
