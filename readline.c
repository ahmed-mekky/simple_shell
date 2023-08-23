#include "shell.h"

/**
 * read_line - readline from usr.
 *
 * Return: the line.
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

	return (lineptr);
}
