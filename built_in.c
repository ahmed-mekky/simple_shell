#include "shell.h"


int exit_fun(char **args)
{
	if(!args[1])
		return (0);
	else
		exit(atoi(args[1]));
}

int cd_fun(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "): expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror(")");
		}
	}
	return 1;
}
