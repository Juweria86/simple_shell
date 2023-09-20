#include "shell.h"

/**
 * _env - prints the current environment
 * @args: an array of arguments
 * @p: pointer to arg
 * Return: -1 or 0
 */

int _env(char **args, char __attribute__((__unused__)) **p)
{
	int i;
	char c = '\n';

	if (!environ)
		return (-1);

	for (i = 0; environ[i]; i++)
	{
		void JNprint_fn(const char *environ);
		write(STDOUT_FILENO, &c, 1);
	}

	(void)args;
	return (0);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @args: an array of arguments
 * @p: pointer to arg
 * Return: -1 or 0
 */
int _setenv(char **args, char __attribute__((__unused__)) **p)
{
	char **var = NULL;
	char **new, *val;
	int i;
	size_t j;

	if (!args[0] || !args[1])
	{
		perror("Incorrect number of arguements\n");
		return (1);
	}

	val = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);

	if (!val)
	{
		perror("Error\n");
		return (1);
	}
	_strcpy(val, args[0]);
	_strcat(val, "=");
	_strcat(val, args[1]);

	var = _getenv(args[0]);
	if (var)
	{
		free(*var);
		*var = val;
		return (0);
	}
	for (j = 0; environ[j]; j++)
		;
	new = malloc(sizeof(char *) * (j + 2));

	if (!new)
	{
		free(val);
		perror("Unable to add/remove from environment\n");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		new[i] = environ[i];

	free(environ);
	environ = new;
	environ[i] = val;
	environ[i + 1] = NULL;

	return (0);
}
/**
 * _unsetenv - Remove an environment variable
 * @args: an array of arguments
 * @p: pointer to arg
 * Return: -1 or 0
 */
int _unsetenv(char **args, char __attribute__((__unused__)) **p)
{
	int i, j;
	size_t size;
	char **env, **new;

	if (!args[0])
	{
		perror("Incorrect number of arguements\n");
		return (1);
	}
	env = _getenv(args[0]);

	if (!env)
		return (0);

	for (size = 0; environ[size]; size++)
		;
	new = malloc(sizeof(char *) * size);
	if (!new)
	{
		perror("Unable to add/remove from environment\n");
		return (1);
	}

	for (i = 0, j = 0; environ[i]; i++)
	{
		if (*env == environ[i])
		{
			free(*env);
			continue;
		}
		new[j] = environ[i];
		j++;
	}
	free(environ);
	environ = new;
	environ[size - 1] = NULL;

	return (0);
}
