#include "shell.h"

/**
 * get_builtin - builtin that pass the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", myexit },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", change_dir_shell },
		{ "help", _helper },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
