#include "shell.h"
int execute(char **args)
{
	int i;
	pid_t pid;
	int status;
	char *builtin_str[2] = {"cd","exit"};
	int (*builtin_func[]) (char **) = {
	&cd_fun,
	&exit_fun
	};

	if (args[0] == NULL)
	{
	return 1;
	}

	for (i = 0; i < 2; i++)
	{
	if (strcmp(args[0], builtin_str[i]) == 0)
	{
		return (*builtin_func[i])(args);
	}
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(get_location(args[0]), args, NULL) == -1)
		{
			perror(")...");
		}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	perror(")");
	}
	else
	{
	do
	{
		waitpid(pid, &status, WUNTRACED);
	}
	while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}
