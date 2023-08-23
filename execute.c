#include "shell.h"

/**
 * execute - execute the orders.
 *
 * @args: ....
 *
 * Return: int.
*/

int execute(char **args)
{
	int i;
	pid_t pid;
	int status;
	char *builtin_str[] = {"cd", "exit", "env", "setenv", "unsetenv"};

	int (*builtin_func[]) (char **) = {
	&cd_fun,
	&exit_fun,
	&env_fun,
	&setenv_fun,
	&unsetenv_fun
	};
	if (args[0][0] == '.' && args[0][1] == '/')
	{
		fprintf(stderr, "): 1: %s: not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	if (args[0] == NULL)
	return (1);
	for (i = 0; i < 2; i++)
	{
	if (strcmp(args[0], builtin_str[i]) == 0)
		return ((*builtin_func[i])(args));
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(get_location(args[0]), args, NULL) == -1)
			perror(")");
	}
	else if (pid < 0)
	perror(")");
	else
	{
	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
