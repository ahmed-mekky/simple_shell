#include "shell.h"

/**
 * get_location - get path location.
 *
 * @command: ....
 *
 * Return: the path with the command
*/

char *get_location(char *command)
{
	char *path, *token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path = strdup(path);
		command_length = strlen(command);
		token = strtok(path, ":");

		while (token != NULL)
		{
			directory_length = strlen(token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, ":");
			}
		}
		free(path);

		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
