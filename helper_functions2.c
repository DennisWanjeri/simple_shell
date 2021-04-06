#include "holberton.h"

/**
 *_strcmp - compares strings
 *@s1: string character
 *@s2: string character
 *Return: a pointer to string
 */
int _strcmp(char *s1, char *s2)
{
  int i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
char *read_line(void)
{
	int buffsize = 1024;
	int index = 0;
	int cha;
	char *buffer;

	buffer = malloc(sizeof(char) * buffsize);
	if(!buffer)
	{
		dprintf(STDERR_FILENO, "memory allocation error\n");
		exit(98);
	}
/*apparently infinite loop*/
	while (1)
	{
/*read a character*/
		cha = getchar();
/*handling End of File or EOF  where we replace it with nullbyte char*/
		if (cha == EOF || cha == '\n')
		{
			buffer[index] = '\0';
			return (buffer);
		}
/*else we write the character read to buffer*/
		else
		{
			buffer[index] = cha;
		}
		index++;
/*reallocation of memory incase of excess cha*/
		if (index >= buffsize)
		{
			buffsize += 1024;
			buffer = realloc(buffer,buffsize);
			if (!buffer)
			{dprintf(STDERR_FILENO, "error in memory allocation\n"), exit(98);}
		}
	}
}
