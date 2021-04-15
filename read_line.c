#include "holberton.h"
/**
 *read_line - reads user's input from stdin
 *
 *Return:pointer to string containing user input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == 0)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (line);
}
