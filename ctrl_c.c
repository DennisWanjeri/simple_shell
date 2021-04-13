#include "holberton.h"
/**
 *ctrl_c - suppresses quitting when Ctrl c is invoked
 *@signum:SIGINT variable
 *Return:void
 */
void ctrl_c(int signum)
{
	void(signum);
	signal(SIGINT, sigint_handler);
	write(STDIN_FILENO, "/n^C ", 3);
}
