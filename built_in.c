#include "shell.h"


int exit_fun(char **args)
{
	return 0;
}

int cd_fun(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "): expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0) {
		perror(")");
		exit(EXIT_FAILURE);
	}
	}
	return 1;
}
