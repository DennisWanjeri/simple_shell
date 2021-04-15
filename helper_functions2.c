#include "holberton.h"

/**
 *read_line - reads characters in stdin
 *
 *Return: nothing
 */
char *read_line(void)
{
	int buffsize = 1024, index = 0, cha;
	char *buffer;

	buffer = malloc(sizeof(char) * buffsize);
	if (!buffer)
	{dprintf(STDERR_FILENO, "memory allocation error\n"), exit(98); }
	cha = getchar();
	if (cha == '\n')
	{
		*buffer = '\n';
		return (buffer);
	}
	if (cha == EOF)
	{
		exit(EXIT_SUCCESS);
	}
	else
		buffer[index] = cha;
/*apparently infinite loop*/
	index = 1;
	while (1)
	{
/*read a character*/
		cha = getchar();
/*handling End of File or EOF  where we replace it with nullbyte char*/
		if (cha == '\n' || cha == EOF)
		{
			if (cha == '\n')
			{
				buffer[index] = cha;
				index++;
			}
			buffer[index] = '\0';
			return (buffer);
		}
/*else we write the character read to buffer*/
		else
			buffer[index] = cha;
		index++;
/*reallocation of memory incase of excess cha*/
		if (index >= buffsize)
		{
			buffsize += 1024;
			buffer = realloc(buffer, buffsize);
			if (!buffer)
			{dprintf(STDERR_FILENO, "error in memory allocation\n"), exit(98); }
		}
	}
}
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
