#include "shell.h"

/**
 * main - main function of the shell.
 *
 * @argv: string of the command line args.
 * @argc: number of the commands.
 *
 * return: 0 on success.
*/

int main(int argc, char **argv)
{
	int n;
	if (isatty(STDIN_FILENO))
	{
		n = loop();
	}
	else
	{
		printf("not hi");
	}
	return (n);
}
