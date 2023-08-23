#include "shell.h"

/**
 * loop - make the shell main loop.
 *
 * Return: void.
*/

int loop(void)
{
	int status = 1;
	char *arg;
	char **args;

	while (status)
	{
		fflush(stdin);
		write(1, "(: ", 3);
		arg = read_line();
		if (!arg)
			return (-1);
		args = split_line(arg);
		status = execute(args);
		free(arg);
		free(args);
	}
	return (0);
}
