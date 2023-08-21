#include "shell.h"

/**
 * splist_line - split line into words
 *
 * @line: string contains the line to split.
 *
 * return: pointer to array of the words.
*/

char **split_line(char *line)
{
	int bufsize = BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "): allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				fprintf(stderr, "): allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return tokens;
}
