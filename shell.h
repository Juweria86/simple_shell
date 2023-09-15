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

/**
 * struct list_s - Linked list to path
 * @dir: directory in path
 * @ptr: pointer to next node
 */

typedef struct list_s
{
	char *dir;
	struct list_s *ptr;
} list_t;

void JNprint_fn(const char *Msg);
void prompt(void);
char *u_input();
void exec_cmd(char *args[]);
char **parse_input(char *input);
void handle_command_with_arguments(char *input);
char *_strdup(char *str);
int  _strlen(char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
void exit_t(char **av);
int _atoi(char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
void free_lt(list_t *head);

list_t *node_end(list_t **head, char *dir);
char *find_path(char *cmd);
char *copy_path(char *path);
list_t *find_dir(char *path);
#endif
