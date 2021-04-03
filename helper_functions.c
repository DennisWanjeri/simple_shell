#include "holberton.h"
/**
 *check_file_status - checks whether a file exists
 *@filename:name of file
 *Return:0 - file is available, -1 otherwise
 */
int check_file_status(char *filename)
{
	struct stat st;

	if (stat(filename, &st) == -1)
		return (-1);
	return (0);
}
/**
 *execute_file - executes a file given as input
 *@argv:an array of pointers to strings
 *Return:-1 (success), -1,otherwise
 */
int execute_file(char **argv)
{
	if (execve(argv[0], argv, NULL) == -1)
		return (-1);
	return (0);
}
