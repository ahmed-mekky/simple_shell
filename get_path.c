#include "shell.h"

/**
 * get_location - get path location.
 *
 * @command: ....
 *
 * Return: the path with the command
*/

char **get_path(void)
{
	char *path, *token, **directories;
	int bufsize = BUFSIZE, i = 0;

	path = getenv("PATH");
	directories = malloc(bufsize * sizeof(char *));
	if (!directories)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		directories[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			directories = realloc(directories, bufsize * sizeof(char *));
			if (!directories)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, ":");
	}

	directories[i] = NULL;
	return (directories);
}
