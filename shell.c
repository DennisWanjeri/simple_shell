/**
 *main - Displays a prompt and waits for the user to enter a command
 *@argc:arguement count
 *@argv:arguement vector
 *Return:0
 */
int main(int argc, char **argv)
{
	char *buffer;
	int bufflen = 120;
	char *args[];
/*print '#cisfun$'*/

	printf("#cisfun$");
	buffer = malloc(sizeof(char) * bufflen);
	if (buffer == NULL)
	{
		perror("Error: malloc");
	}
	getline(buffer, bufflen, stdin);
	args[1] = strdup(buffer);
	args[2] = "NULL";
