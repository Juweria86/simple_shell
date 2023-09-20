#include "shell.h"

/**
 * _error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int _error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = environment_error(datash);
		break;
	case 126:
		error = path_error(datash);
		break;
	case 127:
		error = cmd_notfound(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = exit_error(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = cmd_notfound(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
