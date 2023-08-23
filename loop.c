#include "shell.h"

/**
 * loop - make the shell main loop.
 *
 * Return: void.
*/

void loop(void)
{
	char *line, **args;
	int status;

	do {
		printf("(: ");
		line = readline();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}
