#include "holberton.h"
/**
 *print_prompt - displays promot b4 user inputs
 *
 *Return:void
 */
void print_prompt(void )
{
	if (isatty(STDIN_FILENO))
	{
		_print("cisfun$");
	}
}