#include "holberton.h"
/**
 *_setenv - updates or adds an environment variable
 *@var_name:variable name
 *@var_value:variable value
 *Return:0 - success,otherwise -1
 */
int _setenv(char *var_name, char *var_value)
{
	int i = 0;
	size_t name_len;
	char *var_new;

	name_len = _strlen(var_name);
	i = 0;
/*updating an existing variable*/
	while (environ[i])
	{
		if (strncmp(environ[i], var_name, name_len) == 0)
		{
			var_new = var_build(var_name, var_value);
/*Not sure but wanted to clear its mem b4 writing*/
			free(environ[i]);
			environ[i] = strdup(var_new);
			free(var_new);
			return (0);
		}
		i++;
	}
/*adding a variable that never existed before*/
	var_new = var_build(var_name, var_value);
	free(environ[i]);
	environ[i] = strdup(var_new);
	i++;
	environ[i] = NULL;
	free(var_new);

	return (0);
}
/**
 *var_build - builds an environment variable from its name and value
 *@var_name:variable name
 *@var_value:variable value
 *Return:string containing full environment variable
 */
char *var_build(char *var_name, char *var_value)
{
	char *new_var;
	size_t var_len;

	var_len = _strlen(var_name) + _strlen(var_value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (new_var == NULL)
	{
		perror("Error: Insufficient memory\n");
		return (NULL);
	}
	memset(new_var, 0, var_len);

/*Data in the form: var_name=var_value*/
	new_var = strcat(new_var, var_name);
	new_var = strcat(new_var, "=");
	new_var = strcat(new_var, var_value);

	return (new_var);
}
