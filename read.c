#include "holberton.h"
/**
 *read_line - reads user input from.stdin
 *Return:pointer to string
 */
char *read_line2(void)
{
	char *input = NULL;
	size_t len = 0;

	if (getline(&input, &len, stdin) == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	return (input);
}
