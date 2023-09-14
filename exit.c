#include "shell.h"

/**
 * exit_t - exits from the shell
 * @av: an array
 */
void exit_t(char **av)
{
	int j;

	if (av[1])
	{
		j = _atoi(av[1]);
		if (j <= -1)
			j = 2;
		free(av);
		exit(j);
	}
	exit(0);
}
