#include "holberton.h"
/**
 *shell_environ - prints environment variables when env is invoked
 *
 *Return:1 on success
 */
int shell_environ(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
