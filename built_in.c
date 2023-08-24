#include "shell.h"

/**
 * exit_fun - exit shell with number.
 *
 * @args: number to exit with
 *
 * Return: int number.
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
/**
 * env_fun - Print the current environment
 *
 * @args: The arguments passed to the env command (ignored)
 *
 * Return: Always returns 1 to continue the shell loop
 */
int env_fun(char **args)
{
	int i = 0;

	(void)args;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (1);
}

/**
 * setenv_fun - Set a new environment variable or modify an existing one.
 *
 * * @args: The arguments passed to the setenv command.
 *
 * Return: Always returns 1
 */
int setenv_fun(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return (1);
	}

	return (1);
}

/**
 * unsetenv_fun - Unset an environment variable.
 *
 * @args: The arguments passed to the unsetenv command.
 *
 * Return: Always returns 1
 */
int unsetenv_fun(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (1);
	}

	return (1);
}
