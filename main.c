#include "shell.h"

/**
 * main - main function of the shell.
 *
 * @argv: string of the command line args.
 * @argc: number of the commands.
 *
 * return: 0 on success.
*/

int main(void)
{
	int n;
	char *arg;
	char **args;

	if (isatty(STDIN_FILENO))
	{
		n = loop();
	}
	else
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "(: ", 3);
			fflush(stdout);
		}
		arg = read_line();
		if (!arg)
			return (-1);
		args = split_line(arg);
		execute(args);
		free(arg);
		free(args);
	}
	return (n);
}
