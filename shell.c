#include "holberton.h"

/**
 *main - Displays a prompt and waits for the user to enter a command
 *@argc: arguement count
 *@argv: arguement vector
 *Return: 0 on success
 */
int main(void)
{
	char **tokens;
	char *line;
	int status;
	struct stat st;


	status = 1;
	do {
/*print prompt if command is not piped*/
		print_prompt();
/*read input from stdin*/
		line = read_line();
/*split the line into tokens*/
		tokens = _strtotokens(line);
/*handle exit invokation*/
		if (strcmp(token[0], "exit") == 0)
		{
			shell_exit(tokens, line);
		}
		else
		{
/*execute commands*/
			status = exec(tokens, line);
		}
/*free memory*/
		free(line);
		free_args(tokens);
	} while (status == 1);
	return (status);
}
