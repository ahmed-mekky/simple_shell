#include "shell.h"

/**
 * main - main function of the shell.
 *
 * @argv: string of the command line args.
 * @argc: number of the commands.
 *
 * Return: 0 on success.
*/

int main(int argc,char **argv)
{
	FILE *input_file;
	char *line = NULL, **args;
	size_t bufsize = 0;
	int status = 0;

	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
		loop();
	else
	{
		input_file = stdin;
		while (getline(&line, &bufsize, input_file) != -1)
		{
			line[strcspn(line, "\n")] = '\0';
			args = split_line(line);
			status = execute(args);

			free(args);
			if (status == 0)
				break;
		}


		free(line);
	}
	if (status == 127)
		return (127);
	else
		return (EXIT_SUCCESS);
}
