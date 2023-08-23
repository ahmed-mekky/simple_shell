#include "shell.h"

/**
 * main - main function of the shell.
 *
 * @argv: string of the command line args.
 * @argc: number of the commands.
 *
 * Return: 0 on success.
*/

int main(int __attribute__((unused)) argc, __attribute__((unused))char **argv)
{
	char *arg, *cpy;
	char **args;

	if (isatty(STDIN_FILENO))
	{
		loop();
	}
	else
	{
		arg = read_line();
		cpy = strdup(arg);
		if (!arg)
			exit(-1);
		cpy = strtok(arg, " \t\r\n\a");
		while (cpy != NULL)
		{
			args = split_line(cpy);
			execute(args);
			cpy = strtok(NULL, " \t\r\n\a");
		}
		free(cpy);
		free(arg);
		free(args);
		return (0);
	}
	return (0);
}
