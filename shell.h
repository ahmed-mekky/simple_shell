#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 64
#define DELIM " \t\r\n\a"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void loop(void);
char *readline(void);
char **split_line(char *line);
char **get_path();
int launch(char **args);
void excution(char *directories, char **args);
int cd_fun(char **args);
int exit_fun(char **args);
int env_fun(char **args);
int setenv_fun(char **args);
int unsetenv_fun(char **args);
int execute(char **args);

#endif
