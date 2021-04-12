#include "holberton.h"

/**
 *main - Displays a prompt and waits for the user to enter a command
 *@argc: arguement count
 *@argv: arguement vector
 *Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line;
	char **tokens;;
	int response, isPipe = 0;
	/*check whether only the commands are typed*/
	/*no other arguments*/
	if (argc >= 2)
	  {
	    if (execve(argv[1], argv, NULL) == -1)
	      {
		perror("Error");
		exit(98);
	      }
	    return (0);
	  }
	/*then print prompt '#cisfun$'*/
	do {
	  if (isatty(fileno(stdin)))
	    {
	      isPipe = 1;
	      _print("#cisfun$ ");
	    }

	  line = read_line();
	  tokens = _strtotokens(line);
	  response = _execute(tokens);
	} while (isPipe && response != -1);

	return (0);
}
