#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* jlists.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* jlists2.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* str.c */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* mem_func.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* str3.c */
void rev_string(char *s);

/* find_syntax.c */
int char_repetition(char *input, int i);
int find_syntax(char *input, int i, char last);
int char_index(char *input, int *i);
void print_error(data_shell *datash, char *input, int i, int bool);
int check_syntax(data_shell *datash, char *input);

/* shell_loop.c */
char *del_comment(char *in);
void my_shell(data_shell *datash);

/* read_input.c */
char *read_input(int *i_eof);

/* parse.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void next_cmd(sep_list **list_s, line_list **list_l, data_shell *datash);
int parse_cmd(data_shell *datash, char *input);
char **parse_input(char *input);

/* rep_var.c */
void is_env(r_var **h, char *in, data_shell *data);
int is_var(r_var **h, char *in, char *st, data_shell *data);
char *rep_input(r_var **head, char *input, char *new_input, int nlen);
char *var_replace(char *input, data_shell *datash);

/* get_input.c */
void var_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_input(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int find_built(data_shell *datash);

/* cmd_exec.c */
int check_cdir(char *path, int *i);
char *loc_cmd(char *cmd, char **_environ);
int executable(data_shell *datash);
int check_error(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* environment1.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* environment2.c */
char *copy_data(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* change_dir.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* cd_shell.c */
int change_dir_shell(data_shell *datash);

/* get_builtin */
int (*_builtin(char *cmd))(data_shell *datash);

/* _exit.c */
int myexit(data_shell *datash);

/* ju_stdlib.c */
int num_len(int n);
char *_itoa(int n);
int _atoi(char *s);

/* jerror1.c */
char *concat_cd(data_shell *, char *, char *, char *);
char *cd_error(data_shell *datash);
char *cmd_notfound(data_shell *datash);
char *exit_error(data_shell *datash);

/* jerror2.c */
char *error_get_alias(char **args);
char *environment_error(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *path_error(data_shell *datash);


/* get_error.c */
int _error(data_shell *datash, int eval);

/* _sigint.c */
void _sigint(int sig);

/* j_help.c */
void jhelp_env(void);
void jhelp_setenv(void);
void jhelp_unsetenv(void);
void jhelp_general(void);
void jhelp_exit(void);

/* _help2.c */
void jhelp(void);
void jhelp_alias(void);
void jhelp_cd(void);

/* _help.c */
int _helper(data_shell *datash);

#endif
