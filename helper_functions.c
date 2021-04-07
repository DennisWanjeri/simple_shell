#include "holberton.h"

/**
 * _strlen - find the length of a string
 * @s: pointer to the string
 * Return: characters in the string
 */
int _strlen(const char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
;
return (i);
}

/**
 * _occurence - return the number of occurence of a string
 * @s: string to check
 * Return: integer
 */
unsigned int _occurence(char *s)
{
  int i, cnt = 0;

  for (i = 0; s[i] != '\0'; i++)
    {
/*test for all delimeters*/
      if (s[i]  == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n' || s[i] == '\a')
	cnt++;
    }

  return (cnt);
}

/**
 *_strtotokens - split a sentence into multiple words.
 *@str: the string passed as argument.
 *Return: tokens
 */
char **_strtotokens(char *str)
{
  int i = 0;
  const char separator[] = " \t\n\r\a";
  int spaces = _occurence(str);
  char **tokens = malloc(sizeof(char *) * (spaces + 1));
  char *token;

  if (!tokens)
    {
      fprintf(stderr, "sh: allocation error\n");
      exit(1);
    }

  token = strtok(str, separator);

  while (token != NULL)
    {
      tokens[i] = token;
      token = strtok(NULL, separator);
      i++;
    }
  tokens[i] = NULL;

  return (tokens);
}

/**
 *check_file_status - checks whether a file exists
 *@filename:name of file
 *Return:0 - file is available, -1 otherwise
 */
int check_file_status(char *filename)
{
	struct stat st;

	if (stat(filename, &st) == -1)
		return (-1);
	return (0);
}
/**
 *_execute - executes a file given as input
 *@argv:an array of pointers to strings
 *Return:-1 (success), -1,otherwise
 */
int _execute(char **argv)
{
  pid_t cpid;
  int status;

  if (_strcmp(argv[0], "exit") == 0)
    exit(0);

  cpid = fork();
/*child process*/
  if (cpid == 0)
    {
      if (execve(argv[0], argv, NULL) == -1)
	{
	  perror("Error in execution");
	}
	  exit(-1);
    }
  else if (cpid < 0)
      perror("Error");
  else
/*parent process*/
    wait(&status);
  return (1);
}
