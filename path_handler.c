#include "holberton.h"

/**
 *get_path - gets the absolute path of a command
 *@args:pointer to an array of strings
 *Return:address of the path
 */
char *get_path(char **args)
{
	char *path = NULL, *token = NULL, *slash_token = NULL, *cmd_token = NULL;
	struct stat st;

	if (args == NULL)
		return (NULL);
/*when user inputs full path e.g /bin/ls*/
	if(stat(args[0], &st) == 0)
		return (args[0]);
	path = get_env("PATH");
	token = strtok(path, ":");

	while (token)
	{
		slash_token = strcat(token, "/");
		cmd_token = strcat(slash_token, args[0]);
		free(slash_token);
		if (stat(cmd_token, &st) == 0)
		{
			args[0] = strdup(cmd_token);
			free(cmd_token);
			free(path);
			return(args[0]);
		}
		free(cmd_token);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
/**
 *get_env - retrieves an environment variable
 *@args:variable passed
 *Return:pointer to a string
 */
char *get_env(char *path)
{
	char *envcpy = NULL;
	int i = 0;
	int len, len2;

	while (environ[i])
	{
		len = _strlen(path);
/*locate substring PATH*/
		if (strstr(environ[i], path))
		{
			if(environ[i][len] == '=')
			{
				len2 = _strlen(environ[i]) - _strlen(path);
				envcpy = malloc(sizeof(char) * len2);
				if(envcpy == NULL)
				{
					perror("Error: Insufficient memory");
					exit(1);
				}
				strcpy(envcpy, environ[i] + (len + 1));
				return(envcpy);
			}
		}
		i++;
	}
	return (NULL);
}
