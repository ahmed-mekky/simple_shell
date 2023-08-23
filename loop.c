#include "shell.h"

/**
 * loop - make the shell main loop.
 *
 * Return: void.
*/

int loop(void)
{
	int status = 1;
	char *arg, *cpy;
	char **args;

	while (status)
	{
		fflush(stdin);
		printf("(: ");
		arg = read_line();
		cpy = arg;
		if (!arg)
			exit(-1);
		cpy = strtok(arg, " \t\r\n\a");
		while (cpy != NULL)
		{
			args = split_line(cpy);
			status = execute(args);
			cpy = strtok(NULL, " \t\r\n\a");
		}
		free(cpy);
		free(arg);
		free(args);
	}
	return (0);
}
