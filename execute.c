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
	char *builtin_str[] = {
		"cd",
		"exit",
		"env",
		"setenv",
		"unsetenv"
	};
	int (*builtin_func[]) (char **) = {
		&cd_fun,
		&exit_fun,
		&env_fun,
		&setenv_fun,
		&unsetenv_fun
	};
	if (args[0] == NULL)
		return (1);
	for (i = 0; i < 5; i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (launch(args));
}

/**
 * launch - Launch a process and execute a command
 * @args: The arguments of the command
 *
 * Return: Always returns 1
 */
int launch(char **args)
{
	char *envp[] = {NULL}, **directories, *path;
	pid_t pid = fork();
	int status, i = 0;

	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			directories = get_path();
			while (directories[i] != NULL)
			{
				path = malloc(strlen(directories[i]) + strlen(args[0]) + 2);
				if (!path)
				{
					fprintf(stderr, "Allocation error\n");
					exit(EXIT_FAILURE);
				}
				sprintf(path, "%s/%s", directories[i++], args[0]);
				if (execve(path, args, environ) == 0)
				{
					free(path);
					exit(EXIT_SUCCESS);
				}
			}
			free(directories);
			exit(127);
		}
	}
	else if (pid < 0)
		perror(")");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (127);
		}
	}
	return (1);
}
/**
 * excution - execute the command
 * @directories: The directories of the command
 * @args: The arguments of the command
 */
void excution(char *directories, char **args)
{
	char *path;

	path = malloc(strlen(directories) + strlen(args[0]) + 2);
	if (!path)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	sprintf(path, "%s/%s", directories, args[0]);
	if (execve(path, args, environ) == 0)
	{
		free(path);
		exit(EXIT_SUCCESS);
	}
}
