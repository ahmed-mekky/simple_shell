#include "shell.h"

/**
 * read_line - readline from usr.
 *
 * Return: the line.
*/


char *read_line(void)
{
	char *line;
	int len = 0, Buffer = BUFSIZE;
	char c;

	line = malloc(Buffer);
	if (!line)
	{
		perror("problem in allocation");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == '\n' || c == EOF)
		{
			line[len] = '\0';
			return (line);
		}
		else
		{
			line[len++] = c;
		}
		if (len >= Buffer)
		{
			Buffer += BUFSIZE;
			line = realloc(line, Buffer);
			if (!line)
			{
				perror("problem in ");
				exit(EXIT_FAILURE);
			}
		}
	}
}
