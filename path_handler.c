#include "holberton.h"

/**
 *get_path - gets the absolute path of a command
 *@args:pointer to an array of strings
 *Return:address of the path
 */
char *get_path(char **args)
{
	int i = 0;
	char *path = NULL, *token = NULL, *slash_token = NULL, *cmd_token = NULL;
	struct stat st;

	if (args == NULL)
		return (NULL);
/*when user inputs full path e.g /bin/ls*/
	if(stat(argv[0], &st) == 0)
		return (argv[0]);
	path = get_env("PATH");
	token = strtok(path, ":");
	i = 0;
	while (token)
	{
		slash_token = _strcat(token, "/");
		cmd_token = _strcat(slash_token, args[0]);
		free(slash_token);
		if (stat(cmd_token, &st) == 0)
		{
			_strcpy(args[0], cmd_token);
			free(cmd_token);
			free(path);
			return(args[0]);
		}
		free(cmd_token);
		token = (NULL, ":");
		i++;
	}
	path = NULL;
	return (NULL);
}
/**
 *get_env - retrieves an environment variable
 *@args:variable passed
 *Return:pointer to a string
 */
char *get_env(char *args)
{
	char *envcpy = NULL;
	int i = 0;
	int len, len2;

	while (environ[i])
	{
		len = _strlen(path);
/*locate substring PATH*/
		if (_strstr(environ[i], path))
		{
			if(environ[i][len] == '=')
			{
				len2 = _strlen(environ[i]) - _strlen(path);
				envcpy = malloc(sizeof(char) * len2);
				if(envcpy = NULL)
				{
					perror("Error: Insufficient memory");
					exit(1);
				}
				_strcpy(envcpy, environ[i] + (len + 1));
				return(envcpy);
			}
		}
		i++;
	}
	return (NULL);
}
