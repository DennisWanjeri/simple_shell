#include "holberton.h"
/**
 *sigint_handler - suppresses quitting when Ctrl c is invoked
 *@signum:SIGINT variable
 *Return:void
 */
void sigint_handler(int signum)
{
	void(signum);
	signal(SIGINT, sigint_handler);
	write(STDIN_FILENO, "/n^C ", 3);
}
