#include "shell.h"

/**
 * free_lt - free list
 * @head: head of list
 */
void free_lt(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->ptr;
		free(head->dir);
		free(head);
		head = tmp;
	}
}

/**
 * _getenv - gets an environmental variale
 * @var: name of variale
 * Return: pointer to env var or NULL
 */
char **_getenv(char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}
	return (NULL);
}

/**
 * _builtin - match a command
 * @cmd: the command
 * Return: a function pointer
 */
int (*_builtin(char *cmd))(char **args, char **p)
{
	builtin_t func[] = {
		{ "exit", exit_arg },
		{ "setenv", _setenv },
		{ "env", _env },
		{ "unsetenv", _unsetenv },
		{ NULL, NULL}
	};
	int i;

	for (i = 0; func[i].name; i++)
	{
		if (_strcmp(func[i].name, cmd) == 0)
			break;
	}

	return (func[i].j);
}
