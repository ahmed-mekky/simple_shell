#include "shell.h"

/**
 * loop - make the shell main loop.
 *
 * return: int.
*/


char *read_line(void)
{
	char *lineptr = malloc(1024 * sizeof(char));

	if (!lineptr)
	{
		perror(")");
		return (NULL);
	}

	if (!fgets(lineptr, sizeof(lineptr), stdin))
	{
		perror(")");
		return (NULL);
	}

	return lineptr;
}
