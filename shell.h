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
void exec_cmd(char *args[]);
char **parse_input(char *input);
void handle_command_with_arguments(char *input);
char *_strdup(char *str);
int  _strlen(char *s);
char *format(char *N, char *sep, char *val);
int _strcmp(char *s1, char *s2);
void exit_t(char **av);
int _atoi(char *s);

/**
 * path_t *node_end(path_t **head, char *string);
 * path_t *linkpath(char *path);
 * *char *_choose(char *fname, path_t *head);
 *  void free_path(path_t *head);
 */

/**
 * struct path_t - Linked list to path
 * @dir: directory in path
 * @ptr: pointer to next node
 */

/**
 * typedef struct path_t
 * {
 * char *dir;
 * struct path_t *ptr;
 * } path_t;
*/

#endif
