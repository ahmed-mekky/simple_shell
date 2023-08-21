#include "shell.h"

/**
 * loop - make the shell main loop.
 *
 * return: void.
*/

int loop(void)
{
	int status = 1;
	char *str;
	char **str_arr;

	while (status)
	{
		printf(":) ");
		str = read_line();
		if (!str)
			return (-1);
		str_arr = split_line(str);
		status = execute(str_arr);
		free(str);
		free(str_arr);
	}
	return (0);
}
