#include "holberton.h"
/**
 *_unsetenv - removes an environment variable
 *@var_name:variable name
 *Return:0 if successful -1,otherwise
 */
int _unsetenv(char *var_name)
{
	int i = 0;
	char **env_temp;
	size_t name_len;

	name_len = _strlen(var_name);
	while (environ[i])
	{
		if (strncmp(environ[i], var_name, name_len) == 0)
		{
			env_temp = environ;
			free(env_temp[0]);
			do {
				env_temp[0] = env_temp[1];
				env_temp++;
			} while (*env_temp);
		}
		i++;
	}
	return (0);
}
