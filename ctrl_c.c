#include "holberton.h"
/**
 *ctrl_c - suppresses quitting when Ctrl c is invoked
 *@signum:SIGINT variable
 *Return:void
 */
void ctrl_c(int signum)
{
	void(signum);
	signal(SIGINT, ctrl_c);
	write(STDIN_FILENO, "\n#cisfun$ ", 3);
}
