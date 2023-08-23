#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 64
#define DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

int loop(void);
char *read_line(void);
char **split_line(char *line);

int cd_fun(char **args);
int exit_fun(char **args);
int execute(char **args);
char *get_location(char *command);


#endif
