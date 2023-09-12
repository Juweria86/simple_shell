#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

void JNprint_fn(const char *Msg);
void prompt(void);
char *u_input();
void exec_cmd(char *command);
char **parse_input(char *input);
char *_strdup(char *str);
int  _strlen(char *s);
char *format(char *N, char *sep, char *val);


/**
 * struct path - Linked list to path
 * @dir: directory in path
 * @ptr: pointer to next node
 */

typedef struct path
{
	char *dir;
	struct path *ptr;
} path;

#endif
