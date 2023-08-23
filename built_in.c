#include "shell.h"

/**
 * exit_fun - exit shell with number.
 *
 * @args: number to exit with
 *
 * Return: int.
*/

int exit_fun(char **args)
{
	if (args[1])
		exit(atoi(args[1]));
	else
		return (0);
}

/**
 * cd_fun -change current dir.
 *
 * @args: name of the new dir
 *
 * Return: int.
*/

int cd_fun(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "): expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror(")");
		}
	}
	return (1);
}
