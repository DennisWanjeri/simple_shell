#include "holberton.h"

/**
 *main - Displays a prompt and waits for the user to enter a command
 *@argc: arguement count
 *@argv: arguement vector
 *Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *buffer;
	char **tokens;
	size_t bufflen = BUFSIZ;
	int response, isPipe = 0;
	/*check whether only the commands are typed*/
	/*no other arguments*/
	if (argc >= 2)
	  {
	    if (execve(argv[1], argv, NULL) == -1)
	      {
		perror("Error");
		exit(-1);
	      }
	    return (0);
	  }
	/*then print prompt '#cisfun$'*/
	do {
	  if (isatty(fileno(stdin)))
	    {
	      isPipe = 1;
	      _print("cisfun$ ");
	    }

	  getline(&buffer, &bufflen, stdin);
	  buffer[_strlen(buffer) - 1] = '\0';
	  tokens = _strtotokens(buffer);
	  response = _execute(tokens);
	} while (isPipe && response != -1);

	return (0);
}
