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
	char *line, *cmd;
	int status;
	struct stat st;

	if (fstat(0, &st) == -1)
		perror("fstat");
	status = 1;
	do {
/*print prompt if command is not piped*/
		if (!S_ISFIFO(st.st_mode))
		{
			print_prompt();
		}
/*read input from stdin*/
		line = read_line();
/*split the line into tokens*/
		tokens = _strtotokens(line);
/*handle exit invokation*/
		if (strcmp(tokens[0], "exit") == 0)
		{
			shell_exit(tokens, line);
		}
		else
		{
/*execute commands*/
			cmd = get_path(tokens);
			status = _execute(cmd, line);
		}
/*free memory*/
		free(line);
		free(tokens);
		free(cmd);
	} while (status == 1);
	return (status);
}
